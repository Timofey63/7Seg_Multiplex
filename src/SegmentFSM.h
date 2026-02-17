#pragma once
#include <Arduino.h>

class SegmentFSM
{
public:
    enum State
    {
        IDLE,
        FADE_OUT,
        FADE_IN
    };

    SegmentFSM();
    void start();
    void update();
    byte getMask();
    bool isActive();

private:
    State state;// = IDLE;

    unsigned long timer;// = 0;
    unsigned stepTime;// = 100;

    int step;// = 0;
    static const byte stateCode[6];
};
