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

const byte DisplayData::symbolCode[3] = {
    B01000100, //+ градус
    B11000100, //- градус
    B01100000 //процент
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
    bool isNegative = _value < 0;
    switch (index)
    {
    case 0:
        if(absValue / 10 == 0)
        {
            if(isNegative) return 2;
            else return 0;
        }
        return segmentCodes[absValue / 10];
    case 1:
        return segmentCodes[absValue % 10];
    case 2:
        // implementation later
        if(_isCelsius)
        {
            if(isNegative)
            {
                if(absValue / 10 == 0) return symbolCode[0];
                return symbolCode[1];
            }
            else return symbolCode[0];
        }
        else 
        {
            return symbolCode[2];
        }
        return 0;
    default:
        return 0;
    }
}