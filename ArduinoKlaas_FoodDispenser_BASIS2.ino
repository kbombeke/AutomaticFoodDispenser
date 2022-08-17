//// ARDUINO FOOD DISPENSER
// KLAAS BOMBEKE

// INCLUDE LIBRARIES
#include <AccelStepper.h>
#include <NewPing.h>
#include <ezButton.h>


// DECLARE VARIABLES
// Define a stepper and the pins it will use
AccelStepper stepper(1,7,6);
int driverENA = 5; 
int driverDIR = 6;  

// Define the push button
const int BUTTON_PIN =10;
ezButton button(BUTTON_PIN);  // create ezButton object that attach to pin 7;
boolean setdir = HIGH;  


// SETUP

void setup()
{  
    Serial.begin (9600);
    stepper.setMaxSpeed(200.0);
    stepper.setAcceleration(100.0);
    pinMode (driverENA, OUTPUT);
    pinMode (driverDIR, OUTPUT);
    button.setDebounceTime(1000);// set debounce time to 50 millisecond  

    
}


// MAIN LOOP

void loop()
{  

   button.loop(); // MUST call the loop() function first
//  char method = "buttonpress";
//  if (method == "buttonpress") { 



      if(button.isPressed()) {
          Serial.println("The button is pressed");
          digitalWrite(driverENA, HIGH);
          digitalWrite(driverDIR, HIGH); // Move the motor clockwise
          stepper.runToNewPosition(stepper.currentPosition()+200);
          digitalWrite(driverENA, LOW);
          
          //delay(5000);
          
          }
      if(button.isReleased()) {
          Serial.println("The button is released");
          digitalWrite(driverENA, HIGH);
          digitalWrite(driverDIR, HIGH); // Move the motor clockwise
          stepper.runToNewPosition(stepper.currentPosition()+200);
          digitalWrite(driverENA, LOW);
          //delay(5000);
          }

//    } 
//    else if(method == "time") {    
//
//          digitalWrite(driverENA, HIGH);
//          stepper.runToNewPosition(stepper.currentPosition()+200);
//          digitalWrite(driverENA, LOW);
//          delay(5000);
//      }

}



////////////////////////////////////////////////////////////////////////////////////////////////////////////


//const int buzzer = 9; //buzzer to arduino pin 9


    //tone(buzzer, 1000); // Send 1KHz sound signal...
    // digitalWrite(buzzer, HIGH); // Turn the LED on
    //delay(1000);        // ...for 1 sec
    //noTone(buzzer);     // Stop sound...
    //digitalWrite(buzzer, LOW); // Turn the LED off
    //delay(1000);        // ...for 1sec
