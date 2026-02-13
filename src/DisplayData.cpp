#include <DisplayData.h>

const byte DisplayData::segmentCodes[10] = {
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
DisplayData::DisplayData()
{
    _value = -100; //error
}
DisplayData::DisplayData(int value, bool isCelsius)
{
    _isCelsius = isCelsius;
    if(isCelsius) _value = constrain(value, -99, 99);
    else _value = constrain(value, 0, 99);
}
byte DisplayData::get(int index)
{
    int absValue = abs(_value);
    switch (index)
    {
    case 0:
        return segmentCodes[absValue / 10];
    case 1:
        return segmentCodes[absValue % 10];
    case 2:
        // implementation later
        return 0;
    default:
        return 0;
    }
}