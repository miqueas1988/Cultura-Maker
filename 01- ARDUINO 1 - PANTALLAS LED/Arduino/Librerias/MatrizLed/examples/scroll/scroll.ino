#include <MatrizLed.h>

/*
 * Texto que aparece por la izquierda y sale por la derecha
 */

MatrizLed pantalla;

void setup() {
  pantalla.begin(12, 11, 10, 3); // dataPin, clkPin, csPin, numero de matrices de 8x8
}

void loop() { 
  pantalla.borrar();
  pantalla.escribirFraseScroll("Campamento de verano", 50  ); // Texto, milisegundos entre frames
}
