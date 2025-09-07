#include <SPI.h>
#include <RF24.h>

// Pin definitions
#define CE_PIN    22   // nRF24L01+ CE
#define CSN_PIN   4    // nRF24L01+ CSN
#define ESC_PIN   21   // ESC signal wire (servo PWM)

// Create radio object
RF24 radio(CE_PIN, CSN_PIN);
const byte address[6] = "00001";

// PWM settings
const int channel   = 0;    // LEDC channel 0
const int freq      = 50;   // 50Hz
const int resolution= 16;   // 16-bit (0–65535)

void setup() {
  Serial.begin(115200);

  // Radio init
  if (!radio.begin()) {
    Serial.println("nRF24L01+ not found");
    while (1) { delay(1000); }
  }
  radio.setPALevel(RF24_PA_LOW);
  radio.openReadingPipe(0, address);
  radio.startListening();

  // PWM init for ESC
  ledcSetup(channel, freq, resolution);
  ledcAttachPin(ESC_PIN, channel);

  // Arm ESC: send 1ms pulse for 2s
  uint32_t maxDuty = (1UL << resolution) - 1; // 65535
  uint32_t minDuty = (maxDuty * 1) / 20;      // 1ms of 20ms
  ledcWrite(channel, minDuty);
  delay(2000);

  Serial.println("Receiver ready; ESC armed");
}

void loop() {
  if (radio.available()) {
    int data[2] = {0, 0};
    radio.read(&data, sizeof(data));

    int joyX = *data;  // X-axis throttle
    Serial.print("Received X: ");
    Serial.println(joyX);

    // Map 0–4095 to 1–2ms pulse width
    uint32_t maxDuty = (1UL << resolution) - 1;
    uint32_t minDuty = (maxDuty * 1) / 20;
    uint32_t maxDuty2= (maxDuty * 2) / 20;

    uint32_t duty = map(joyX, 0, 4095, minDuty, maxDuty2);
    ledcWrite(channel, duty);
  }

  delay(20);
}
