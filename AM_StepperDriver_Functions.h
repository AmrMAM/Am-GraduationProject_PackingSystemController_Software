/*=================================================================================================================*/
/*** Author : Amr Mostafa      (Amr_MAM)                                                                         ***/
/*** Title  : this file contains the motion functions related to the stepper drivers                             ***/
/*** Date   : 06Jul2022                                                                                          ***/
/*** Version: V07                                                                                                ***/
/*=================================================================================================================*/

#include "AM_Include_All.h"

#ifndef AM_StepperDriver_Functions
#define AM_StepperDriver_Functions

#include "AM_LimitSwitches_Driver.h"

/// deprecated with the [motorX_Until_Limit] function used instead
void motorX(u16 u16_steps, bool direction){
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

/// deprecated with the [motorY_Until_Limit] function used instead
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

/// deprecated with the [motorZ_Until_Limit] function used instead
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
  digitalWrite(aPinMotorZ_Eng, LOW);
  digitalWrite(aPinMotorZ_Dir, direction);
  while((direction && LS7) | (!direction && LS6))
  {
    digitalWrite(aPinMotorZ_Step, HIGH);
    delayMicroseconds(700);
    digitalWrite(aPinMotorZ_Step, LOW);
    delayMicroseconds(700);
    limitSwRead();
    digitalWrite(aPinMotorZ_Dir, direction);
  }
  digitalWrite(aPinMotorZ_Eng, HIGH);

}

void motorGripper(u16 u16_steps, bool direction){
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



#endif