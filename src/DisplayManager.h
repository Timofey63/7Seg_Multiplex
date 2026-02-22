#ifndef DISPLAY_MANAGER
#define DISPLAY_MANAGER

#include <Arduino.h>
#include <DisplayData.h>
#include "SegmentDisplay.h"
#include <SegmentFSM.h>

class DisplayManager
{
private:
    static const int dataPin;   
    static const int clockPin;
    static const int latchPin;
    static const byte digits[10];

    int displayCount = 3;     
    SegmentDisplay displays[3];
    DisplayData currentData;

    unsigned long previousOutputTime;
    const unsigned long outputInterval = 3;
    int activeDisplayIndex;
public:
    SegmentFSM fsm;
    DisplayManager();
    void shiftOutData(byte data);
    void begin();
    void setValue(DisplayData data);
    void update();
};

#endif