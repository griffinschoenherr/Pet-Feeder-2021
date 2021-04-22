# Pet-Feeder-2021
![IMG_1671](https://user-images.githubusercontent.com/47340308/115754890-b0065d00-a36a-11eb-87f9-59a36863617e.png)


## Description 
<li> For my senior project, I created a Pet Feeder, powered by ESP 8266 NodeMCU. This project was built with the intention of having the pet feeder be controlled via NodeMCU, which in turn would be controlled with Blynk, a platform for the feeder to be controlled over the internet with. </li>
<li> The feeder is coded such that it can be manually triggered, or have two alarms set for it to go off throughout the day.</li>
<li> Feeder will display feed intervals in the app. </li>
<li> Amount of servings can be adjusted in app.</li>
## Hardware
<li> ESP8266 NodeMCU </li>
![IMG_1682](https://user-images.githubusercontent.com/47340308/115754591-57cf5b00-a36a-11eb-8e88-8eb90f64898b.png)


<li> Breadboard </li>
<li> Jumper wires </li>
<li> 180 deg. Servo Motor </li>
![IMG_1632](https://user-images.githubusercontent.com/47340308/115754630-61f15980-a36a-11eb-914a-f7f0beee9926.png)
<li> Wood (various construction items) </li>
<li> Recycled Cereal Dispenser </li>
<li> Power Supply Unit </li>

## Software
1. Arduino IDE
2. Blynk App
![IMG_1678 (2)](https://user-images.githubusercontent.com/47340308/115754669-6e75b200-a36a-11eb-9f3a-b59fa47abfce.png)
![IMG_1678](https://user-images.githubusercontent.com/47340308/115754693-76cded00-a36a-11eb-86f9-6df07ab20e6b.png)


## Construction Process
1. This was made primarily using wood. In the future, a 3D printed model would be more preferable.
2. The servo attachment was constructed using wooden dowels tapped into drilled out holes, which was then screwed onto the servo motor.
3. For the servo mount, measurements were taken so that the servo would sit in line with the dispenser handles.
![IMG_1632](https://user-images.githubusercontent.com/47340308/115760612-7421c680-a36f-11eb-9695-4d28d1739869.png)
3. The main box was nailed together, with the dispenser holder being held in by screws. The dispenser holder was measured precisely so that the feeder would hold the dispenser.
![IMG_1583](https://user-images.githubusercontent.com/47340308/115768961-fd89c680-a378-11eb-9bdd-b779eed93f8e.png)



## Board Assembly
1. The PSU can be purhcased from Amazon. Please make sure to use one as the servo cannot adequately run off NodeMCU power supply by itself.
![IMG_1673](https://user-images.githubusercontent.com/47340308/115760756-8f8cd180-a36f-11eb-8175-b1d52cb53f01.png)
2. The servo is wired to the breadboard, for power, not the NodeMCU.
3. The NodeMCU pin is wired to the servo for commends, as shown. 
4. The NodeMCU is grounded to the breadboard. It must share the same ground as the servo.
5. NodeMCU power is independent of the servo.


