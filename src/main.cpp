#include <Arduino.h>
#include "DisplayManager.h"
#include <Adafruit_AHTX0.h>
//https://github.com/Timofey63/7Seg_Multiplex

DisplayManager displayManager;
Adafruit_AHTX0 aht;

const unsigned timeUpdateDisplay = 5000;
unsigned long lastUpdateDisplay;

int tempDisplay, himDisplay;
bool isCelsius = true;

void setValueDispay(), onDisplayOff();

void setup() 
{
  Serial.begin(9600);

  if (!aht.begin()) 
  {
    Serial.println("Not found sensor AHT10!");
    while (1) delay(100);
  }

  displayManager.begin();

  displayManager.fsm.setOnDisplayOffCallback(onDisplayOff);
  Serial.println("Display initialized");
}

void loop() 
{
  if (millis() - lastUpdateDisplay > timeUpdateDisplay) 
  {
    lastUpdateDisplay = millis();
    
    setValueDispay();
  }

  displayManager.update();
}

void setValueDispay()
{
  isCelsius = !isCelsius;
  int valueDisplay = isCelsius? tempDisplay : himDisplay;
  DisplayData newData(valueDisplay, isCelsius);

  displayManager.setValue(newData);

  Serial.print(isCelsius ? "Temperature: " : "Percent: ");
  Serial.print(valueDisplay);
  Serial.println(isCelsius ? "°C" : "%");
}

void onDisplayOff()
{
  sensors_event_t humidity, temperature;
  aht.getEvent(&humidity, &temperature);
  
  tempDisplay = temperature.temperature;
  himDisplay = humidity.relative_humidity;
}