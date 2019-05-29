/***************************************************
 *    ESEMPIO DI GESTIONE NEOPIXEL CON LIBRERIA ADAFRUIT
 *      Versione base
 *    
 *    Author: Rosita Esposito
 *    Version: 1.0
 *    Corso Elettronica Wearable
 *    
 *    
 */

// Viene richiamata la libreria NeoPixel
#include <Adafruit_NeoPixel.h>

// Viene richiamata la libreria avr/power.h solo se si sta generando codice per una
// scheda Arduino che ha il microcontrollore di tipo AVR.
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Viene definita una "MACRO" per parametrizzare il PIN di controllo dove è
// collegata la striscia di neopixel per modificare il programma per usare un PIN diverso
// è sufficiente modificare solo la riga seguente
#define PIN            6


// Anche in questo caso viene definita una "MACRO" per parametrizzare 
// il numero di neopixel. Per modificare il programma con un numero diverso di pixel è
// quindi sufficiente modificare solo la riga seguente
#define NUMPIXELS      3 

// Viene creato l'oggetto "pixels" che sarà usato nel programma per pilotare i
// neopixel. Vengono specificati come parametri il numero di pixel, il PIN di controllo e il
// tipo di neopixel. NEO_RGB+NEO_KHZ800 rappresenta la combinazione da usare per i neopixel
// di tipo più nuovo acquistati di recente. Sul sito Adafruit sono riportati i parametri
// per neopixel di tipo più vecchio.

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // variabile che memorizza il tempo di ritardo di mezzo secondo

void setup() {
  pixels.begin(); // Viene inizializzata la libreria neopixel
}

void loop() {

  // La numerazione dei neopixel della striscia inizia da 0, il secondo è quindi 1...
  // Viene effettuato un ciclo per impostare il colore di tutti i pixel della striscia
  // ciascun neopixel viene acceso con lo stesso colore e tra un passo e l'altro del
  // ciclo c'è un tempo di attesa per creare l'effetto di animazione.
  
  for(int i=0;i<NUMPIXELS;i++){

    // Viene impostato il colore del neopixel i-esimo
    // pixels.Color ha come parametro il valore RGB, da 0,0,0 a 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,150,0)); // Modificare qui per il colore desiderato

    //Per variare il colore dei pixel occorre chiamare la funzione show
    pixels.show();

    delay(delayval); // attende un certo tempo (in millisecondi)

  }
}
