class Rotor
{
  public:
    Rotor(int identifier);
    void increment(void);
    void increment(int linkedRotor1);
    void increment(int linkedRotor1, int linkedRotor2);
    int rightSide(int character);
    int leftSide(int character);
    int getPosition(void);



  private:
    int _position;

};
