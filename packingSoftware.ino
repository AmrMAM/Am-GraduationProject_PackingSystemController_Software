
/*=================================================================================================================*/
/*** Author : Amr Mostafa      (Amr_MAM)                                                                         ***/
/*** Title  : Main program file for the controller of the Packing System                                         ***/
/*** Date   : 05Jul2022                                                                                          ***/
/*** Version: V05                                                                                                ***/
/*=================================================================================================================*/

#include "AM_PIN_INTERFACE.h"

int LS1;
int LS2;
int LS3;
int LS4;
int LS5;
int LS6;
int LS7;

void setup()
{
  Serial.begin(9600);

  /*==============[Settings of Pins]===============*/
  pinMode(aPinMotorX_Eng, OUTPUT);
  pinMode(aPinMotorX_Dir, OUTPUT);
  pinMode(aPinMotorX_Step, OUTPUT);

  pinMode(aPinMotorY_Eng, OUTPUT);
  pinMode(aPinMotorY_Dir, OUTPUT);
  pinMode(aPinMotorY_Step, OUTPUT);

  pinMode(aPinMotorZ_Eng, OUTPUT);
  pinMode(aPinMotorZ_Dir, OUTPUT);
  pinMode(aPinMotorZ_Step, OUTPUT);

  pinMode(aPinMotorGr_Eng, OUTPUT);
  pinMode(aPinMotorGr_Dir, OUTPUT);
  pinMode(aPinMotorGr_Step, OUTPUT);

  pinMode(aPinLS1, INPUT_PULLUP);
  pinMode(aPinLS2, INPUT_PULLUP);
  pinMode(aPinLS3, INPUT_PULLUP);
  pinMode(aPinLS4, INPUT_PULLUP);
  pinMode(aPinLS5, INPUT_PULLUP);
  pinMode(aPinLS6, INPUT_PULLUP);
  pinMode(aPinLS7, INPUT_PULLUP);
}

void loop()
{
  listenToSerialCommand();
  limitSwRead();
  delay(100);
}

void limitSwRead(){
  LS1 = digitalRead(aPinLS1);
  LS2 = digitalRead(aPinLS2);
  LS3 = digitalRead(aPinLS3);
  LS4 = digitalRead(aPinLS4);
  LS5 = digitalRead(aPinLS5);
  LS6 = digitalRead(aPinLS6);
  LS7 = digitalRead(aPinLS7);
}

void listenToSerialCommand(){
  u8 cmd =  Serial.read();
  switch (cmd)
  {
  case 'A':  // X-Axis Right
    Serial.println("Motor_X-Axis Starts to move right");
    //motorX(2000, true);
    motorX_Until_Limit(true);
    Serial.println("Motor_X-Axis Finished moving");
    break;  

  case 'B':  // X-Axis Left
    Serial.println("Motor_X-Axis Starts to move left");
    // motorX(2000, false);
    motorX_Until_Limit(false);
    Serial.println("Motor_X-Axis Finished moving");
    break;   

  case 'C':  // Y-Axis In
    Serial.println("Motor_Y-Axis Starts to move in");
    // motorY(2000, true);
    motorY_Until_Limit(true);
    Serial.println("Motor_Y-Axis Finished moving");
    break;  

  case 'D':  // Y-Axis Out
    Serial.println("Motor_Y-Axis Starts to move out");
    // motorY(2000, false);
    motorY_Until_Limit(false);
    Serial.println("Motor_Y-Axis Finished moving");
    break;      

  case 'E':  // Z-Axis Up
    Serial.println("Motor_Z-Axis Starts to move up");
    // motorZ(700, true);
    motorZ_Until_Limit(true);
    Serial.println("Motor_Z-Axis Finished moving");
    break;  

  case 'F':  // Z-Axis Down
    Serial.println("Motor_Z-Axis Starts to move down");
    // motorZ(700, false);
    motorZ_Until_Limit(false);
    Serial.println("Motor_Z-Axis Finished moving");
    break;      

  case 'G':  // GripperMotor holding
    Serial.println("Motor_Gripper Starts to hold the bottle");
    motorGripper(150, true);
    Serial.println("Motor_Gripper Finished moving");
    break;  

  case 'H':  // GripperMotor open
    Serial.println("Motor_Gripper Starts to take off the bottle");
    motorGripper(150, false);
    Serial.println("Motor_Gripper Finished moving");
    break;  

  case 'I':
    Serial.println(LS1);
    Serial.print(' '); Serial.print(LS2);
    Serial.print(' '); Serial.print(LS3);
    Serial.print(' '); Serial.print(LS4);
    Serial.print(' '); Serial.print(LS5);
    Serial.print(' '); Serial.print(LS6);
    Serial.print(' '); Serial.print(LS7);
    break;

 default:
    break;
  }
}

