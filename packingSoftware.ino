
/*=================================================================================================================*/
/*** Author : Amr Mostafa      (Amr_MAM)                                                                         ***/
/*** Title  : Main program file for the controller of the Packing System                                         ***/
/*** Date   : 22Feb2022                                                                                          ***/
/*** Version: V01                                                                                                ***/
/*=================================================================================================================*/

#include "AM_PIN_INTERFACE.h"

bool dir = HIGH;

void setup()
{
  Serial.begin(9600);
  AmSetPin_As_Output(aPinMotorY_Dir);
  AmSetPin_As_Output(aPinMotorY_Step);
  AmSetPin_As_Output(aPinMotorY_Eng);

  AmSetPin_As_Output(13);

  AmSetPin_As_InputPullUp(aPinLS1);
  AmSetPin_As_InputPullUp(aPinLS2);
  AmSetPin_As_InputPullUp(aPinLS3);
  AmSetPin_As_InputPullUp(aPinLS4);
  AmSetPin_As_InputPullUp(aPinLS5);
  AmSetPin_As_InputPullUp(aPinLS6);
  AmSetPin_As_InputPullUp(aPinLS7);
}

void loop()
{
  testServer();
  // AmClrPin(aPinMotorY_Eng);
  // AmSetPinState(aPinMotorY_Dir, dir);
  // for (int i = 0; i <= 800; i++)
  // {
  //   AmSetPin(aPinMotorY_Step);
  //   delayMicroseconds(500);
  //   AmClrPin(aPinMotorY_Step);
  //   delayMicroseconds(500);
  // }

  // dir = !dir;
  delay(100);
}

void testLS(){
  if (!AmGetPinState(aPinLS1))         Serial.println(1);
  else if(!AmGetPinState(aPinLS2))     Serial.println(1);  
  else if(!AmGetPinState(aPinLS3))     Serial.println(1);  
  else if(!AmGetPinState(aPinLS4))     Serial.println(1);
  else if(!AmGetPinState(aPinLS5))     Serial.println(1);
  else if(!AmGetPinState(aPinLS6))     Serial.println(1);
  else if(!AmGetPinState(aPinLS7))     Serial.println(1);
  else                                 Serial.println(6);
}
void testServer(){
  u8 cmd =  Serial.read();
  switch (cmd)
  {
  case 'A':
    AmSetPin(aPinMotorY_Dir);
    AmClrPin(aPinMotorY_Eng);
    Serial.println("LED is ON");
    break;  
  case 'B':
    AmClrPin(aPinMotorY_Dir);
    AmSetPin(aPinMotorY_Eng); 
    Serial.println("LED is OFF");
    break;  
  default:
    break;
  }
}