#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>


// MATRIX DECLARATION:
// Parameter 1 = WIDTH of NeoPixel matrix
// Parameter 2 = HEIGHT of matrix
// Parameter 3 = PIN number (most are valid)
// Parameter 4 = MATRIX LAYOUT FLAGS, add together as needed:
// NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
// Position of the FIRST LED in the matrix; pick two, e.g.
// NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
// NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs are arranged in horizontal
// rows or in vertical columns, respectively; pick one or the other.
// NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns proceed
// in the same order, or alternate lines reverse direction; pick one.

#define PIN 6
// Color definitions
#define BLACK    0x0000
#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x07E0
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0 
#define WHITE    0xFFFF


Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(22, 22, PIN,
NEO_MATRIX_TOP + NEO_MATRIX_LEFT +
NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
NEO_GRB + NEO_KHZ800);

void setup() {

  matrix.begin();
  matrix.setBrightness(20);
//  matrix.drawCircle(11,11,8,BLUE);
//  matrix.show();

}

void loop() {
  makeLines(BLUE);
  makeLines(RED);
  makeLines(GREEN);
  makeLines(CYAN);
  makeLines(MAGENTA);
  makeLines(YELLOW);
  makeLines(WHITE);
  }

void makeLines(int color){
  matrix.clear();
  for (int16_t i=0; i<matrix.width(); i+=4) {
    matrix.drawLine(0, 0, i, matrix.height()-1, color);
    matrix.show();
    delay(1);
  }
  for (int16_t i=0; i<matrix.height(); i+=4) {
    matrix.drawLine(0, 0, matrix.width()-1, i, color);
    matrix.show();
    delay(1);
  }
  delay(250);
  
  matrix.clear();
  for (int16_t i=0; i<matrix.width(); i+=4) {
    matrix.drawLine(0, matrix.height()-1, i, 0, color);
    matrix.show();
    delay(1);
  }
  for (int16_t i=matrix.height()-1; i>=0; i-=4) {
    matrix.drawLine(0, matrix.height()-1, matrix.width()-1, i, color);
    matrix.show();
    delay(1);
  }
  delay(250);
  
  matrix.clear();
  for (int16_t i=matrix.width()-1; i>=0; i-=4) {
    matrix.drawLine(matrix.width()-1, matrix.height()-1, i, 0, color);
    matrix.show();
    delay(1);
  }
  for (int16_t i=matrix.height()-1; i>=0; i-=4) {
    matrix.drawLine(matrix.width()-1, matrix.height()-1, 0, i, color);
    matrix.show();
    delay(1);
  }
  delay(250);

  matrix.clear();
  for (int16_t i=0; i<matrix.height(); i+=4) {
    matrix.drawLine(matrix.width()-1, 0, 0, i, color);
    matrix.show();
    delay(1);
  }
  for (int16_t i=0; i<matrix.width(); i+=4) {
    matrix.drawLine(matrix.width()-1, 0, i, matrix.height()-1, color); 
    matrix.show();
    delay(1);
  }
  delay(250);
}




