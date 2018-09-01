/*
This sketch centers your maze servos on the maze BT control project

 * pitch servo pin 6 group
 * roll servo pin 7 group
 
Written by The Bridgeville Delaware Public Library Teen Imagineering Club
This code is in the public domain 
 */

#include <VarSpeedServo.h>  //include the VarSpeedServo library

VarSpeedServo pitchServo;   //create VarSpeedServo objects for pitch and roll
VarSpeedServo rollServo;

const int svsp = 10;   //speed setting for VarSpeedServo SlowMove
const int pitchHm = 90;   //set so pitch direction is level
const int rollHm = 90;    //set so roll direction is level

void setup()  //setup runs one time
{
  pitchServo.attach(6);  //attach servos to pins
  rollServo.attach(7);
  
  pitchServo.slowmove(pitchHm, svsp);  //Home servos to start
  rollServo.slowmove(rollHm, svsp);
}

void loop() //loop repeats forever
{   
  // Nothing here
}
