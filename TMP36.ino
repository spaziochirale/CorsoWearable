/*******************************************
 * CORSO ELETTRONICA WEARABLE CON ARDUINO 
 * 
 * Author: Rosita Esposito
 * Ver: 1.0
 * Title: Esempio di lettura del sensore TMP36
 * 
 * Circuit: Board Adafruit Flora con TMP36
 * 
 */

// Definisco le variabili utilizzate nello sketch
int val; // Valore letto dal PIN Analogico del sensore
float temp,voltage; // Numeri con virgola per la traduzione in gradi centigradi

void setup()
{
  // Inizializzo la comunicazione con il terminale seriale
  Serial.begin(9600);
}

void loop()
{
  // Leggo il valore del PIN A7 e lo visualizzo sul terminale seriale
  val = analogRead(A7);
  Serial.print("Val Sensore: ");
  Serial.print(val);

  // Calcolo il valore di tensione applicato sul PIN
  voltage = (val * 3.3) / 1024.0;

  // Calcolo il valore della temperatura usando la formula per TMP36
  // e la visualizzo sul terminale (andando a capo)
  temp = (voltage - 0.5)*100;
  Serial.print(" Temp C: ");
  Serial.println(temp);
  
  // Introduco un ritardo per evitare di leggere inutilmente il sensore troppe volte
  delay(500);
}
