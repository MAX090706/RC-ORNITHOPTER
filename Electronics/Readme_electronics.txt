🛩️ Ornithopter – Electronics

This folder contains the electronics design, code, and documentation for the Ornithopter project.
The first challenge in this field was to select the motor for the mech , we went with a 1400kv BLDC motor there were some selection criteria,
> weight
> torque
> rpm
after the criteria wee selected we went with A2212/10 t motor.
Then we required a battery , we went with 1000 MAH 11.1v Li-Po battery cause it was perfect with the weight constraints we had.
Now for running a bldc motor you need and ESC and a microcontroller , we went with ESP32. 
then i wrote a simple code for runningmy motor .
after that my task was to control the motor with joystick , i have given the code for the same in the electronics part 
Then i thaought of wireless connection and making an actual remote like structure, for which i useed nRF24L01 radio transmitter and Receiver
but i faced a problem in that the thing was every code i used till now were in esp=idf but the header files {sih} does no exist in esp-idf , I tried to download the 
files but i was not able to do that in esp-idf so I had to shift to Arduino-idf as it contained the header files for this 
then i wrote the code for this with help of chat-gpt and was able to control the motor wirelessly 
