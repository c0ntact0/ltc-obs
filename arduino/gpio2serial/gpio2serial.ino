/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/DigitalReadSerial
*/
#include <util/atomic.h>
// digital pin 2 has a pushbutton attached to it. Give it a name:
// Using no PWM pins
byte cams[4] = {2,4,7,8};
byte states[4] = {0,0,0,0};
byte currentCam = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  for (int i = 0;i < sizeof(cams);i++) {
    pinMode(cams[i],INPUT);
  }
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
    for (int i = 0;i < sizeof(cams);i++) {
      states[i] = digitalRead(cams[i]);
  }
  stateMachine();
  delay(10);  // delay in between reads for stability
  // print out the state of the button:
}


void stateMachine() {
  
    byte newCam = 0;
    byte pressedCams = 0;
    byte oldCam = currentCam;
    for (int i = 0;i < sizeof(states);i++) {
      newCam = i + 1;
      if (states[i] == 1 && currentCam != newCam && pressedCams == 0) {
        pressedCams++;
        currentCam = newCam;
        Serial.print(currentCam);
      }
    
    }

}