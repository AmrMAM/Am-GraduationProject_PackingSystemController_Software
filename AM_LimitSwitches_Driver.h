/*=================================================================================================================*/
/*** Author : Amr Mostafa      (Amr_MAM)                                                                         ***/
/*** Title  : this file contains the Limit Switches Driver                                                       ***/
/*** Date   : 06Jul2022                                                                                          ***/
/*** Version: V07                                                                                                ***/
/*=================================================================================================================*/

#include "AM_Include_All.h"
#include "AM_PIN_INTERFACE.h"

#ifndef AM_LimitSwitches_Driver
#define AM_LimitSwitches_Driver


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