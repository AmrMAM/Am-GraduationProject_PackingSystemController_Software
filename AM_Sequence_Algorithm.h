/*=================================================================================================================*/
/*** Author : Amr Mostafa      (Amr_MAM)                                                                         ***/
/*** Title  : this file contains the motion Algorithm functions                                                  ***/
/*** Date   : 06Jul2022                                                                                          ***/
/*** Version: V07                                                                                                ***/
/*=================================================================================================================*/

#include "AM_Include_All.h"

#ifndef AM_Sequence_Algorithm
#define AM_Sequence_Algorithm

#include "AM_StepperDriver_Functions.h"
#include "AM_LimitSwitches_Driver.h"

void goHome(bool openGripper = true){

    if (openGripper)
    {
        Serial.println(46);     // Gripper indication (Open)
        motorGripper(150, true);   // open Gripper   
    }

    Serial.println(45);     // Moving indication (Z-) 
    motorZ_Until_Limit(false);  // Z up (Z-)

    Serial.println(40);     // Moving indication (X-) 
    motorX_Until_Limit(false);   // X -

    Serial.println(42);     // Moving indication (Y-) 
    motorY_Until_Limit(false);   // Y - 

    Serial.println(49);     // Ready for the new command
}

void putFaultyBottle(){
    Serial.println(44);     // Moving indication (Z+) 
    motorZ_Until_Limit(true);  // Z down (Z+)

    Serial.println(47);     // Gripper indication (Holding)
    motorGripper(150, false);   // close Gripper

    Serial.println(45);     // Moving indication (Z-) 
    motorZ_Until_Limit(false);  // Z up (Z-)

    Serial.println(41);     // Moving indication (X+) 
    motorX_Until_Limit(true);   // X +

    Serial.println(43);     // Moving indication (Y+) 
    motorY_Until_Limit(true);   // Y + 

    Serial.println(44);     // Moving indication (Z+) 
    motorZ_Until_Limit(true);  // Z down (Z+)

    Serial.println(46);     // Gripper indication (Open)
    motorGripper(150, true);   // open Gripper

    Serial.println(48);     // Indication (Process is finshed)

    goHome(false);   // to go home position
}

void putIntactBottle(){
    Serial.println(44);     // Moving indication (Z+) 
    motorZ_Until_Limit(true);  // Z down (Z+)

    Serial.println(47);     // Gripper indication (Holding)
    motorGripper(150, false);   // close Gripper

    Serial.println(45);     // Moving indication (Z-) 
    motorZ_Until_Limit(false);  // Z up (Z-)

    Serial.println(41);     // Moving indication (X+) 
    motorX_Until_Limit(true);   // X +

    Serial.println(44);     // Moving indication (Z+) 
    motorZ_Until_Limit(true);  // Z down (Z+)

    Serial.println(46);     // Gripper indication (Open)
    motorGripper(150, true);   // open Gripper

    Serial.println(48);     // Indication (Process is finshed)

    goHome(false);   // to go home position
}

void check_X_mismatch(){
    Serial.println(40);     // Moving indication (X-) 
    motorX_Until_Limit(false);   // X -

    limitSwRead();

    if (!(LS2 | LS3))
    {
        Serial.println(50);     // No mismatch in X
    }
    else
    {
        Serial.println(51);     // There is mismatch in X-axis try to solve manually before we start
    }
    
}
#endif