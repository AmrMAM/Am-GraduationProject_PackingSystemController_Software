
/*=================================================================================================================*/
/*** Author : Amr Mostafa         (Amr_MAM)                                                                      ***/
/*** Title  : Pin mapping (pin information) & Global Pin Methods                                                 ***/
/*** Date   : 22Feb2022                                                                                          ***/
/*** Version: V01                                                                                                ***/
/*=================================================================================================================*/

#ifndef AM_PIN_INTERFACE
#define AM_PIN_INTERFACE

#include "Arduino.h"

/* Data Types ==================================================================================================== */
typedef unsigned char                                  u8;
typedef unsigned short int                             u16;
typedef unsigned long int                              u32;
typedef unsigned long long int                         u64;

/* Pin Data ====================================================================================================== */
#include "AM_PIN_CONFIG.h"

/* Pin Global Functions ========================================================================================== */
#define AmSetPin(pin)                                  digitalWrite(pin, HIGH)
#define AmClrPin(pin)                                  digitalWrite(pin, LOW)
#define AmSetPinState(pin, state)                      digitalWrite(pin, state)
#define AmSetPinValue(pin, Value)                      analogWrite(pin, value)

#define AmGetPinState(pin)                             (bool)digitalRead(pin)
#define AmGetPinValue(pin)                             (int)analogRead(pin)

#define AmSetPin_As_InputPullUp(pin)                   pinMode(pin, INPUT_PULLUP)
#define AmSetPin_As_Input(pin)                         pinMode(pin, INPUT)
#define AmSetPin_As_Output(pin)                        pinMode(pin, OUTPUT)

#define AmRung(Condition, u8Var)                       if(Condition) u8Var=HIGH;    else u8Var=LOW;

#endif