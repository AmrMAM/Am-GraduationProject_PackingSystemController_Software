
/*=================================================================================================================*/
/*** Author : Amr Mostafa      (Amr_MAM)                                                                         ***/
/*** Title  : Main program file for the controller of the Packing System                                         ***/
/*** Date   : 05Jul2022                                                                                          ***/
/*** Version: V06                                                                                                ***/
/*=================================================================================================================*/

#include "AM_PIN_INTERFACE.h"
#include "AM_Serial_Driver.h" 

void setup()
{
  Serial.begin(9600);
  /*==============[Settings of Pins]===============*/
  setPinsConfiguration();
}

void loop()
{
  listenToSerialCommand();
  delay(100);
}

