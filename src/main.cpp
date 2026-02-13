#include <Arduino.h>
#include "digit.h"

//(D5, D6, D7)
const int COUNT_DIGITS = 3;
Digit digits[COUNT_DIGITS] = {Digit(5), Digit(6), Digit(7)};

// Таймеры и состояния
unsigned long previousDigitTime = 0;
const long digitInterval = 1000;
int currentDigit = 0;

//вывод
unsigned long previousOutputTime = 0;
const long outputInterval = 3;
int activePinIndex = 0;

void setup() 
{
  Serial.begin(9600);

  Digit::allSetup();
  for (int i = 0; i < COUNT_DIGITS; i++) 
  {
    digits[i].begin();
  }
}

void loop() 
{
  unsigned long currentMillis = millis();
  
  // тестовый таймер
  if (currentMillis - previousDigitTime >= digitInterval) 
  {
    previousDigitTime = currentMillis;
    
    currentDigit = (currentDigit + 1) % 10;
  }

  // основной вывод
  if (currentMillis - previousOutputTime >= outputInterval) 
  {
    previousOutputTime = currentMillis;

    digits[activePinIndex].off();
    activePinIndex = (activePinIndex + 1) % 3;
    digits[activePinIndex].on();
    digits[activePinIndex].display(currentDigit);
  }
}