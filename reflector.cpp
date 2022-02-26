#include "reflector.h"
#include "rotorDef.h"
#include <string.h>
#include <Arduino.h>


Reflector::Reflector(int identifier)
{
  switch (identifier)
  {
    case 1:
      strcpy(_reflectorArray, UKW_A);
      break;
    case 2:
      strcpy(_reflectorArray, UKW_B);
      break;
    case 3:
      strcpy(_reflectorArray, UKW_C);
      break;
    default:
      strcpy(_reflectorArray, UKW_A);
  }
}

char Reflector::reflect(char letter)
{
  int position;
  //Serial.print("Reflector In:");
  //Serial.print(letter);
  position = letter - 65;
  //position = % 26;
  letter = _reflectorArray[position];

  //Serial.print(" - Reflector Out:");
  //Serial.println(letter);
  return letter;
}
