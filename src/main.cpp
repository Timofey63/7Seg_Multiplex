#include <Arduino.h>
#include "DisplayManager.h"
#include "DisplayData.h"
//https://github.com/Timofey63/7Seg_Multiplex

DisplayManager displayManager;

unsigned long lastUpdate = 0;
const unsigned timeUpdateData = 500;

//for test
int temperature = 0;

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
    
    temperature = (temperature + 1) % 100;
    bool isCelsius = true;

    DisplayData newData(temperature, isCelsius);
    displayManager.setValue(newData);
    
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println("C");
  }
}