int lightSensorValue=0;
int lightSensorPin = A10;
int LedPin = 6;
int mappedlightSensorValue=0;

void setup() {
  Serial.begin (9600);
  
 

}

void loop() {
  lightSensorValue=analogRead (lightSensorPin);
mappedlightSensorValue= map (lightSensorValue, 0,1023,0,255);
  analogWrite (LedPin, mappedlightSensorValue);
  delay(200);

}
