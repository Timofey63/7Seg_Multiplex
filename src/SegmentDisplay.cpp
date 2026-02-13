#include "SegmentDisplay.h"

SegmentDisplay::SegmentDisplay(int outputPin)
{
    _outputPin = outputPin;
}

SegmentDisplay::SegmentDisplay()
{
    _outputPin = -1; //error
}

void SegmentDisplay::begin()
{
    pinMode(_outputPin, OUTPUT);
    off();
}

void SegmentDisplay::on()
{
    digitalWrite(_outputPin, LOW); // Включить (LOW = активно для общего катода)
}

void SegmentDisplay::off()
{
    digitalWrite(_outputPin, HIGH); // Выключить
}