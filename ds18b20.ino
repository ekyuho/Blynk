#include <OneWire.h>
#include <DallasTemperature.h>
 
#define ONE_WIRE_BUS D3
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
 
float get()
{
  static bool first = true;
  if (first) {
    sensors.begin();
    first = false;
  }
  sensors.requestTemperatures();
  float  t = sensors.getTempCByIndex(0);
  Serial.println(t);
  return(t);
}
