#include "rotor.h"
#include "reflector.h"
//#include "rotorDef.h"
#include <Adafruit_RGBLCDShield.h>
#include <Adafruit_MCP23X17.h>


Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

//set the three rotors
Rotor fast(3, 22);
Rotor middle(2, 5);
Rotor slow(1, 17);

//set the reflector
Reflector reflector(1);

void setup()
{
  Serial.begin(115200);
  Serial.println("\n\n\nThe Enigma machine\n");

  lcd.begin(16, 2);
  lcd.setBacklight(0x01);


}

void loop()
{
  char buffer[32];
  int p = 0;
  char letter, cipher;
  strcpy(buffer, "enigmaaaaaaaa");

  while (strlen(buffer) > p)
  {
    letter = buffer[p];
    Serial.println(letter);
    incrementRotors();
    printRotorPosition();
    LCDprintRotorPosition();
    cipher = substitution(letter);
    Serial.println(cipher);
    p++;
  }

  while (1)
  {

  }
}

void printRotorPosition(void)
{
  Serial.print("Rotors: ");
  Serial.print(slow.getPosition());
  Serial.print(" - ");
  Serial.print(middle.getPosition());
  Serial.print(" - ");
  Serial.println(fast.getPosition());
}

void LCDprintRotorPosition(void)
{
  char buffer1[24], buffer2[24];
  //lcd.clear();
  sprintf(buffer1, "Rotors:%02i-%02i-%02i", slow.getPosition(), middle.getPosition(), fast.getPosition());
  sprintf(buffer2, "Type  :%02i-%02i-%02i", 1, 2, 3);
  lcd.setCursor(0, 0);
  lcd.print(buffer1);
  lcd.setCursor(0, 1);
  lcd.print(buffer2);
}

void incrementRotors()
{
  fast.increment();
  middle.increment(fast.getPosition(), fast.getAdvanceNotch());
  slow.increment(fast.getPosition(), fast.getAdvanceNotch(), middle.getPosition(), middle.getAdvanceNotch());
}


char substitution(char letter)
{
  char cipher;
  letter = toupper(letter);
  Serial.println(letter, DEC);
  cipher = fast.rl(letter);
  return cipher;
}
