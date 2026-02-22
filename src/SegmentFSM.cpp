#include "SegmentFSM.h"

const byte SegmentFSM::stateCode[6] = {
    B11111111,
    B01111111,
    B00111011,
    B00111001,
    B00010001,
    B00000001
};

byte SegmentFSM::getMask()
{
    switch (state)
    {
    case IDLE:
        return stateCode[0];
        break;
    case FADE_OUT:
        return stateCode[step];
        break;
    case FADE_IN:
        return stateCode[5 - step];
        break;
    default:
        break;
    }
    return stateCode[0];
}

void SegmentFSM::setOnDisplayOffCallback(void (*callback)())
{
    onDisplayOffCallback = callback;
}

void SegmentFSM::start()
{
    state = FADE_OUT;
    step = 0;
    timer = millis();
    dataSwitched = false;
}

SegmentFSM::SegmentFSM()
{
    stepTime = 100;
    step = 0;
}

void SegmentFSM::update()
{
    if (state == IDLE) return;
    unsigned long now = millis();
    if(now - timer < stepTime) return;

    timer = now;

    switch (state)
    {
    case FADE_OUT:
        step++;
        if(step >= 6)
        {
            //Invoke read sensor
            if (onDisplayOffCallback != NULL) {
                onDisplayOffCallback();
            }
            state = FADE_IN;
            step = 0;
            dataSwitched = true;
        }
        break;
    case FADE_IN:
        step++;
        if(step >= 6)
        {
            state = IDLE;
            step = 0;
        }
        break;
    
    default:
        break;
    }
}