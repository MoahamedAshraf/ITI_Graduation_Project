# Adaptive Cruise Control connected to Infotainment System


1-    General view of the system:
Since safety is valuable and human nature tends to be more comfortable and make life easier,
Our System is designed to help vehicles maintain a safe following distance and stay within the speed limitations.
It includes both Normal Cruise Control (NCC) and Adaptive Cruise Control (ACC) types.
NCC type; in this mode the car maintains its speed and the user can't accelerate the car above the maintained speed but he can deaccelerate the car's speed. If an object is at a distance that is close to the car, an alarm is fired to alert the driver. Also, In case of critical Distance, the car is immediately stops using Automatic Emergency Braking (AEB) system.
ACC Type, in this mode also the car maintains its speed and the user can't accelerate the car above the maintained speed but he can deaccelerate the car's speed. But the difference here is that the Driver has some ranges of Distance to choose the preferred Distance between his vehicle and the vehicle ahead to adapt the car speed to it.
If a car ahead is slowing down or getting close, the user's car also slows down so it keeps the selected distance between the two cars until it stops, if the other car ahead got so close. Once the car, in front, starts moving again and the sensor will not detect any obstacles ahead, so the car starts accelerating again until it reaches the lately maintained speed on ACC mode.
Also, here, in case of critical Distance, the car is immediately stops using the Automatic Emergency Braking (AEB) system.

2-	How Our System works?
•	Arm communicates with raspberry pi using UART communication protocol.
•	Peripherals used in STM32F401CC is: Timer (PWM mode & ICU mode) , GPIO, Systick, RCC, NVIC, USART.
•	All system features (ACC on, NCC on, CC off, Accelerate, Decelerate, Distance Ranges) are controlled from the GUI buttons.
•	Distance and Speed is received and displayed on the GUI.
•	The GUI has been done using QT.
•	NCC and CC features can also be controlled using voice command through IOT technology.
