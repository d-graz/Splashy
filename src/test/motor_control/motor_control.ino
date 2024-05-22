#include <Servo.h>

#define SERVO_PIN_L 9  // Pin per il servo motore L
#define SERVO_PIN_R 10 // Pin per il servo motore R
#define SERVO_PIN_H 11 // Pin per il servo motore H

Servo servoL;  // Crea un oggetto servo per controllare il servo motore L
Servo servoR;  // Crea un oggetto servo per controllare il servo motore R
Servo servoH;  // Crea un oggetto servo per controllare il servo motore H

void setup() {
  Serial.begin(9600);  // Inizia la comunicazione seriale a 9600 baud
  servoL.attach(SERVO_PIN_L);  // Collega il servo motore L al pin SERVO_PIN_L
  servoR.attach(SERVO_PIN_R);  // Collega il servo motore R al pin SERVO_PIN_R
  servoH.attach(SERVO_PIN_H);  // Collega il servo motore H al pin SERVO_PIN_H
}

void loop() {
  if (Serial.available()) {  // Se ci sono dati disponibili da leggere
    char motor = Serial.read();  // Legge il primo carattere (L, R o H)
    int angle = Serial.parseInt();  // Legge il numero successivo (0-180)
    if (Serial.read() == '\n') {  // Se il prossimo carattere è un ritorno a capo
      if (motor == 'L') {
        servoL.write(angle);  // Imposta il servo motore L all'angolo specificato
      } else if (motor == 'R') {
        servoR.write(angle);  // Imposta il servo motore R all'angolo specificato
      } else if (motor == 'H') {
        servoH.write(angle);  // Imposta il servo motore H all'angolo specificato
      }
    }
  }
}