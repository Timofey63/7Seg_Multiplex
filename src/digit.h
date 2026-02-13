// digit.h
#ifndef DIGIT_H
#define DIGIT_H

#include <Arduino.h>

class Digit
{
private:
    static const int dataPin;   
    static const int clockPin;
    static const int latchPin;
    static const byte digits[10];

    int _outputPin;
    int _currentValue;

public:
    Digit(int outputPin);
    
    static void allSetup();
    void begin();
    void on();
    void off();
    void display();
    void display(int num);
};

#endif