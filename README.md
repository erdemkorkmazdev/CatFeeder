# CatFeeder
Arduino Automatic Cat Feeder Measuring Weight
Project Description: Weighing Food Automatic Pet Feeder
In this project, an automatic pet feeder is designed using a load cell and HX711 amplifier module to measure and control the amount of pet food. The weight data is displayed on a 16x2 LCD screen. When the weight drops below 1.5 kilograms, a stepper motor is triggered to dispense the calibrated amount of food onto a platform below.

The operation of the automatic pet feeder is based on the following principles:

•	Load Cell and HX711: The load cell is a sensor used to measure the food quantity. The HX711 amplifier module facilitates the connection between the load cell and Arduino. The load cell accurately detects the food weight, and the HX711 module performs amplification and analog-to-digital conversion.

•	LCD Display: The project utilizes a 16x2 character LCD screen. The LCD screen shows the weight data to the user. The first line displays "Weight:", while the second line shows the measured weight. This allows the user to easily monitor the food quantity.

•	Stepper Motor: The stepper motor controls the feeding mechanism of the pet feeder. When the measured weight drops below 1.5 kilograms, the stepper motor is triggered. The motor rotates a specified number of steps, dispensing the calibrated amount of food onto the platform below. Afterwards, the motor returns to its initial position.

To summarize the project's operation:

•	Arduino communicates with the HX711 amplifier module and the LCD screen.
•	The load cell measures the food weight and transmits the analog data to the HX711 module for Arduino to read.
•	Arduino displays the measured weight on the LCD screen.
•	Arduino checks the weight and triggers the stepper motor if it is below 1.5 kilograms.
•	The stepper motor rotates a specified number of steps to dispense the calibrated amount of food onto the platform.
•	The motor then returns to its initial position.
•	Arduino displays the new measured weight on the LCD screen, and the loop continues.
•	A potentiometer is used to adjust the contrast of the LCD screen.
•	An intermediate amplifier is utilized for the smooth movement of the stepper motor.
•	A platform is designed to ensure proper positioning of the load cell.
With this project, the automatic pet feeder provides precise control over the food quantity, allowing pets to be fed accurately. The user can monitor the food quantity through the LCD screen and intervene if necessary.

Connection Diagram: 
![image](https://github.com/erdemkorkmazdev/CatFeeder/assets/98043504/cca81929-53c9-4b6a-b84f-a392a804a56b)
