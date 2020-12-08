#include "DHT.h"
#define DHTPIN 3    // what digital pin we're connected to //2
#define LED 2 
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321  //4

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");
   pinMode(LED, OUTPUT); 

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(100);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("  Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
//  Serial.print("  Temperature: ");
//  Serial.print(t);
//  Serial.print(" *C ");
//  Serial.print(f);
//  Serial.print(" *F\t");
//  Serial.print("  Heat index: ");
//  Serial.print(hic);
//  Serial.print(" *C ");
//  Serial.print(hif);
//  Serial.print(" *F");


if(h>=75.00){                          
  digitalWrite(LED,1);
  Serial.println("  :เปิดไฟ");
  }else{
  digitalWrite(LED,0);
  Serial.println("  :ปิดไฟ");
    }

  
}
