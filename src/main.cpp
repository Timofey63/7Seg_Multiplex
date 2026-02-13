#include <Arduino.h>
#include "DisplayManager.h"
#include "DisplayData.h"
//https://github.com/Timofey63/7Seg_Multiplex

DisplayManager displayManager;

unsigned long lastUpdate = 0;
const unsigned timeUpdateData = 5000;

//for test
int temperature = 0;
bool isCelsius = true;

void setup() 
{
  Serial.begin(9600);
  displayManager.begin();
  Serial.println("Display initialized");
}

void loop() 
{
  displayManager.update();
  
  if (millis() - lastUpdate > timeUpdateData) {
    lastUpdate = millis();
    //srand(millis());
    temperature = (rand() % 90) - 40; //(temperature + 1) % 100;
    Serial.println(rand());
    isCelsius = !isCelsius;

    DisplayData newData(temperature, isCelsius);
    displayManager.setValue(newData);
    
    Serial.print(isCelsius ? "Temperature: " : "Percent: ");
    Serial.print(temperature);
    Serial.println(isCelsius ? "C" : "%");
  }
}