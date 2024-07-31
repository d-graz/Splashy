# Splashy
<p align="center">
  <img src="documentation/images/logo_scaled.jpeg" />
</p>

![logo_final](https://github.com/user-attachments/assets/f5fed4ba-afbe-40ae-9c03-79528b048abe)


*"Splashy is a penguin shaped robot that helps you in refilling your water bottle"*
- Politecnico di Milan, Robotics \& Design course, A.Y. 2023/2024

<div align="center">
  <video src="https://github.com/user-attachments/assets/95a2d4e3-3e73-4272-86ca-d840ce8c92a2" width="1280" />
</div>

### Table of content
- [Introduction](#introduction)
- [Do It Yourself](#diy)
- [Credits](#credits)

## Introduction
This project started with the task *to create something that would have changed the behavior of people* (for the better of course =) ) on campus, given the constrain of non-mobility of such robot. Given such a constrain we explored some ideas before realizing that plastic has been a problem since forever and that the water refillers on campus where not that good. In fact thoose machines were slow resulting in a booring queue during peak hours. This somethimes would result in people buying  plastic water bottles from vending machines.\
Now i will **briefly** present some design challenges encoutered during developing of such a project. The full report can be found [here](documentation/report.pdf)

### How to attract people the first time (discovery)
The robot embeds a `PIR Sensor` able to detect motion. If the robot is not current under usage it will attract people passing by using it's wings (`servo motors` handles motion) and adjusting it's facial expression(rendered using `8x8 led matrices`).

### How to attract people in the long run (re-usage)
Splashy has a `NFC Reader`. This nfc can be used to identify users and thus create a rank based on the quantity of recharges that have been made. The rank is presented using an `LCD Screen`. This creates a gamification aspect in the refilling process

### Distribution of water
The water can be pumped from a water tank using a `pump` (like in our case) or alternative the penguin can be directly attached to a pressured faucet by replacing the pump with a `electric driven valve` 

## DIY
If you plan to recreate this project:
1. find all the components used for Splasy [here](documentation/BOM.pdf)
2. find all the 3d-printable in the `stl` directory
3. give a **careful** read to the [report](documentation/report.pdf)
4. Additionally read [user manual](documentation/user_manual.pdf) and [maintence manual](documentation/maintence_manual.pdf)

## Credits
<p align="center">
  <img src="https://github.com/user-attachments/assets/9bc1cc19-a49e-4e46-a704-29662c4543e2" />
</p>
- Sofia Maria Ciccia (School of Design and Engineering)
- Davide Grazzani    (me, Computer Science Engineer)
- Gianluca Miglietta (Automation Engineer)
- Enrico Virgili     (School of Design and Engineering)

Supervisors:
- prof. Andrea Bonarini
- prof. Maximiliano Ernesto Romero
