#include <stdio.h>
#include "driver/ledc.h"
#include "driver/adc.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"

// === Pin Definitions ===
#define ESC_GPIO        18              // GPIO for ESC signal
#define JOY_ADC_CH      ADC1_CHANNEL_6  // Example: GPIO34

// === ESC Parameters ===
#define ESC_PWM_FREQ        50          // Standard ESC frequency
#define ESC_RESOLUTION      LEDC_TIMER_16_BIT

// Pulse width timings (in microseconds)
#define ESC_MIN_PULSE_US    1000        // ESC minimum pulse (1ms) - motor off
#define ESC_START_PULSE_US  1060        // Minimum running speed
#define ESC_KICK_PULSE_US   1200        // Kickstart pulse for reliable spin-up

// Joystick threshold
#define JOYSTICK_THRESHOLD  4095        // Max ADC value is 4095

// === Helper function to convert pulse width to duty ===
static uint32_t pulse_to_duty(uint32_t pulse_us, uint32_t max_duty) {
    return (max_duty * pulse_us) / 20000;  // 20ms period at 50Hz
}

void app_main(void)
{
    printf("Starting ESC + Joystick Control...\n");

    // === Configure LEDC Timer ===
    ledc_timer_config_t ledc_timer = {
        .speed_mode       = LEDC_LOW_SPEED_MODE,
        .timer_num        = LEDC_TIMER_0,
        .duty_resolution  = ESC_RESOLUTION,
        .freq_hz          = ESC_PWM_FREQ,
        .clk_cfg          = LEDC_AUTO_CLK
    };
    ledc_timer_config(&ledc_timer);

    // === Configure LEDC Channel ===
    ledc_channel_config_t ledc_channel = {
        .speed_mode     = LEDC_LOW_SPEED_MODE,
        .channel  
             = LEDC_CHANNEL_0,
        .timer_sel      = LEDC_TIMER_0,
        .intr_type      = LEDC_INTR_DISABLE,
        .gpio_num       = ESC_GPIO,
        .duty           = 0, // Start with motor off
        .hpoint         = 0
    };
    ledc_channel_config(&ledc_channel);

    uint32_t max_duty = (1 << ESC_RESOLUTION) - 1;

    // === Configure ADC ===
    adc1_config_width(ADC_WIDTH_BIT_12); // 0-4095 range
    adc1_config_channel_atten(JOY_ADC_CH, ADC_ATTEN_DB_12);

    // === ESC Arming Sequence ===
    printf("Arming ESC...\n");
    uint32_t off_duty = pulse_to_duty(ESC_MIN_PULSE_US, max_duty);
    ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, off_duty);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);
    vTaskDelay(pdMS_TO_TICKS(2000));  // 2 seconds for arming

    printf("ESC armed. Ready to control motor.\n");

    bool has_kicked = false; // Track whether we have given a kickstart

    while (true) {
        // Read joystick value
        int joy_value = adc1_get_raw(JOY_ADC_CH);
        printf("Joystick: %d\n", joy_value);

        if (joy_value >= JOYSTICK_THRESHOLD) {
            // Joystick at max -> Run motor
            if (!has_kicked) {
                
                uint32_t kick_duty = pulse_to_duty(ESC_KICK_PULSE_US, max_duty);
                ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, kick_duty);
                ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);
                vTaskDelay(pdMS_TO_TICKS(110)); // short kick duration
                has_kicked = true;
            }

            uint32_t min_run_duty = pulse_to_duty(ESC_START_PULSE_US, max_duty);
            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, min_run_duty);
            ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);
        } else {
            
            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, off_duty);
            ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);
            has_kicked = false; // Reset kick flag
        }

        vTaskDelay(pdMS_TO_TICKS(50)); // Loop delay
    }
}
