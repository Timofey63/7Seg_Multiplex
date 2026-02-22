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
    bool dataSwitched = false;

private:
    State state;// IDLE

    unsigned long timer;
    unsigned stepTime;

    int step;
    static const byte stateCode[6];
};
