#include <Arduino.h>

volatile unsigned int pulseCount = 0; // Variabile per tenere traccia del numero di impulsi

// Funzione di interrupt che viene chiamata ogni volta che il pin 7 va da LOW a HIGH
void pulseCounter() {
  pulseCount++;
}

void setup() {
  Serial.begin(9600); // Inizia la comunicazione seriale a 9600 baud
  pinMode(2, INPUT_PULLUP); // Imposta il pin 7 come input con pullup
  attachInterrupt(digitalPinToInterrupt(2), pulseCounter, RISING); // Configura un interrupt sul pin 7
}

void loop() {
  Serial.println(pulseCount); // Stampa il numero di impulsi
  delay(1000); // Aspetta un secondo
}