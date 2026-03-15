🔐 Password Based Door Lock System
📌 Overview

The Password Based Door Lock System is a microcontroller-based security system designed to enhance access control using a digital keypad instead of traditional mechanical keys. The system uses an 8051 microcontroller to verify a user-entered password and control a door mechanism.

When the correct password is entered, the system allows the user to open or close the door using a DC motor. If the password is incorrect, the system triggers a buzzer alert and visual indication using LEDs.

This project was designed and simulated using Proteus 8 Professional for circuit design and Keil uVision 5 for programming the 8051 microcontroller.




🎯 Objectives

Provide a secure and modern alternative to traditional door locks.

Implement password-based authentication using an 8051 microcontroller.

Create a low-cost security system suitable for homes and offices.

Improve user convenience by eliminating physical keys.

Apply embedded systems concepts in a practical project.


⚙️ System Requirements
💻 Software Requirements

Proteus 8 Professional

Keil uVision 5

🔌 Hardware Components

8051 Microcontroller

LCD Display

Keypad

DC Motor

Buzzer

LEDs  



🧩 Components Description
8051 Microcontroller

The 8051 microcontroller acts as the main controller of the system. It processes user inputs from the keypad and controls the LCD, LEDs, buzzer, and DC motor.

LCD Display

The LCD screen displays messages such as:

Enter Code

Valid Password

Invalid Password

Door Status

Keypad

The keypad allows users to enter the password required to unlock the door.

DC Motor

The DC motor simulates the door mechanism:

Clockwise rotation → Door Opening

Anti-clockwise rotation → Door Closing

LEDs

LEDs provide visual feedback:

Green LED → Valid password

Red LED → Invalid password

Buzzer

The buzzer produces an alarm sound when an incorrect password is entered.



🔄 Working Process
1. Initialization

The system starts by initializing the LCD, keypad, and microcontroller ports.

2. Password Entry

The user enters a 4-digit password using the keypad. The digits are displayed as * on the LCD for security.

3. Password Validation

The entered password is compared with the stored password (1234 by default).

4. Access Granted

If the password is correct:

LCD displays "Valid Code"

User can choose options:

Open Door

Close Door

Change Password

5. Access Denied

If the password is incorrect:

LCD shows "Invalid Code / Access Denied"

Red LED turns on

Buzzer sounds an alert




🖥️ Circuit Design
Block Diagram




The system connects all components to the 8051 microcontroller, which controls the input and output devices.

Component Connections:

Keypad → Port 1 (Pins 0–6)

Buzzer → Port 1 (Pin 7)

LCD → Port 2 (Pins 0–7)

LCD Control → Port 3 (Pins 0–1)

LEDs → Port 3 (Pins 2–3)

DC Motor → Port 3 (Pins 4–5)

The complete circuit was designed and tested using Proteus simulation software.




📊 Results

The system successfully performs the following operations:

Password verification

Door opening and closing

Password changing functionality

Visual indication using LEDs

Audible alerts using buzzer

Simulation results were verified using Proteus circuit simulation.



👤 Author

Jayaram Kandukuri  
B.Tech – Electronics and Communication Engineering  
SRM University AP  

📧 jayaramknss@gmail.com
