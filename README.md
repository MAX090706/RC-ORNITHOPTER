#  RC Ornithopter Project
---
##  Project Structure
- **Gearbox** → Design of multi-stage reduction gearbox.
- **Wing Mechanism** → 4-bar flapping mechanism.
- **Wing Design** → Aerodynamic design of the wings.
- **Electronics** → Control system and power electronics.

#  RC Ornithopter  

An RC Ornithopter is a bio-inspired aircraft that flies by flapping its wings, much like birds, bats, and insects. Unlike traditional fixed-wing or rotary aircraft that rely on propellers, the ornithopter uses wing motion to generate both lift and thrust.   

This project focuses on the design and development of a remote-controlled ornithopter with a **1.3 m wingspan**. The mechanical system includes a 2-stage spur gear reduction gearbox to convert high motor RPM into strong wing-flapping , paired with a **4-bar wing mechanism** that ensures smooth and symmetric wing motion flapping at **5 Hz frequency**.  

To maximize aerodynamic performance, we have used the **S1223 aerofoil** for the wings, chosen for its optimal aspect ratio, lift-to-drag ratio, and lightweight structural efficiency that balance **lift, stability, and strength**.  

The ornithopter is powered by a **1400 KV BLDC motor**, controlled with a **30A ESC**, and powered by a **1000mAh 30C Li-Po battery**. Overall, this project combines **aerodynamics, mechanical design, and electronics** to create a working prototype that demonstrates the **feasibility of flapping-wing flight**.  

<p align="center">
  <img src="assets/assembly.jpg" alt="assembly front view" width="30%">
  <img src="assets/side_assembly.jpg" alt="side view" width="30%">
</p>  
---

## Gearbox  

The gearbox is the core mechanical component whose purpose is to convert the high-speed, low-torque rotation of the BLDC motor into an optimum-speed, high-torque, and controlled flapping motion.  

We designed a compact 2-stage gearbox that achieves a final reduction ratio of **45:1**, bringing the motor’s **12,432 RPM** (considering 80% efficiency of the BLDC motor) down to **300 RPM (5 Hz flapping frequency)**.  

By balancing **weight (less than 100 g)**, durability, and efficiency, this gearbox ensures the wings flap with enough torque and optimum speed for **sustained and efficient flight**.  

<p align="center">
  <img src="Gearbox/assets/gearbox_sideview.jpg" alt="Gearbox Side View" width="30%">
  <img src="Gearbox/assets/gearbox_front_view.jpg" alt="Gearbox Front View" width="30%">
</p>  

---

## Wing Mechanism  

The **wing mechanism** acts as the link between the gearbox and the wings, transmitting torque while ensuring **symmetric and controlled flapping motion**. We implemented a **4-bar mechanism**, widely used in ornithopter designs, to convert the rotary output of the gearbox into oscillatory wing motion.  

This setup ensures:  
- **Equal flapping angles** on both wings for stability  
- **Smooth oscillation** without jerks or misalignment  
- **Compact integration** with the gearbox  

The mechanism was designed to maintain structural rigidity while allowing the wings to flap at **5 Hz**, synchronized with the gearbox output.  

<p align="center">
  <img src="WingMechanism/assets/mechanism_1.jpg" alt="Wing Mechanism View 1" width="30%">
  <img src="WingMechanism/assets/mechanism_2.jpg" alt="Wing Mechanism View 2" width="30%">
</p>  

---

##  Wing Design  

The wings are the **primary lift and thrust generating components** of our RC Ornithopter, and their design was one of the most critical challenges. We explored two major approaches:  

1. **Membraned Wing** – A flexible fabric stretched over a frame, lightweight and naturally adaptable.  
2. **Aerofoiled Wing** – A rigid aerodynamic profile designed for maximum lift efficiency.  

The membraned wing offered lightweight construction but faced practical issues: difficulty in finding materials, failed heat shrinking, and unreliable stitching/tension. After trials with umbrella fabric (PET), this design was abandoned.  

The final choice was the Aerofoiled Wing specifically using the **S1223 aerofoil**, known for its excellent lift-to-drag ratio and similarity to bird wings (e.g., seagull). Our prototyping combined 3D-printed ribs with lightweight foam covered in PET fabric for laminar airflow.  

This design resulted in a lightweight, durable, and aerodynamically efficient wing, far superior to the membraned version, and capable of supporting sustained flight.  

<p align="center">
  <img src="WingDesign/assets/S1223_aerofoil.jpg" alt="Aerofoil" width="30%">
  <img src="WingDesign/assets/membranewing.jpg" alt="Membrane Wing Trial" width="30%">
</p>  

---
## Electronics  

The **electronics system** provides power, control, and wireless communication. The goal was to build a lightweight yet reliable setup that could deliver enough power while enabling precise control of the ornithopter’s flapping frequency via wireless input from a transmitter and receiver.  

We used a **1400 KV A2212/10T BLDC motor (68 g)** powered by a **1000mAh 11.1V 30C Li-Po battery (80 g)**. The motor is driven through a **30A Electronic Speed Controller (ESC)**, ensuring smooth conversion of electrical energy into mechanical flapping motion.  

For control, an **ESP32 microcontroller** was selected, paired with the **nRF24L01 radio module** for wireless communication. This enabled us to transmit control inputs remotely in real time.

The components were carefully chosen to balance weight and functionality. Despite challenges with libraries and toolchains (ESP-IDF vs. Arduino IDE), the system now enables precise and smooth control of the gearbox and wing mechanism.  

<p align="center">
  <img src="Electronics/assets/electronics_overview.jpg" alt="Electronics Overview" width="30%">
  
</p>  

---


