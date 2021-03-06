/*
This sketch demonstrates bluetooth control of a maze using an Android device.
In addition to the arduino (RoboRed) you need a HC-05 / HC-06 bluetooth board and 2 servos.

 The circuit: 
 * The RoboRed has a serial data pin group. Wire to bluetooth 
   * RX  (connect to TX of bluetooth board)
   * TX  (connect to RX of bluetooth board)
   * VCC
   * GND
 * pitch servo pin 6 group
 * roll servo pin 7 group
 
Written by The Bridgeville Delaware Public Library Teen Imagineering Club
This code is in the public domain 
 */

#include <VarSpeedServo.h>  //include the VarSpeedServo library

VarSpeedServo pitchServo;   //create VarSpeedServo objects for pitch and roll
VarSpeedServo rollServo;

const int svsp = 10;   //speed setting for VarSpeedServo SlowMove
const int pitchHm = 97;   //set so the maze pitch direction is level
const int rollHm = 90;    //set so the maze roll direction is level
int pitch;
int roll;

void setup()  //setup runs one time
{
  // Open serial communications-via bluetooth
  Serial.begin(9600);
 
  pitchServo.attach(6);  //attach servos to pins
  rollServo.attach(7);
  
  pitchServo.slowmove(pitchHm, svsp);  //Home servos to start
  rollServo.slowmove(rollHm, svsp);
  delay(200);
  
}

void loop() //loop repeats forever
{
   // if there's any serial available, read it:
  while (Serial.available() > 0) {
    // look for the next valid integer in the incoming serial stream:
    pitch = Serial.parseInt();
    // do it again:
    roll = Serial.parseInt();
    if (Serial.read() == '\n') break;  // look for the newline. That's the end of your read
  }
      //keep angles under 15 degrees
      pitch = constrain(pitch, -15, 15);
      roll = constrain(roll, -15, 15);
      //move servos to pitch and roll angles
      pitchServo.slowmove(pitchHm - pitch, svsp);  // change - to + if pitch is backword
      rollServo.slowmove(rollHm + roll, svsp);
      delay(70);  // let slowmove do its thing
}
