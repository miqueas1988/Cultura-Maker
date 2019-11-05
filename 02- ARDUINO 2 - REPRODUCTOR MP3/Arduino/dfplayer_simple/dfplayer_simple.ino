#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial miPuertoSerie(2, 4); // RX, TX
DFRobotDFPlayerMini miMP3;

const int in_play = 8;
const int in_stopp = 9;
const int in_prev = 10;
const int in_next = 11;
const int in_vol_up = 12;
const int in_vol_down = 13;

int play = 0;
int stopp = 0;
int prev = 0;
int next = 0;
int vol_up = 0;
int vol_down = 0;

void setup()
{
  pinMode(in_play,INPUT);
  pinMode(in_stopp,INPUT);
  pinMode(in_prev,INPUT);
  pinMode(in_next,INPUT);
  pinMode(in_vol_up,INPUT);
  pinMode(in_vol_down,INPUT);
  
  miPuertoSerie.begin(9600);
  miMP3.begin(miPuertoSerie); 
  miMP3.volume(30);  //Set volume value. From 0 to 30
}

void loop(){

  play = digitalRead(in_play);
  stopp = digitalRead(in_stopp);
  prev = digitalRead(in_prev);
  next = digitalRead(in_next);
  vol_up = digitalRead(in_vol_up);
  vol_down = digitalRead(in_vol_down);

  if (play == HIGH) {
    //miMP3.play(1);
    miMP3.enableLoopAll();
  }
  else if (stopp == HIGH) {
    miMP3.pause();
  }
  else if (prev == HIGH) {
    miMP3.previous();
  }
  else if (next == HIGH) {
    miMP3.next();
  }
  else if (vol_up == HIGH) {
    miMP3.volumeUp();
  }
  else if (vol_down == HIGH) {
    miMP3.volumeDown();
  }
  delay (1000);
}
