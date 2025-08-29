#include <SPI.h>
#include <RF24.h>

// ===== Pin Definitions =====
#define CE_PIN    22    // CE for nRF24L01+
#define CSN_PIN   4     // CSN for nRF24L01+
#define JOY_X_PIN 32    // Joystick X-axis (VRx pin)
#define JOY_Y_PIN 34    // Joystick Y-axis (VRy pin)

RF24 radio(CE_PIN, CSN_PIN);
const byte address[6] = "00001";

void setup() {
  Serial.begin(115200);
  
  // Initialize radio
  if (!radio.begin()) {
    Serial.println("NRF24L01 not responding! Check wiring.");
    while (1) { delay(1000); }
  }
  
  radio.setPALevel(RF24_PA_LOW);
  radio.openWritingPipe(address);
  radio.stopListening();
  
  Serial.println("Transmitter ready!");
}

void loop() {
  // Read joystick values
  int joyX = analogRead(JOY_X_PIN); // 0-4095 on ESP32
  int joyY = analogRead(JOY_Y_PIN); // 0-4095 on ESP32
  
  // Pack data into array
  int joyData[2] = { joyX, joyY };
  
  // Send data
  bool result = radio.write(&joyData, sizeof(joyData));
  
  // Debug output
  Serial.print("Sent X: "); Serial.print(joyX);
  Serial.print(" Y: "); Serial.print(joyY);
 // Serial.print(" Status: "); Serial.println(result ? "OK" : "FAIL");
  
  delay(50); // Send data every 50ms
}
