
/*=================================================================================================================*/
/*** Author : Amr Mostafa         (Amr_MAM)                                                                      ***/
/*** Title  : Pin mapping (pin information) & Global Pin Methods                                                 ***/
/*** Date   : 05Jul2022                                                                                          ***/
/*** Version: V06                                                                                                ***/
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

/* Functions ===================================================================================================== */
void setPinsConfiguration(){
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

#endif