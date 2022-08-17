// Include NewPing Library
#include "NewPing.h"


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
  if (distance >= 400 || distance <= 2) {
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);
  }
  delay(500);

  
//    tone(buzzer, 1000); // Send 1KHz sound signal...
//    digitalWrite(led, HIGH); // Turn the LED on
//    delay(1000);        // ...for 1 sec
//    noTone(buzzer);     // Stop sound...
//    digitalWrite(led, LOW); // Turn the LED off
//    delay(1000);        // ...for 1sec
//    digitalWrite(driverENA, HIGH);
//    stepper.runToNewPosition(stepper.currentPosition()+200);
//    digitalWrite(driverENA, LOW);
//    delay(5000);
}
