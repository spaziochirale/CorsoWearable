/*******************************************
 * CORSO ELETTRONICA WEARABLE CON ARDUINO 
 * 
 * Author: Rosita Esposito
 * Ver: 1.0
 * Title: Esempio di gestione Matrice LED
 * 
 * Circuit: Board Adafruit Flora con LED Matrix 8X8 e controller MAX 7219
 * 
 */

// Includo la libreria LedControl
#include "LedControl.h"
/*
 Definizione dell'oggetto lc per controllare la matrice
 ***** Versione FLORA *****
 pin 12 is connected to the DataIn 
 pin 9 is connected to the CLK 
 pin 6 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,9,6,1);


void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);

}

void loop() {
  // Definisco due immagini usando numeri binari
  int img1[8] = {
    B10000001,
    B01000010,
    B00111100,
    B00000000,
    B00011000,
    B00011000,
    B10000001,
    B01111110};
int img2[8] = {
    B10000001,
    B01000010,
    B00111100,
    B00000000,
    B00000000,
    B00011000,
    B10011001,
    B01111110};

// carico sul controller le due immagini alternandole
   for (int i=0;i<8;i++) lc.setRow(0,i,img1[i]);
   delay(200);
   for (int i=0;i<8;i++) lc.setRow(0,i,img2[i]);
   delay(200);

}
