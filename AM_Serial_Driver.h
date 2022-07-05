/*=================================================================================================================*/
/*** Author : Amr Mostafa      (Amr_MAM)                                                                         ***/
/*** Title  : this file contains the Serial listening and filtering functions                                    ***/
/*** Date   : 05Jul2022                                                                                          ***/
/*** Version: V06                                                                                                ***/
/*=================================================================================================================*/

#ifndef AM_Serial_Driver
#define AM_Serial_Driver

#include "AM_StepperDriver_Functions.h"
#include "AM_Sequence_Algorithm.h"

void listenToSerialCommand()
{
    u8 cmd = Serial.read();
    switch (cmd)
    {
    case 'A': // X-Axis Right
        Serial.println("Motor_X-Axis Starts to move right");
        // motorX(2000, true);
        motorX_Until_Limit(true);
        Serial.println("Motor_X-Axis Finished moving");
        break;

    case 'B': // X-Axis Left
        Serial.println("Motor_X-Axis Starts to move left");
        // motorX(2000, false);
        motorX_Until_Limit(false);
        Serial.println("Motor_X-Axis Finished moving");
        break;

    case 'C': // Y-Axis In
        Serial.println("Motor_Y-Axis Starts to move in");
        // motorY(2000, true);
        motorY_Until_Limit(true);
        Serial.println("Motor_Y-Axis Finished moving");
        break;

    case 'D': // Y-Axis Out
        Serial.println("Motor_Y-Axis Starts to move out");
        // motorY(2000, false);
        motorY_Until_Limit(false);
        Serial.println("Motor_Y-Axis Finished moving");
        break;

    case 'E': // Z-Axis Up
        Serial.println("Motor_Z-Axis Starts to move up");
        // motorZ(700, true);
        motorZ_Until_Limit(true);
        Serial.println("Motor_Z-Axis Finished moving");
        break;

    case 'F': // Z-Axis Down
        Serial.println("Motor_Z-Axis Starts to move down");
        // motorZ(700, false);
        motorZ_Until_Limit(false);
        Serial.println("Motor_Z-Axis Finished moving");
        break;

    case 'G': // GripperMotor open
        Serial.println("Motor_Gripper Starts to take off the bottle");
        motorGripper(100, false);
        Serial.println("Motor_Gripper Finished moving");
        break;

    case 'H': // GripperMotor holding
        Serial.println("Motor_Gripper Starts to hold the bottle");
        motorGripper(100, true);
        Serial.println("Motor_Gripper Finished moving");
        break;

    case 'I':
        Serial.print(LS1);
        Serial.print(' ');
        Serial.print(LS2);
        Serial.print(' ');
        Serial.print(LS3);
        Serial.print(' ');
        Serial.print(LS4);
        Serial.print(' ');
        Serial.print(LS5);
        Serial.print(' ');
        Serial.print(LS6);
        Serial.print(' ');
        Serial.println(LS7);
        break;

    case 29:  // Check X-axis mismatch
        check_X_mismatch();
        break;

    case 30:  // Go Home
        goHome();
        break;

    case 31:  // put intact bottle (packing)
        putIntactBottle();
        break;

    case 32:  // put faulty bottle (throw out)
        putFaultyBottle();
        break;

    default:
        break;
    }
}

#endif

/* Commands litters: 
A
B
C
D
E
F
G
H
I



 
*/