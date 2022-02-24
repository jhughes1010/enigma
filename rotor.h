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



  private:
    int _position;
    //int _rolloverNotch;
    int _advanceNotch;

};
