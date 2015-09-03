#include <Servo.h>

Servo switcher; //creating the servo object
boolean switchIsOn = false; //assumption is that the Light is off initially
int pos = 0; // variable to store servo position

void setup()
{
  // initialize the serial communication:
  Serial.begin(19200); //baud rate - make sure it matches that of the module you got:
  // attaches the Servo to pin 9
  switcher.attach(9);
}

void loop() {

if (Serial.available() > 0 && Serial.read() == 1){
  if(switchIsOn){ // if the switch is in the on position
    for(pos=41; pos>0; pos-=1){ // sweeps servo down 41 degrees
      switcher.write(pos);
      delay(15);
    }
    switchIsOn=false;
    delay(100); // 1 second wait til the switch can change position again
  }
  else{
    for(pos=0; pos>41; pos+=1){ // sweeps servo up 41 degrees
      switcher.write(pos);
      delay(15);
    }
    switchIsOn=true;
    delay(100); // 1 second wait til the switch can change position again
  }
}

}
