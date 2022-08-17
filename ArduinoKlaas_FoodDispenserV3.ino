// Blocking.pde
// -*- mode: C++ -*-
//
// Shows how to use the blocking call runToNewPosition
// Which sets a new target position and then waits until the stepper has 
// achieved it.
//
// Copyright (C) 2009 Mike McCauley
// $Id: Blocking.pde,v 1.1 2011/01/05 01:51:01 mikem Exp mikem $

#include <AccelStepper.h>

// Include NewPing Library
#include "NewPing.h"

// Define a stepper and the pins it will use
AccelStepper stepper(1,7,6);
int driverENA = 5; 
const int buzzer = 9; //buzzer to arduino pin 9
int led = 10; // the pin the LED is connected to

// This uses Serial Monitor to display Range Finder distance readings
 // Hook up HC-SR04 with Trig to Arduino Pin 10, Echo to Arduino pin 13
// Maximum Distance is 400 cm
 
#define TRIGGER_PIN  11
#define ECHO_PIN     13
#define MAX_DISTANCE 400
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
float duration, distance;
 
int iterations = 5;

void setup()
{  
    Serial.begin (9600);
    stepper.setMaxSpeed(200.0);
    stepper.setAcceleration(100.0);
    pinMode (driverENA, OUTPUT);
    pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
    pinMode(led, OUTPUT); // Declare the LED as an output
}


void loop()
{  
  duration = sonar.ping_median(iterations);
  
  // Determine distance from duration
  // Use 343 metres per second as speed of sound
  
  distance = (duration / 2) * 0.0343;
  
  // Send results to Serial Monitor
  Serial.print("Distance = ");
  if (distance >= 150 || distance <= 100) {
    Serial.println("No reward");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
//    tone(buzzer, 1000); // Send 1KHz sound signal...
  digitalWrite(led, HIGH); // Turn the LED on
   delay(1000);        // ...for 1 sec
//    noTone(buzzer);     // Stop sound...
    digitalWrite(led, LOW); // Turn the LED off
   delay(1000);        // ...for 1sec
   digitalWrite(driverENA, HIGH);
   stepper.runToNewPosition(stepper.currentPosition()+200);
   digitalWrite(driverENA, LOW);
    delay(5000);
    delay(500);
  }
  delay(500);

  

}
