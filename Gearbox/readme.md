#  RC Ornithopter Project

##  GEARBOX

###  **Calculation of Reduction Ratio**
For our **Ornithopter**, we needed a gearbox that was **lightweight, compact, low-friction, and capable of handling high torque with large reduction ratios**.  

We selected a **BLDC motor of 1400 KV** and targeted a **flapping frequency of 5 Hz**. Using an **11.1V battery**, the motor theoretically spins at:  

\[
11.1 \times 1400 = 15,540 \text{ RPM}
\]  

According to the datasheet of the **A2212 10T BLDC motor**, it runs at about **80% efficiency**, which brings it down to:  

\[
15,540 \times 0.85 = 13,209 \text{ RPM}
\]  

To scale this down to **300 RPM (5 Hz flapping)**, we needed a gear reduction of approximately **44:1**.  

---

##  **Options Explored**

###  Compound Gear Train
The first idea was a **4–5 stage compound gearbox** (8–10 gears total). While mechanically feasible, it turned out **too heavy** for our design — about **100 g**.  
Also, our **3D printer couldn’t reliably print pinions smaller than 20 mm**, and gears larger than 10 cm were impractical.  
Thus, **compound gear train was ruled out**.  
 
`![Compound Gear Train]()`  

---

###  Planetary Gearbox
A **planetary gearbox** is compact and efficient, with gears arranged like a miniature solar system.  
A carrier of **10–12 cm diameter** could give a reduction of **5:1 to 8:1**.  
But to reach our requirement, we would need **two planetary gearboxes**, adding up to **100+ g**, making it unsuitable.  

`![Planetary Gearbox]()`  

---

###  Cycloidal Gearbox
A **cycloidal gearbox** achieves **very high reduction ratios** with eccentric rolling motion.  
However, these need to be made of metal, making them too heavy for our ornithopter.  

`![Cycloidal Gearbox]()`  

---

###  Hybrid (Planetary + Compound Gear Train)
We also considered combining both systems:  

- **1 Planetary gearbox** → ~**7:1 reduction**  
- **2-stage compound gear train** → ~**6:1 reduction**  

Together, this gave us **42:1 reduction**.  
By printing gears with **ABS-like resin** (tougher and more durable than PLA), this design became **practical**.  

`![Hybrid Gearbox]()`  

---

##  **Implemented Gearbox**

Finally, we achieved our working solution.  

Since we couldn’t print pinions smaller than **20 mm**, we purchased two 18-tooth pinions (module 0.529) from Robu.  
With these, we achieved the required reduction in just two stages:  

- **Stage 1:** 18T pinion → 128T gear → **7.11:1 reduction**  
- **Stage 2:** 18T pinion → 114T gear → **6.33:1 reduction**  

 **Final reduction ratio:**  
\[
7.11 \times 6.33 = 45.03
\]  

This near-perfect match gave us a **lightweight, efficient gearbox** 🚀  

---

- `![Implemented Gearbox 1]()`  
- `![Implemented Gearbox 2]()`  
- `![Implemented Gearbox 3]()`  

---

 With this, our **RC Ornithopter gearbox** was finalized, striking the right balance between **weight, durability, and efficiency**!
