class led
{
private:
    int pinNumber;
public:
    led(int pinNumber);
    void switchLED_On();
    void switchLED_Off();
    ~led();
};