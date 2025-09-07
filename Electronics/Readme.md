# Ornithopter - Electronics

This folder contains the electronics design, code, and documentation for the Ornithopter project. The goal of this part of the project was to develop a reliable and lightweight control system for the ornithopter's flapping mechanism.

### **1. Components**
The following electronic components were selected based on a balance of weight, torque, and power requirements.

* **Motor**: A **1400kv A2212/10t BLDC motor** was chosen for its optimal weight-to-torque ratio.
* **Battery**: A **1000mAh 11.1V Li-Po battery** provides sufficient power while sticking to the project's weight constraints.
* **Motor Controller**: An **ESC (Electronic Speed Controller)** that is used to drive the BLDC motor.
* **Microcontroller**: We used **ESP32** because of its availability and ease of use .
* **Radio Module**: We only had **nRF24L01 radio transmitter/receiver module** , so we used it for our wireless communication 

### **2. Development Process**

This section shows the steps and problems i faced when building the control system for the ornithopter 

1.  **Motor Control**: A simple program was written for the ESP32 to run the BLDC motor.
2.  **Joystick Integration**: Then I updated the code such that an JOY Stick was able to control the speed of the motor
3.  **Wireless Control**: To enable wireless operation, the nRF24L01 module was integrated to create a remote-like structure.

### **3. Notable Challenges & Solutions**

* **ESP-IDF vs. Arduino-IDE**: Once I started with the wireless part of the control system , I encounterd a big challenge , the thing is that the header fiels used in the module **nRF24L01** nRF24.h does not exist in esp-idf , I tried to find thoes files but i was not able to find it thats why i was suggested to use arduino-ide , there were still some prolems with that , like the latest version of the esp32 on arduino that is v3.1 does not support spi.h files so i had to move to the older version of it precisely v2.0 then i had to down load the nRF24 fiels from library . After doing all this I was finally able to control the motor wirelessly 

### **4. Files and Folders**

* `code/`: Contains the microcontroller code for both wired and wireless control.
* `schematics/`: Includes component layouts.
* `datasheets/`: Houses technical specifications for all electronic components. 
