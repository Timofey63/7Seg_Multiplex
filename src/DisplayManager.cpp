#include <DisplayManager.h>

const int DisplayManager::dataPin = 2;
const int DisplayManager::clockPin = 3;
const int DisplayManager::latchPin = 4;

DisplayManager::DisplayManager()
{
    displayCount = 3;
    displays[0] = SegmentDisplay(7);
    displays[1] = SegmentDisplay(6);
    displays[2] = SegmentDisplay(5);
}

void DisplayManager::shiftOutData(byte data)
{
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, data);
    digitalWrite(latchPin, HIGH);
}

void DisplayManager::begin()
{
    // Настройка пинов для 74HC595
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(latchPin, OUTPUT);

    for (int i = 0; i < DisplayManager::displayCount; i++) 
    {
        displays[i].begin();
    }
}

void DisplayManager::setValue(DisplayData data)
{
    currentData = data;
}

void DisplayManager::update()
{
    unsigned long currentMillis = millis();

    if (currentMillis - previousOutputTime >= outputInterval)
    {
        previousOutputTime = currentMillis;

        for (int i = 0; i < displayCount; i++)
        {
            displays[i].off();
        }

        activeDisplayIndex = (activeDisplayIndex + 1) % displayCount;

        byte segmentCode = currentData.get(activeDisplayIndex);
        shiftOutData(segmentCode);

        displays[activeDisplayIndex].on();
    }
}
