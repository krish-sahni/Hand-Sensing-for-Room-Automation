# Automated Room Sensor with Ultrasonic Sensors

## Project Overview

This project involves the creation of an automated room control system using ultrasonic sensors to detect hand movements. The system is designed to control functionalities such as light switches based on detected gestures. The project demonstrates my ability to integrate sensor technology with microcontroller programming and communication modules, aligning with my aspirations in automation, robotics, control systems, and hardware design.

## Features

- **Hand Motion Detection:** Utilizes three HCSR04 ultrasonic sensors arranged in a triangular setup to detect hand movements in six directions.
- **3D Printed Sensor Mount:** Custom-designed and 3D printed mount to hold the sensors in place.
- **Arduino Integration:** Sensors connected to an Arduino microcontroller for processing hand motion data.
- **NRF24L01 Communication:** Wireless communication with another Arduino to send control commands.
- **Example Application:** Demonstrated by using the system to turn a motor on and off, which can be used to control lights or other devices.

## Technologies Used

- **CAD Design:** Used for designing the sensor mount.
- **3D Printing:** Fabricated the custom sensor mount.
- **HCSR04 Ultrasonic Sensors:** For detecting hand movements.
- **Arduino:** For processing sensor data and controlling devices.
- **NRF24L01 Module:** For wireless communication between Arduino boards.
- **C++:** Programming language used for writing the Arduino code.

## Installation

To replicate this project, you will need:

- Three HCSR04 ultrasonic sensors
- Two Arduino boards
- NRF24L01 modules for wireless communication
- A 3D printer and filament
- Wires and breadboard for connections

## Steps:

1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/automated-room-sensor.git
2. 3D print the sensor mount using the provided CAD files.
3. Assemble the sensors and Arduino boards according to the provided schematics.
4. Upload the Arduino code to the respective boards.
5. Set up the NRF24L01 modules for wireless communication.
6. Power the system and test hand movements to control the connected device.

## Usage:

1. Power on both Arduino boards.
2. Place your hand in the detection area.
3. Move your hand in the desired direction to trigger the corresponding action.
4. The system will detect the motion and send a command to the second Arduino to perform the action (e.g., turning on/off a motor).

## Impact and Results

This project showcased my ability to design and implement an automation system using sensor technology and microcontroller programming. The complexity of detecting hand motions in multiple directions and ensuring accurate gesture recognition provided valuable experience in algorithm development and hardware integration. The successful demonstration of controlling a motor based on hand movements highlights the practical applications of this system in smart home and automation technologies.
## Future Work

Future enhancements for this project could include refining the motion detection algorithms for increased accuracy and reliability, integrating additional sensors for more complex gesture recognition, and expanding the system to control multiple devices simultaneously. Additionally, incorporating machine learning techniques to improve gesture recognition and adaptability could further enhance the system's capabilities. These advancements align with my career goals in automation, robotics, and control systems, providing further opportunities to develop and demonstrate my expertise in these fields.
### License
This project is licensed under the MIT License. See the LICENSE file for details.
