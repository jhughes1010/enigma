class Rotor
{
  public:


    Rotor(int identifier, int advanceNotch);
    void increment(void);
    void increment(int RotorFastPosition, int notchRotorFast);
    void increment(int RotorFastPosition, int notchRotorFast, int RotorMiddlePosition, int notchRotorMiddle);
    int rightSide(int character);
    int leftSide(int character);
    int getPosition(void);
    int getAdvanceNotch(void);
    void setPosition(int position);

    char rl( char letter);



  private:
    int _position;
    //int _rolloverNotch;
    int _advanceNotch;
    char _rotorArray[32];

};
