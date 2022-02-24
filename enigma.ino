#include "rotor.h"
#include "reflector.h"
#include <Adafruit_RGBLCDShield.h>
#include <Adafruit_MCP23X17.h>


Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

//set the three rotors
Rotor fast(1, 3);
Rotor middle(2, 0);
Rotor slow(3, 0);

//set the reflector
Reflector reflector(1);

void setup()
{
  Serial.begin(9600);
  Serial.println("\n\n\nThe Enigma machine\n");

  lcd.begin(16, 2);
  lcd.setBacklight(0x01);


}

void loop()
{
  fast.increment();
  middle.increment(fast.getPosition(),fast.getAdvanceNotch());
  slow.increment(fast.getPosition(),fast.getAdvanceNotch(),middle.getPosition(),middle.getAdvanceNotch());


  //if (!fast.getPosition() & !middle.getPosition())
  {
    //printRotorPosition();
    LCDprintRotorPosition();
    Serial.println(millis());
  }
  delay(1000);
}

void printRotorPosition(void)
{
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
  sprintf(buffer2, "Type  :%02i-%02i-%02i", 3, 2, 1);
  lcd.setCursor(0, 0);
  lcd.print(buffer1);
  lcd.setCursor(0, 1);
  lcd.print(buffer2);
}
