void setup() {
  Serial.begin(9600);
  delay(2000);

}

void loop() {
  float random_value = get_random_value();
  Serial.println(random_value);
  Serial.flush();
  delay(1000 * 30);
}

float get_random_value(){
  int random_value = random(20,150);
  float r = (float)random_value / 100.0;
  return r;
}