
/*=================================================================================================================*/
/*** Author : Amr Mostafa      (Amr_MAM)                                                                         ***/
/*** Title  : Main program file for the controller of the Packing System                                         ***/
/*** Date   : 06Jul2022                                                                                          ***/
/*** Version: V07                                                                                                ***/
/*=================================================================================================================*/

#include "Arduino.h"
#include "AM_Include_All.h"

void setup()
{
  Serial.begin(9600);
  /*==============[Settings of Pins]===============*/
  setPinsConfiguration();
}

void loop()
{
  listenToSerialCommand();
  limitSwRead();
  delay(100);
}
