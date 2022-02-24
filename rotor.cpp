#include "rotor.h"
#include "rotorDef.h"
#include <string.h>

Rotor::Rotor(int identifier, int advanceNotch)
{
  _position = 0;
  _advanceNotch = advanceNotch + 1;
  strcpy(_rotorArray, R3);
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
  position = letter - 65;
  position = (position + _position) % 26;
  letter = _rotorArray[position];
  return letter;
}
