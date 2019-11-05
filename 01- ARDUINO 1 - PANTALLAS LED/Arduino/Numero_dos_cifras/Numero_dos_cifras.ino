#include <MatrizLed.h>

MatrizLed pantalla;
int numero = 45;

void setup() {
  pantalla.begin(12, 11, 10, 2);      // dataPin, clkPin, csPin, numero de matrices de 8x8
}

void loop() { 
  pantalla.borrar();
  pantalla.escribirCifra(numero);
}
