
#include <AccelStepper.h>

// Include NewPing Library
#include "NewPing.h"
//#include <Tone.h>

// Define a stepper and the pins it will use
AccelStepper stepper(1,7,6);
int driverENA = 5; 
int driverDIR = 6;       // DIR-pin
const int buzzer = 9; //buzzer to arduino pin 9

// Define the push button
const int BUTTON_PIN =10;
ezButton (BUTTON_PIN);  // create ezButton object that attach to pin 7;

// variables will change:
int DispenseState = LOW;   // the current state of the dispenser


void setup()
{  
    Serial.begin (9600);
    stepper.setMaxSpeed(200.0);
    stepper.setAcceleration(100.0);
    pinMode (driverENA, OUTPUT);
    pinMode (driverDIR, OUTPUT);
    //pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output

   button.setDebounceTime(50); // set debounce time to 50 millisecond
    
    
}


void loop()
{  
    //tone(buzzer, 1000); // Send 1KHz sound signal...
    // digitalWrite(buzzer, HIGH); // Turn the LED on
    //delay(1000);        // ...for 1 sec
    //noTone(buzzer);     // Stop sound...
    //digitalWrite(buzzer, LOW); // Turn the LED off
    //delay(1000);        // ...for 1sec


    // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
    button.loop(); // MUST call the loop() function first

      if(button.isPressed()) {
          Serial.println("The button is pressed");
          digitalWrite(driverENA, HIGH);
          digitalWrite(driverDIR, HIGH); // Move the motor counterclockwise
          stepper.runToNewPosition(stepper.currentPosition()+200);
          digitalWrite(driverENA, LOW);
           digitalWrite(driverDIR, LOW); // Move the motor clockwise
          delay(5000);
          }
    

}
