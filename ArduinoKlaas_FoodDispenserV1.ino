
////// ARDUINO FOOD DISPENSER ///////////


// Define pins

int StartButton = 2;     // Push button to start the motor
int driverPUL = 7;       //PUL-pin
int driverDIR = 6;       // DIR-pin
const int ledPin =  13;      // the number of the LED pin

// Variables

int pd = 1000;           // Pulse Delay period
boolean setdir = LOW;   // Set direction (LOW=clockwise, HIGH=counterclockwise)
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status


void setup() {
  // put your setup code here, to run once:
  pinMode (driverPUL, OUTPUT);
  pinMode (driverDIR, OUTPUT);

  // initialize the pushbutton pin as an input:
  pinMode(StartButton, INPUT);

    // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
}

void loop() {

   // read the state of the pushbutton value:
  buttonState = digitalRead(StartButton);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
      digitalWrite(ledPin, HIGH);
      digitalWrite(driverDIR, LOW); // Move the motor clockwise
      digitalWrite(driverPUL, HIGH);
      delayMicroseconds(pd);
      digitalWrite(driverPUL, LOW);
      delayMicroseconds(pd);
  } else {
    // turn LED off:
      digitalWrite(ledPin, LOW);
      digitalWrite(driverDIR, HIGH); // Move the motor clockwise
      digitalWrite(driverPUL, HIGH);
      delayMicroseconds(pd);
      digitalWrite(driverPUL, LOW);
      delayMicroseconds(pd);
  }
  // put your main code here, to run repeatedly:



}
