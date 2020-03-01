//
// Simple DHT sensor code
// 01-03-2020 - Marco Spanhaak
// Code will work together with DHT11, 21 and 22 if defined
// This code is tested on a NodeMCU, but should work also on Arduino
//

#include <DHT.h>
#define DHTPIN D3       // This is the digital pin i've used to connect the DHT22, pin 2
#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  // I'm printing an empty line because my controller prints 5 bogus chars at initialization
  // If your controller is better or does not show this behaviour, this can be deleted
  Serial.println(F(" "));
  Serial.println(F("DHT22 Initialization done"));
  dht.begin();
}

void loop() {
  // Delay is to allow sensor to grab metrics
  delay(4000);
  
  // Read Humidity and Temperature
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Perform a check to see if values can be read from sensor, if not print error message
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Cannot read from the sensor, please check!"));
    return;
  }

  // List out the measurements, on one line
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C"));
  Serial.println(" ");

  // I'm pausing measurements because i only need it once every 5 minutes.
  delay(300000);
}
