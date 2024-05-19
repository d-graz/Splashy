#include <CapacitiveSensor.h>

// Crea un oggetto CapacitiveSensor 'capSensor' con un send pin 4 e un receive pin 3
CapacitiveSensor capSensor = CapacitiveSensor(4,3);

void setup(){
  Serial.begin(9600);
  delay(2000);
  Serial.println("Finished init");
  Serial.flush();
}

void loop(){
  long sensorValue = capSensor.capacitiveSensor(2000);
  Serial.println(sensorValue);

  delay(1000);
}