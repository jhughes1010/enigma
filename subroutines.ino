
//-------------------------
//Subroutines
//-------------------------
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

void runEnigma(char letter)
{
  char cipher;
  incrementRotors();
  printRotorPosition();
  Serial.println("");
  Serial.println(letter);
  LCDprintRotorPosition();
  cipher = substitution(letter);
  Serial.println(cipher);
}

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
