/*=================================================================================================================*/
/*** Author : Amr Mostafa      (Amr_MAM)                                                                         ***/
/*** Title  : this file contains the Limit Switches Driver                                                       ***/
/*** Date   : 05Jul2022                                                                                          ***/
/*** Version: V06                                                                                                ***/
/*=================================================================================================================*/

#ifndef AM_LimitSwitches_Driver
#define AM_LimitSwitches_Driver

#include "AM_PIN_INTERFACE.h"

int LS1;
int LS2;
int LS3;
int LS4;
int LS5;
int LS6;
int LS7;

void limitSwRead()
{
    LS1 = digitalRead(aPinLS1);
    LS2 = digitalRead(aPinLS2);
    LS3 = digitalRead(aPinLS3);
    LS4 = digitalRead(aPinLS4);
    LS5 = digitalRead(aPinLS5);
    LS6 = digitalRead(aPinLS6);
    LS7 = digitalRead(aPinLS7);
}

#endif