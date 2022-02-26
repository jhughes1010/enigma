
//-------------------------
//Subroutines
//-------------------------

/**
 * The standard Arduino loop function used for repeating tasks.
 */
void printRotorPosition(void)
{
  Serial.print("Rotors: ");
  Serial.print(slow.getPosition());
  Serial.print(" - ");
  Serial.print(middle.getPosition());
  Serial.print(" - ");
  Serial.println(fast.getPosition());
}

/**
 * The standard Arduino loop function used for repeating tasks.
 */
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

/**
 * The standard Arduino loop function used for repeating tasks.
 */
void incrementRotors()
{
  fast.increment();
  middle.increment(fast.getPosition(), fast.getAdvanceNotch());
  slow.increment(fast.getPosition(), fast.getAdvanceNotch(), middle.getPosition(), middle.getAdvanceNotch());
}

/**
 * This function taskes the passed ASCII character:
 *  - converts to uppercase ASCII
 *  - runs character through 3 defined rotors
 *  - runs character through the reflector
 *  - runs character back through 3 defined rotors
 */
char substitution(char letter)
{
  char cipher;
  letter = toupper(letter);
  //plugboard call
  cipher = fast.rightLeft(letter);
  cipher = middle.rightLeft(cipher);
  cipher = slow.rightLeft(cipher);
  cipher = reflector.reflect(cipher);
  cipher = slow.leftRight(cipher);
  cipher = middle.leftRight(cipher);
  cipher = fast.leftRight(cipher);
  //plugboard call
  return cipher;
}

/**
 * Top level cipher engine call. This will:
 * - Increment rotors
 * - Display rotor values to LCD
 * - Run the substitution() to encrypt/decrypt the passed character
 */
void runEnigma(char letter)
{
  char cipher;
  incrementRotors();
  //printRotorPosition();
  //Serial.println("");
  //Serial.println(letter);
  //LCDprintRotorPosition();
  cipher = substitution(letter);
  Serial.print(cipher);
}

/**
 * Project title to LCD for 2sec
 */
void LCDTitle(void)
{
  lcd.setBacklight(0x01);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enigma Machine");
  lcd.setCursor(0, 1);
  lcd.print("2022");
  delay(2000);
}
