#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);
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

  lcd.init();                      
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Bienvenido a tu");
  lcd.setCursor(0, 1);
  lcd.print("reproductor MP3");
  delay(5000);
  lcd.clear();
  lcd.print("  Dale al Play!");
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
    lcd.clear();
    lcd.backlight();
    lcd.setCursor(1, 0);
    lcd.print("Reproduciendo");
    lcd.setCursor(1, 1);
    lcd.print("SONG:");
    lcd.print(miMP3.readCurrentFileNumber(1));
    lcd.setCursor(9, 1);
    lcd.print("VOL:");
    lcd.print(miMP3.readVolume());
  }
  else if (stopp == HIGH) {
    miMP3.pause();
    lcd.clear();
    lcd.noBacklight();
  }
  else if (prev == HIGH) {
    miMP3.previous();
    lcd.setCursor(6, 1);
    lcd.print(miMP3.readCurrentFileNumber(1));
  }
  else if (next == HIGH) {
    miMP3.next();
    lcd.setCursor(6, 1);
    lcd.print(miMP3.readCurrentFileNumber(1));
  }
  else if (vol_up == HIGH) {
    miMP3.volumeUp();
    lcd.setCursor(13, 1);
    if (miMP3.readVolume() > 9){
      lcd.print(miMP3.readVolume());
    }
    else{
      lcd.print("0");
      lcd.print(miMP3.readVolume());
    }
  }
  else if (vol_down == HIGH) {
    miMP3.volumeDown();
    lcd.setCursor(13, 1);
    if (miMP3.readVolume() > 9){
      lcd.print(miMP3.readVolume());
    }
    else{
      lcd.print("0");
      lcd.print(miMP3.readVolume());
    }
  }

  delay (1000);
}
