# Video #253 Arduino Task Scheduler (Super-Accurate!)
Finally a task scheduler that is super accurate - good enough for a clock!

[thumbnail]  
[video reference]  
[sponsor]  
  
[![JLCPCB-Purple](https://user-images.githubusercontent.com/20911308/159024530-3e083ca1-fea4-4ba9-97d3-a3af3fb979d2.png)](https://www.jlcpcb.com/cem)  

[![PCB Way One Stop Shop](https://user-images.githubusercontent.com/20911308/197213913-10dc32a6-0113-4d9b-9a8d-ea8fa198e550.gif)](https://pcbway.com)  

During the course of playing about with 7-segment animation, I stumbled across a very well-written **Task Scheduler** for the **Arduiino, STM32, ESP32** and others too.

I used it just to display a "clock" on the 4-digit, 7-segment display I was using for the animation - and was amazed to find that it was still accurately displaying the correct time the next day.

Anyone who has ever tried to make an accurate loop in the Arduino environment will know that "drift" is unavoidable. That is, the time taken to execute the loop or function has an adverse effect on the timing accuracy of the loop, especially if the loop's code does not always execute the same code.

So Anatoli Arkhipenko's Task Scheduler is a great find, and has lots of options, not to mention examples. It's worth taking the time to read the documentation to get a better grasp of the potential of this library; not least the option to ensure that a task is effectively guaranteed to fire the correct number of times in a given time period.

![image](https://user-images.githubusercontent.com/20911308/197213109-80e960f4-d2d0-4ad8-9e12-d8d1d600e6a9.png)  
The four-digit 74HC595-controlled device (two 2-digit devices cascaded [soldered] together) can be found here:  
https://s.click.aliexpress.com/e/_DEt25OF  
They don't make a great clock because the gap between the two sets of two digits is too big, but you could always put a couple of 1.8mm flashing LEDs in there, controlled by another task to ensure they flash accurately every second (just like in the demo sketch). But other ones are available that lend themselves better into making into a clock format.

arkhipenko/TaskScheduler: Cooperative multitasking for Arduino, ESPx, STM32, nRF and other microcontrollers  
https://github.com/arkhipenko/TaskScheduler  
