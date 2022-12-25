#include <Arduino.h>
#include <HardwareSerial.h>
#include <Servo.h>

extern "C" 
{
    #include "pins.h"
    #include "lock.h" 
}

Servo servo;
Lock lock;

void setup() 
{
   lock_initialize(&lock, PIN_BUTTON, 115200, PIN_SERVO);
   pinMode(13, OUTPUT);
   digitalWrite(13,HIGH);
}

void loop() 
{
   lock_update(&lock);
}
