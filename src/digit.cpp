// digit.cpp
#include "digit.h"

const int Digit::dataPin = 2;
const int Digit::clockPin = 3;
const int Digit::latchPin = 4;

const byte Digit::digits[10] = {
    B11111100, // 0
    B01100000, // 1
    B11011010, // 2
    B11110010, // 3
    B01100110, // 4
    B10110110, // 5
    B10111110, // 6
    B11100000, // 7
    B11111110, // 8
    B11110110  // 9
};

Digit::Digit(int outputPin)
{
    _outputPin = outputPin;
}

void Digit::allSetup()
{
    // Настройка пинов для 74HC595
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(latchPin, OUTPUT);
}

void Digit::begin()
{
    pinMode(_outputPin, OUTPUT);
    off();
}

void Digit::on()
{
    digitalWrite(_outputPin, LOW); // Включить (LOW = активно для общего катода)
}

void Digit::off()
{
    digitalWrite(_outputPin, HIGH); // Выключить
}

void Digit::display()
{
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, digits[_currentValue]);
    digitalWrite(latchPin, HIGH);
}

void Digit::display(int num)
{
    if (num < 0 || num > 9) return;

    _currentValue = num;
    display();
}