void motorX(u16 u16_steps, bool direction){
  // Todo: do not forget to implement the limit switch conditions
  digitalWrite(aPinMotorX_Eng, LOW);
  digitalWrite(aPinMotorX_Dir, direction);
  for (u16 i = 0; i <= u16_steps; i++)
  {
    limitSwRead();
    if(!LS1 | !LS2 | !LS3) break;
    digitalWrite(aPinMotorX_Step, HIGH);
    delayMicroseconds(700);
    digitalWrite(aPinMotorX_Step, LOW);
    delayMicroseconds(700);
  }
}

void motorX_Until_Limit(bool direction){
  // Todo: do not forget to implement the limit switch conditions
  digitalWrite(aPinMotorX_Eng, LOW);
  digitalWrite(aPinMotorX_Dir, direction);
  while((direction && LS1) | (!direction && (LS2 && LS3)))
  {
    digitalWrite(aPinMotorX_Step, HIGH);
    delayMicroseconds(700);
    digitalWrite(aPinMotorX_Step, LOW);
    delayMicroseconds(700);
    limitSwRead();
  }
  digitalWrite(aPinMotorX_Eng, HIGH);
}

void motorY(u16 u16_steps, bool direction){
  // Todo: do not forget to implement the limit switch conditions
  digitalWrite(aPinMotorY_Eng, LOW);
  digitalWrite(aPinMotorY_Dir, direction);
  for (u16 i = 0; i <= u16_steps; i++)
  {
    digitalWrite(aPinMotorY_Step, HIGH);
    delayMicroseconds(700);
    digitalWrite(aPinMotorY_Step, LOW);
    delayMicroseconds(700);
  }
}

void motorY_Until_Limit(bool direction){
  // Todo: do not forget to implement the limit switch conditions
  digitalWrite(aPinMotorY_Eng, LOW);
  digitalWrite(aPinMotorY_Dir, direction);
  while((direction && LS4) | (!direction && LS5))
  {
    digitalWrite(aPinMotorY_Step, HIGH);
    delayMicroseconds(700);
    digitalWrite(aPinMotorY_Step, LOW);
    delayMicroseconds(700);
    limitSwRead();
  }
  digitalWrite(aPinMotorY_Eng, HIGH);

}

void motorZ(u16 u16_steps, bool direction){
  // Todo: do not forget to implement the limit switch conditions
  digitalWrite(aPinMotorZ_Eng, LOW);
  digitalWrite(aPinMotorZ_Dir, !direction);
  for (u16 i = 0; i <= u16_steps; i++)
  {
    digitalWrite(aPinMotorZ_Step, HIGH);
    delayMicroseconds(700);
    digitalWrite(aPinMotorZ_Step, LOW);
    delayMicroseconds(700);
  }
}

void motorZ_Until_Limit(bool direction){
  // Todo: do not forget to implement the limit switch conditions
  digitalWrite(aPinMotorZ_Eng, LOW);
  digitalWrite(aPinMotorZ_Dir, direction);
  while((direction && LS7) | (!direction && LS6))
  {
    digitalWrite(aPinMotorZ_Step, HIGH);
    delayMicroseconds(700);
    digitalWrite(aPinMotorZ_Step, LOW);
    delayMicroseconds(700);
    limitSwRead();
  }
  digitalWrite(aPinMotorZ_Eng, HIGH);

}

void motorGripper(u16 u16_steps, bool direction){
  // Todo: do not forget to implement the limit switch conditions
  digitalWrite(aPinMotorGr_Eng, LOW);
  digitalWrite(aPinMotorGr_Dir, direction);
  for (u16 i = 0; i <= u16_steps; i++)
  {
    digitalWrite(aPinMotorGr_Step, HIGH);
    delayMicroseconds(1000);
    digitalWrite(aPinMotorGr_Step, LOW);
    delayMicroseconds(1000);
  }
  digitalWrite(aPinMotorGr_Eng, HIGH);
}
