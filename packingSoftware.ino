
/*=================================================================================================================*/
/*** Author : Amr Mostafa      (Amr_MAM)                                                                         ***/
/*** Title  : Main program file for the controller of the Packing System                                         ***/
/*** Date   : 14Mar2022                                                                                          ***/
/*** Version: V03                                                                                                ***/
/*=================================================================================================================*/

#include "AM_PIN_INTERFACE.h"

void setup()
{
  Serial.begin(9600);

  /*==============[Settings of Pins]===============*/
  AmSetPin_As_Output(aPinMotorX_Eng);
  AmSetPin_As_Output(aPinMotorX_Dir);
  AmSetPin_As_Output(aPinMotorX_Step);

  AmSetPin_As_Output(aPinMotorY_Eng);
  AmSetPin_As_Output(aPinMotorY_Dir);
  AmSetPin_As_Output(aPinMotorY_Step);

  AmSetPin_As_Output(aPinMotorZ_Eng);
  AmSetPin_As_Output(aPinMotorZ_Dir);
  AmSetPin_As_Output(aPinMotorZ_Step);

  AmSetPin_As_Output(aPinMotorGr_Eng);
  AmSetPin_As_Output(aPinMotorGr_Dir);
  AmSetPin_As_Output(aPinMotorGr_Step);
  
  AmSetPin_As_InputPullUp(aPinLS1);
  AmSetPin_As_InputPullUp(aPinLS2);
  AmSetPin_As_InputPullUp(aPinLS3);
  AmSetPin_As_InputPullUp(aPinLS4);
  AmSetPin_As_InputPullUp(aPinLS5);
  AmSetPin_As_InputPullUp(aPinLS6);
  AmSetPin_As_InputPullUp(aPinLS7);
}

void loop()
{
  listenToSerialCommand();
  delay(100);
}

void listenToSerialCommand(){
  u8 cmd =  Serial.read();
  switch (cmd)
  {
  case 'A':  // X-Axis Right
    Serial.println("Motor_X-Axis Starts to move right");
    motorX(2000, true);
    Serial.println("Motor_X-Axis Finished moving");
    break;  

  case 'B':  // X-Axis Left
    Serial.println("Motor_X-Axis Starts to move left");
    motorX(2000, false);
    Serial.println("Motor_X-Axis Finished moving");
    break;   

  case 'C':  // Y-Axis In
    Serial.println("Motor_Y-Axis Starts to move in");
    motorY(2000, true);
    Serial.println("Motor_Y-Axis Finished moving");
    break;  

  case 'D':  // Y-Axis Out
    Serial.println("Motor_Y-Axis Starts to move out");
    motorY(2000, false);
    Serial.println("Motor_Y-Axis Finished moving");
    break;      

  case 'E':  // Z-Axis Up
    Serial.println("Motor_Z-Axis Starts to move up");
    motorZ(700, true);
    Serial.println("Motor_Z-Axis Finished moving");
    break;  

  case 'F':  // Z-Axis Down
    Serial.println("Motor_Z-Axis Starts to move down");
    motorZ(700, false);
    Serial.println("Motor_Z-Axis Finished moving");
    break;      

  case 'G':  // GripperMotor holding
    Serial.println("Motor_Gripper Starts to hold the bottle");
    motorGripper(300, true);
    Serial.println("Motor_Gripper Finished moving");
    break;  

  case 'H':  // GripperMotor open
    Serial.println("Motor_Gripper Starts to take off the bottle");
    motorGripper(300, false);
    Serial.println("Motor_Gripper Finished moving");
    break;  

 default:
    break;
  }
}

void motorX(u16 u16_steps, bool direction){
  // Todo: do not forget to implement the limit switch conditions
  AmClrPin(aPinMotorX_Eng);
  AmSetPinState(aPinMotorX_Dir, direction);
  for (u16 i = 0; i <= u16_steps; i++)
  {
    AmSetPin(aPinMotorX_Step);
    delayMicroseconds(700);
    AmClrPin(aPinMotorX_Step);
    delayMicroseconds(700);
  }
}

void motorY(u16 u16_steps, bool direction){
  // Todo: do not forget to implement the limit switch conditions
  AmClrPin(aPinMotorY_Eng);
  AmSetPinState(aPinMotorY_Dir, direction);
  for (u16 i = 0; i <= u16_steps; i++)
  {
    AmSetPin(aPinMotorY_Step);
    delayMicroseconds(1000);
    AmClrPin(aPinMotorY_Step);
    delayMicroseconds(1000);
  }
}

void motorZ(u16 u16_steps, bool direction){
  // Todo: do not forget to implement the limit switch conditions
  AmClrPin(aPinMotorZ_Eng);
  AmSetPinState(aPinMotorZ_Dir, !direction);
  for (u16 i = 0; i <= u16_steps; i++)
  {
    AmSetPin(aPinMotorZ_Step);
    delayMicroseconds(1000);
    AmClrPin(aPinMotorZ_Step);
    delayMicroseconds(1000);
  }
}

void motorGripper(u16 u16_steps, bool direction){
  // Todo: do not forget to implement the limit switch conditions
  AmClrPin(aPinMotorGr_Eng);
  AmSetPinState(aPinMotorGr_Dir, direction);
  for (u16 i = 0; i <= u16_steps; i++)
  {
    AmSetPin(aPinMotorGr_Step);
    delayMicroseconds(1000);
    AmClrPin(aPinMotorGr_Step);
    delayMicroseconds(1000);
  }
}
