#define CONTROL_PIN 7 // Definisci il pin di controllo qui

void setup() {
  Serial.begin(9600); // Inizia la comunicazione seriale a 9600 baud
  pinMode(CONTROL_PIN, OUTPUT); // Imposta il pin di controllo come output
}

void loop() {
  if (Serial.available() > 0) { // Se ci sono dati disponibili sulla seriale
    String command = Serial.readStringUntil('\n'); // Leggi il comando
    command.trim();

    if (command == "1") { // Se il comando è "HIGH"
      digitalWrite(CONTROL_PIN, HIGH); // Imposta il pin di controllo a HIGH
      Serial.println("Pin set to HIGH");
    } 
    else if (command == "0") { // Se il comando è "LOW"
      digitalWrite(CONTROL_PIN, LOW); // Imposta il pin di controllo a LOW
      Serial.println("Pin set to LOW");
    }
    else {
      Serial.println("Invalid command");
    }
  }
}