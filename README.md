# Video #253 Arduino Task Scheduler (Super-Accurate!)
Finally a task scheduler that is super accurate - good enough for a clock!

![Thumbnail-00006 (Phone)](https://user-images.githubusercontent.com/20911308/197991675-73f59f28-8e3e-48bf-9134-583157227d7f.png)  

# Video #253: https://youtu.be/eoJUlH_rWOE
[![PCBWay One Stop Shopy](https://user-images.githubusercontent.com/20911308/197213913-10dc32a6-0113-4d9b-9a8d-ea8fa198e550.gif "PCBWay One Stop Prototyping Shop")](https://pcbway.com/)  

During the course of playing about with 7-segment animation, I stumbled across a very well-written **Task Scheduler** for the **Arduiino, STM32, ESP32** and others too, from Anatoli Arkhipenko.

I used it just to display a "clock" on the 4-digit, 7-segment display I was using for the animation - and was amazed to find that it was still accurately displaying the correct time the next day. No RTC. No access to the Internet. But still accurate. Unheard of!  

Anyone who has ever tried to make an accurate loop in the Arduino environment will know that "drift" is normally unavoidable. That is, the time taken to execute the loop or function has an adverse effect on the timing accuracy of the loop, especially if the loop's code does not always execute the same code. Not any more!  

### SOFTWARE
So [Anatoli Arkhipenko's Task Scheduler](https://github.com/arkhipenko/TaskScheduler) is a great find, and has lots of options, not to mention examples. It's worth taking the time to read the documentation to get a better grasp of the potential of this library; not least the option to ensure that a task is effectively guaranteed to fire the correct number of times in a given time period.
<br>
![Task Scheduler Library Screenshot (Custom)](https://user-images.githubusercontent.com/20911308/197220810-609ad936-ce50-4652-948c-1b4f6491e276.png)  
**arkhipenko/TaskScheduler**: Cooperative multitasking for Arduino, ESPx, STM32, nRF and other microcontrollers  
https://github.com/arkhipenko/TaskScheduler  
<br>
<br>
![227 Thumbnail (Custom)](https://user-images.githubusercontent.com/20911308/197219189-70823ace-552d-4963-949f-cff150d63f6c.jpg)  
**Using printf in an Arduino environment:**  
https://youtu.be/lhwk5vJ1iMA  
<br>
<br>
*![Thumbnail (Custom)](https://user-images.githubusercontent.com/20911308/197218755-4e2f4c69-be3f-4e91-a20c-5ecca42a272b.jpg)  
**FreeRTOS on an Arduino? No way! Yes way!**  
https://youtu.be/s57Xr5LsN60  

### HARDWARE
![Two Digit 7-Segment (Custom)](https://user-images.githubusercontent.com/20911308/197219827-fa2266f3-7302-42ce-925e-56175efdf99d.png)  
The four-digit 74HC595-controlled device (two 2-digit devices cascaded [soldered] together) can be found here:  
https://s.click.aliexpress.com/e/_DEt25OF  
_They don't make a great clock because the gap between the two sets of two digits is too big, but you could always put a couple of 1.8mm flashing LEDs in there, controlled by another task to ensure they flash accurately every second (just like in the demo sketch). But other ones are available that lend themselves better into making into a clock format._  

### LINKS
► Clickable list of all my videos
(Special thanks to Michael Kurt Vogel for compiling this)  
http://bit.ly/YouTubeVideoList-RalphBacon  

► If you like this video please give it a thumbs up, share it and if you're not already subscribed please consider doing so and joining me on my Arduinite (and other μControllers) journey  

My channel, GitHub and blog are here:  
\------------------------------------------------------------------  
• https://www.youtube.com/RalphBacon  
• https://ralphbacon.blog  
• https://github.com/RalphBacon  
• https://buymeacoffee.com/ralphbacon  
\------------------------------------------------------------------

My ABOUT page with email address: https://www.youtube.com/c/RalphBacon/about

