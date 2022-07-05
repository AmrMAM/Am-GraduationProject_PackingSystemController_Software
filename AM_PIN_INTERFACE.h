
/*=================================================================================================================*/
/*** Author : Amr Mostafa         (Amr_MAM)                                                                      ***/
/*** Title  : Pin mapping (pin information) & Global Pin Methods                                                 ***/
/*** Date   : 05Jul2022                                                                                          ***/
/*** Version: V03                                                                                                ***/
/*=================================================================================================================*/

#ifndef AM_PIN_INTERFACE
#define AM_PIN_INTERFACE

#include "Arduino.h"

/* Data Types ==================================================================================================== */
typedef unsigned char                                  u8;
typedef unsigned short int                             u16;
typedef unsigned long int                              u32;
typedef unsigned long long int                         u64;

/* Code file inclusion =========================================================================================== */
#include "AM_PIN_CONFIG.h"

/* Pin Global Functions ========================================================================================== */
#define AmRung(Condition, u8Var)                       if(Condition) u8Var=HIGH;    else u8Var=LOW;

#endif