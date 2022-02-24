#include "rotor.h"

Rotor::Rotor(int identifier, int advanceNotch)
{
  _position = 0;
  _advanceNotch = advanceNotch;
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
  return _position;
}

int Rotor::getAdvanceNotch(void)
{
  return _advanceNotch;
}
