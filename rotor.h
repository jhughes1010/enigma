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
    /// position used for current wiring path
    int _position;
    /// position on rotor when next linked rotor will be advanced (when this number is passed)
    int _advanceNotch;
    /// array that contains substitution mapping for rotor
    char _rotorArray[32];
};
