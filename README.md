# Video #253 Arduino Task Scheduler (Super-Accurate!)
Finally a task scheduler that is super accurate - good enough for a clock!

[thumbnail]
[video reference]
[sponsor]

During the course of playing about with 7-segment animation, I stumbled across a very well-written Task Scheduler for the Arduiino, STM32, ESP32 and others too.

I used it just to display a "clock" on the 4-digit, 7-segment display I was using for the animation - and was amazed to find that it was still accurately displaying the correct time the next day.

Anyone who has ever tried to make an accurate loop in the Arduino environment will know that "drift" is unavoidable. That is, the time taken to execute the loop or function has an adverse effect on the timing accuracy of the loop, especially if the loop's code does not always execute the same code.

