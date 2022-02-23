#include "rotor.h"

Rotor::Rotor(int identifier)
{
  _position = 1;
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

void Rotor::increment(int linkedRotor1)
{
  if (linkedRotor1 == 0)
  {
    _position++;
    _position %= 26;
  }
}

void Rotor::increment(int linkedRotor1, int linkedRotor2)
{
  if (linkedRotor1 == 0 & linkedRotor2 == 0)
  {
    _position++;
    _position %= 26;
  }
}

int Rotor::getPosition(void)
{
  return _position;
}
