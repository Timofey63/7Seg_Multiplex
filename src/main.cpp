#include <Arduino.h>
#include "DisplayManager.h"
#include <Adafruit_AHTX0.h>
//https://github.com/Timofey63/7Seg_Multiplex

DisplayManager displayManager;
Adafruit_AHTX0 aht;

unsigned long lastUpdate = 0;
const unsigned timeUpdateData = 5000;

bool isCelsius = true;
int setValueDispay();

void setup() 
{
  Serial.begin(9600);
  displayManager.begin();

  if (!aht.begin()) 
  {
    Serial.println("Not found sensor AHT10!");
    while (1) delay(100);
  }

  Serial.println("Display initialized");
}

void loop() 
{
  displayManager.update();
  
  if (millis() - lastUpdate > timeUpdateData) 
  {
    lastUpdate = millis();
    
    int valueDisplay = setValueDispay();
    
    Serial.print(isCelsius ? "Temperature: " : "Percent: ");
    Serial.print(valueDisplay);
    Serial.println(isCelsius ? "°C" : "%");
  }
}

int setValueDispay()
{
  sensors_event_t humidity, temperature;
  aht.getEvent(&humidity, &temperature);
    
  isCelsius = !isCelsius;
  int valueDisplay = isCelsius ? temperature.temperature :
    humidity.relative_humidity;
  DisplayData newData(valueDisplay, isCelsius);

  displayManager.setValue(newData);

  return valueDisplay;
}