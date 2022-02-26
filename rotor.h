class Rotor
{
  public:


    Rotor(int identifier, int advanceNotch);
    void increment(void);
    void increment(int RotorFastPosition, int notchRotorFast);
    void increment(int RotorFastPosition, int notchRotorFast, int RotorMiddlePosition, int notchRotorMiddle);
    
    void setPosition(int position);
    int getPosition(void);
    int getAdvanceNotch(void);

    char rightLeft( char letter);
    char leftRight(char letter);



  private:
    int _position;
    //int _rolloverNotch;
    int _advanceNotch;
    char _rotorArray[32];

};
