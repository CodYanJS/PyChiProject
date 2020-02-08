/**
 * Exemple de code pour un servomoteur, il fait faire des va-et-vient à la tête du servomoteur.
 */

 /* Inclut la lib Servo pour manipuler le servomoteur */
#include <Servo.h>

/* Créer un objet Servo pour contrôler le servomoteur */
Servo monServomoteur;

int redpin = 11; //select the pin for the red LED
int bluepin =10; // select the pin for the  blue LED
int greenpin =9;// select the pin for the green LED
 
int val;
 
void setup() {
      pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  Serial.begin(9600);
  // Attache le servomoteur à la broche D9
  monServomoteur.attach(9);
}

void loop() {
  for(val=255; val>0; val--)
  {
   analogWrite(11, 255);
   analogWrite(10, 0-val);
   analogWrite(9, 0-val);
   delay(1); 
  }
for(val=0; val<255; val++)
  {
   analogWrite(11, 255);
   analogWrite(10, 0-val);
   analogWrite(9, 0-val);
   delay(1); 
  }
 Serial.println(val, DEC);
  // Fait bouger le bras de 0° à 180°
  for (int position = 0; position <= 180; position++) {
    monServomoteur.write(position);
    delay(15);
  }
  
  // Fait bouger le bras de 180° à 10°
  for (int position = 180; position >= 0; position--) {
    monServomoteur.write(position);
    delay(15);
  }
}
