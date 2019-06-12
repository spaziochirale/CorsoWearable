
int lightSensorValue=0;
int lightSensorPin = A10;
int soglia1 = 200;
int soglia2 = 600;

void setup() {
 Serial.begin(9600); 
}

void loop() {
  lightSensorValue = analogRead (lightSensorPin);
Serial.print ("Light Sensor Value:");
  Serial.println (lightSensorValue);
  
  if (lightSensorValue> soglia1)
  { 
  Serial.print ("superamento soglia 1:");
  Serial.println (soglia1);
  }
  
else if (lightSensorValue > soglia2)
 {
  Serial.print ("superamento soglia 2:");
  Serial.println (soglia2);
}
  delay(500);

}
