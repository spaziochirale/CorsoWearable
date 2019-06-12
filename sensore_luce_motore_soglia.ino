#include <Servo.h>
Servo ro;
int lightsensorvalue=0;
int lightSensorValue = A10;
int servoPin = 9;

void setup() {
  Serial.begin(9600);
  ro.attach (servoPin);
}

void loop() {
  lightSensorValue=analogRead (A10);
 
if (lightSensorValue>200){ 
  ro.write (100);  
}
else 
{ 
  ro.write(0);
}
delay (200);
}
