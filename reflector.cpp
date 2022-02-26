 #include "reflector.h"
#include "rotorDef.h"
#include <string.h>
#include <Arduino.h>

/**************************************************************************/
/*!
    @brief  Reflector enstaniation. Initializes the reflector based on identifier
            passed.

            There are 3 supported identifiers.
    @param    identifier
              3 reflector models are supported. These are accessed via identifier values 1-3
              
    @return True if the event read was successful, otherwise false.
*/
/**************************************************************************/
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

/**************************************************************************/
/*!
    @brief  Takes input character and translates it to the reflected output character
    @param    letter
              ASCII character input you wish to be run through the assigned 
              reflector.
    @return reflected ASCII character
*/
/**************************************************************************/
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
