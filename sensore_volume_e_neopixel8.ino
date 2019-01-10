/*******************************************
 * CORSO ELETTRONICA WEARABLE CON ARDUINO 
 * 
 * Author: Rosita Esposito
 * Ver: 1.0
 * Title: Esempio di effetti luminosi correlati al volume percepito
 * 
 * Circuit: Board Adafruit Flora con sensore di suono/rumore a microfono
 * 
 */

// Includo la libreria Neopixel
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Dichiaro il PIN 8 come PIN di controllo della strip Neopixel
// sul PIN 8 di Flora è collegato il Neopixel saldato sulla scheda
#define PIN            8

// Creo l'oggetto pixels come striscia di un solo pixel controllato dal PIN definito sopra
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);

// Dichiaro le variabili usate nello Sketch
unsigned long tempo;
int pressione,pMax,pMin,volume;
int red,green;

void setup() {
// Inizializzo la comunicazione con il terminale seriale e la libreria neopixel
Serial.begin(9600);
pixels.begin();
}


void loop() {
  // Registro il tempo iniziale
  tempo=millis();

  // inizializzo i registri dei valori minimi e massimi della pressione acustica
  // campionata nell'intervallo
  pMax=0;
  pMin=1023;

 // Registro i valori mini e massimi di pressione acustica in un intervallo di 50 ms
 while((millis()-tempo)<50)
  {
    pressione=analogRead (A7);
    if(pressione>pMax) pMax=pressione;
    if(pressione<pMin) pMin=pressione;    
  }
  
// Calcolo il volume sonoro e lo scrivo sul terminale seriale
volume =pMax-pMin;
Serial.print("Volume=");
Serial.print(volume);

// Uso la funzione map per stabilire valori di rosso e verde proporzionali
// e inversamente proporzionali al volume rilevato. Scrivo i valori sul terminale seriale
red= map(volume,0,1023,0,255);
green= map(volume,0,1023,255,0);
Serial.print("\tred=");
Serial.print(red);
Serial.print("\tgreen=");
Serial.println(green);

// Imposto il colore del neopixel e lo attivo
pixels.setPixelColor(0, pixels.Color(red,green,0));
pixels.show();
}
