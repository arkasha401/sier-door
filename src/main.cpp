#include <Arduino.h>
#include <HardwareSerial.h>
#include <Servo.h>

extern "C" 
{
    #include <pins.h>
    #include "lock.h" 
}

Servo servo;
Lock lock;

void setup() 
{
    // lock_initialize(&lock, PIN_BUTTON, 9600, PIN_SERVO);
    lock_initialize(&lock, PIN_BUTTON, 9600, PIN_SERVO);
}

void loop() 
{
   // lock_update(&lock);
}
