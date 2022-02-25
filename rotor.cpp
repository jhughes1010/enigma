#include "rotor.h"
#include "rotorDef.h"
#include <string.h>
#include <Arduino.h>

Rotor::Rotor(int identifier, int advanceNotch)
{
  _position = 0;
  _advanceNotch = advanceNotch + 1;
  switch (identifier)
  {
    case 1:
      strcpy(_rotorArray, ROTOR1);
      strcpy(_rotorArray, ROTOR1_PT);
      break;
    case 2:
      strcpy(_rotorArray, ROTOR2);
      strcpy(_rotorArray, ROTOR1_PT);
      break;
    case 3:
      strcpy(_rotorArray, ROTOR3);
      //strcpy(_rotorArray, ROTOR1_PT);
      break;
    case 4:
      strcpy(_rotorArray, ROTOR4);
      strcpy(_rotorArray, ROTOR1_PT);
      break;
    case 5:
      strcpy(_rotorArray, ROTOR5);
      strcpy(_rotorArray, ROTOR1_PT);
      break;
    default:
      strcpy(_rotorArray, ROTOR1);
      strcpy(_rotorArray, ROTOR1_PT);
  }
}

int Rotor::rightSide(int character)
{

}

int Rotor::leftSide(int character)
{

}

void Rotor::increment(void)
{
  _position++;
  _position %= 26;
}

void Rotor::increment(int RotorFastPosition, int notchRotorFast)
{
  if (RotorFastPosition == notchRotorFast)
  {
    increment();
  }
}

void Rotor::increment(int RotorFastPosition, int notchRotorFast, int RotorMiddlePosition, int notchRotorMiddle)
{
  if (RotorFastPosition == notchRotorFast & RotorMiddlePosition == notchRotorMiddle)
  {
    increment();
  }
}

int Rotor::getPosition(void)
{
  return _position + 1;
}

void Rotor::setPosition(int position)
{
  if (position <= 1 & position >= 26)
  {
    _position = position - 1;
  }
}

int Rotor::getAdvanceNotch(void)
{
  return _advanceNotch;
}


char Rotor::rl(char letter)
{
  int position;
  Serial.print("Rotor In:");
  Serial.print(letter);
  position = letter - 65;
  position = (position + _position) % 26;
  //Serial.println(position);
  letter = _rotorArray[position];

  Serial.print(" - Rotor Out:");
  Serial.println(letter);
  return letter;
}

char Rotor::lr(char letter)
{
  int position = 0;
  int index = 0;
  Serial.print("Rotor In:");
  Serial.print(letter);

  position = letter - 65;
  Serial.println(position);
  position = (position + _position) % 26;
  Serial.println(position);
  /*
  for (index = 0; index < 26; index++)
  {
    if (_rotorArray[index] == letter)
    {
      letter = index + 65;
      //Serial.println(index);
    }
  }
  */
  letter = _rotorArray[position];
  //Serial.println(position);
  //letter = _rotorArray[position];
  Serial.print(" - Rotor Out:");
  Serial.println(letter);
  return letter;
}
