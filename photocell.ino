/*******************************************
 * CORSO ELETTRONICA WEARABLE CON ARDUINO 
 * 
 * Author: Rosita Esposito
 * Ver: 1.0
 * Title: Esempio di gestione del fotoresistore
 * 
 * Circuit: Board Adafruit Flora con fotoresistore e partitore
 * 
 */

int photocellPin=A0;
int photocellReading;
int pinled = 13;

void setup(void) {
    Serial.begin(9600);
    pinMode(13, OUTPUT);
    }
    
void loop(void) {
  photocellReading = analogRead(photocellPin);  
  if (photocellReading < 400) { 
    digitalWrite (pinled, HIGH);
    } 
  else {
   digitalWrite (pinled, LOW);
  }
  Serial.print("Analog reading = ");
  Serial.println(photocellReading); 
  delay(1000); 
}
