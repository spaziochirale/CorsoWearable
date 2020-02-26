/*******************************************
 * CORSO ELETTRONICA WEARABLE CON ARDUINO 
 * 
 * Author: Rosita Esposito
 * Ver: 1.0
 * Title: Esempio di lettura del sensore DHT11
 * 
 * Circuit: Board Adafruit Flora con DHT11
 * 
 */

// Richiamo la libreria DHT
#include <DHT.h>

// Creo un oggetto di tipo DHT11 chiamato sensore1, collegato al PIN 6 
DHT sensore1(6, DHT11);

void setup() {
  // Inizializzo la comunicazione seriale
  Serial.begin(9600);
  
  // Inizializzo il sensore
  sensore1.begin();
}

void loop() {
  
  // Definisco le due variabili per ospitare i valori letti (con virgola decimale)
  float temp, hum;
  
  // Leggo i valori dal sensore
  temp = sensore1.readTemperature();
  hum = sensore1.readHumidity();
  
  // Stampo i valori sul terminale seriale
  // in modo formattato
  Serial.print("Temp C° = ");
  Serial.print(temp);
  Serial.print(" Umidità % = ");
  Serial.println(hum);
  
  // Ritardo perché è inutile leggere il sensore con frequenza elevata
  delay(3000);
}
