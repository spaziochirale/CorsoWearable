

#include <Servo.h>
Servo ro;
int laccetto;
int angolo;


void setup() {
  
  ro.attach(9);
  Serial.begin(9600);
  
}

void loop() {
  laccetto = analogRead(A10);
  Serial.print("Laccetto ->");
  Serial.print(laccetto);
  angolo = map(laccetto,100,1023,0,179);
  Serial.print(" angolo->");
  Serial.println (angolo);
  ro.write(angolo);
  delay(100);
  
}
