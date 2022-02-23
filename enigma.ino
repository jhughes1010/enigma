#include "rotor.h"
#include "reflector.h"
#include <Adafruit_RGBLCDShield.h>
#include <Adafruit_MCP23X17.h>


Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

//set the three rotors
Rotor fast(1);
Rotor middle(2);
Rotor slow(3);

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
  middle.increment(fast.getPosition());
  slow.increment(middle.getPosition(), fast.getPosition());


  //if (!fast.getPosition() & !middle.getPosition())
  {
    printRotorPosition();
    LCDprintRotorPosition();
    Serial.println(millis());
  }
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
  //lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(slow.getPosition());
  lcd.print(" - ");
  lcd.print(middle.getPosition());
  lcd.print(" - ");
  lcd.print(fast.getPosition());
}
