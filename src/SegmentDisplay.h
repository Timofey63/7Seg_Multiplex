#ifndef DIGIT_H
#define DIGIT_H

#include <Arduino.h>
#include <SegmentFSM.h>

class SegmentDisplay
{
private:
    int _outputPin;
    int _currentValue;

public:
    SegmentFSM fsm;
    SegmentDisplay();//error
    SegmentDisplay(int outputPin);
    
    void begin();
    void on();
    void off();
    void display();
};

#endif