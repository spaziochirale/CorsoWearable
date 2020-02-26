#include <DHT.h>
DHT sensore1(6, DHT11);

void setup() {
  Serial.begin(9600);
  sensore1.begin();
}

void loop() {
  float temp, hum;
  temp = sensore1.readTemperature();
  hum = sensore1.readHumidity();
  Serial.print("Temp C° = ");
  Serial.print(temp);
  Serial.print(" Umidità % = ");
  Serial.println(hum);
  delay(1000);
}
