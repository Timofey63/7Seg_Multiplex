#ifndef DISPLAY_DATA
#define DISPLAY_DATA

#include <Arduino.h>

struct DisplayData
{
    int _value;
    bool _isCelsius;

    static const byte segmentCodes[10];
    static const byte symbolCode[3];

    DisplayData();//error
    DisplayData(int value, bool isCelsius);
    byte get(int index);
};

#endif