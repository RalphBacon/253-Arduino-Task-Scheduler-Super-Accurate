#include <Arduino.h>

// 74HC595 8-bit Shift Register (with latch) demo for 7-segment displays
// This sketch shows a "clock" (smoke and mirrors) that animates the minutes changing
#include "charSet.h"
#include <LibPrintf.h>

// Specify all #define statements for task scheduler first
#define _TASK_SCHEDULING_OPTIONS
//#define _TASK_TIMECRITICAL
//#define _TASK_SLEEP_ON_IDLE_RUN
#include <TaskScheduler.h>

// More concise definition
#define BLANK _digits[10]

// Clock pin 11 on 74HC595
#define clockPin 12

// Serial data on pin 14 on 74HC595
#define dataPin 11

// Latch pin on pin 12 on 74HC595
#define latchPin 8

// Seconds flasher (@2Hz, on/off so a flash every second)
#define ledSecs 13

// Counter for hours and minutes
uint8_t hours = 10;
uint8_t mins = 30;

// Forward declaration of callback(s)
void clockTaskCallback();
void blankDigits(uint8_t digitsToBlank);
void secondsToggle();

// Create the task scheduler
Scheduler schedule;

// Create a task to run every minute to update the 'clock'
Task clockTask(60000, TASK_FOREVER, &clockTaskCallback);

// Task to flash the seconds LED twice second to toggle the LED
Task secondsTask(500, TASK_FOREVER, &secondsToggle);

void setup() {
  Serial.begin(115200);

  // All 74HC595 pins send out data
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

  // Our seconds flasher
  pinMode(ledSecs, OUTPUT);

  // Initially, don't send out any data
  digitalWrite(clockPin, LOW);
  digitalWrite(latchPin, LOW);

  // Initialise the 'clock' (4 digits)
  blankDigits(4);

  // Set the options for the task so that it "catches up" if there is a delay
  clockTask.setSchedulingOption(TASK_SCHEDULE);
  secondsTask.setSchedulingOption(TASK_SCHEDULE);

  // Initialise the task scheduler and start the tasks
  schedule.init();
  schedule.addTask(clockTask);
  schedule.addTask(secondsTask);
  clockTask.enable();
  secondsTask.enable();

  // All done
  printf("Setup completed.\n");
}

void loop() {
  // Task execution
  schedule.execute();
}

void sendOut(uint8_t val) {
  uint8_t i;

  for (i = 0; i < 8; i++) {

    digitalWrite(dataPin, val & 1);
    val >>= 1;

    // Pulse the Clock so 74HC595 takes note of data value
    digitalWrite(clockPin, HIGH);
    digitalWrite(clockPin, LOW);

    // Show the current output by pulsing LATCH (aka LOAD) pin
    digitalWrite(latchPin, HIGH);
    digitalWrite(latchPin, LOW);

    delay(50);
  }
}

void blankDigits(uint8_t digitsToBlank) {
  // Blank the 'clock' (4 digits)
  digitalWrite(latchPin, LOW);
  for (auto digit = 0; digit < digitsToBlank; digit++) {
    shiftOut(dataPin, clockPin, LSBFIRST, BLANK);
  }
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
}

void clockTaskCallback() {
  // -----------------------------
  // Rollover to the next 'minute'
  // -----------------------------

  // Split the hours into two digit values
  uint8_t hoursTens = hours / 10;
  uint8_t hoursUnits = hours % 10;

  // Split the minutes into two digits values
  uint8_t minsTens = mins / 10;
  uint8_t minsUnits = mins % 10;

  printf("Hours Tens: %d, Hours Units: %d, Mins Tens: %d, Mins Units: %d\n", hoursTens, hoursUnits, minsTens, minsUnits);
  sendOut(_digits[minsUnits]);
  sendOut(_digits[minsTens]);
  sendOut(_digits[hoursUnits]);
  sendOut(_digits[hoursTens]);

  // Increment the minutes and check for overflow
  if (mins == 59) {
    hours++;
    mins = 0;
    if (hours > 23) {
      hours = 0;
    }
  } else {
    mins++;
  }
}

// Simple seconds LED toggle on/off
void secondsToggle() {
  digitalWrite(ledSecs, !(digitalRead(ledSecs)));
}