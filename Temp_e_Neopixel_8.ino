/*******************************************
 * CORSO ELETTRONICA WEARABLE CON ARDUINO 
 * 
 * Author: Rosita Esposito
 * Ver: 1.0
 * Title: Esempio di interazione luminosa con sensore TMP36
 * 
 * Circuit: Board Adafruit Flora con TMP36
 * 
 */
 
// Includo la libreria Neopixel
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Dichiaro il PIN 8 come PIN di controllo della strip Neopixel
// Il PIN 8 corrisponde al Neopixel saldato sulla scheda Flora
#define PIN            8

// Definisco l'"oggetto" pixels che rappresenta una striscia di 1 solo Neopixel
// Le sigle e il tipo di neopixel sono quelle del tipo di neopixel saldato sul Flora
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);


// Dichiaro le variabili utilizzate nello Sketch
float temp,voltage;
int val;
int red,green;


void setup()
{
 // Inizializzo la comunicazione con il monitor seriale 
 Serial.begin(9600);
 
 // Inizializzo la libreria Neopixel e l'oggetto dichiarato sopra
 pixels.begin();
}


void loop()
{
// Lettura della temperature
// leggo il valore del sensore
val = analogRead(A7);

// deduco il valore di tensione rilevato sul pin
voltage = (val * 3.3) / 1024.0;

// converto la tensione in gradi centigradi con la formula specifica del sensore
// e scrivo sul terminale il valore letto e la temperatura calcolata
temp = (voltage - 0.5)*100;
Serial.print("Val Sensore: ");
Serial.print(val);
Serial.print("\tTemp C: ");
Serial.print(temp);

// Uso la funzione "map" per generare un valore per il rosso tra 0 e 150
// in modo proporzionale alla temperatura che immagino variabile tra 16 e 28 gradi
red= map(temp,16,28,0,150);

// Uso la funzione "map" per generare un valore per il verde tra 0 e 150
// in modo INVERSAMENTE proporzionale alla temperatura 
green= map(temp,16,28,150,0);

// scivo sul terminale i valori di colore appena calcolati
Serial.print("\tred=");
Serial.print(red);
Serial.print("\tgreen=");
Serial.println(green);

// Imposto il valore di colore del neopixel
pixels.setPixelColor(0, pixels.Color(red,green,0));

// Attivo il neopixel
pixels.show();

// Introduco un ritardo per evitare di ciclare troppo velocemente
delay(500);
}
