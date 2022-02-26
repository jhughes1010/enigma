/**
   @file enigma.ino

   @mainpage The Enigma Machine

   @section description Description
   A modern day instance of an Enigma machine


   @section circuit Circuit
   - See github for PCB designs
   -

   @section libraries Libraries
   - Adafruit_RGBLCDShield.h
     - Supports I2C based LCD communication

   @section notes Notes
   - Comments are Doxygen compatible.

   @section todo TODO
   - Many non-class related functions need documentation

   @section author Author
   - Created by James Hughes on 02/21/2022.
   - Modified by James Hughes on 02/26/2022.

   Copyright (c) 2022 James Hughes.  All rights reserved.
*/

#include "rotor.h"
#include "reflector.h"
#include <Adafruit_RGBLCDShield.h>
#include <Adafruit_MCP23X17.h>


Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

//set the three rotors
Rotor fast(3, 22);
Rotor middle(2, 5);
Rotor slow(1, 17);

//set the reflector
Reflector reflector(2);

/**
   The standard Arduino setup function used for setup and configuration tasks.
*/
void setup()
{
  Serial.begin(115200);
  Serial.println("\nThe Enigma machine\n");
  lcd.begin(16, 2);
  LCDTitle();

}

/**
   The standard Arduino loop function used for repeating tasks.
*/
void loop()
{
  char buffer[32];
  int p = 0;
  char letter;

  Serial.println("\n\nWaiting for encryption/decryption traffic");
  while (Serial.available() == 0)
  {
  }
  String stringVariable = Serial.readString();
  stringVariable.trim();
  Serial.println(stringVariable);
  if (stringVariable == "reset")
  {
    fast.setPosition(1);
    middle.setPosition(1);
    slow.setPosition(1);
    LCDprintRotorPosition();
  }
  else
  {
    stringVariable.toCharArray(buffer, sizeof(buffer));
    while (strlen(buffer) > p)
    {
      letter = buffer[p];
      runEnigma( letter);
      p++;
    }
    LCDprintRotorPosition();

    //scan menu/utility buttons
    //scan keyboard
    //if buffer -> cipher
    //  lampboard update
    //refresh 7-segments
    //refresh LCD
  }
}
