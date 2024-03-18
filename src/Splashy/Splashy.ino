//libraries in release mode


#define DEBUG
//libraries in debug mode
#include "libraries/MySD/MySD.hpp"
#include "libraries/LedMatrix/LedMatrix.hpp"

// define
#define BAUD_RATE 9600
LedMatrix *led_matrix;
void setup() {
  // start serial communication
  Serial.begin(BAUD_RATE);
  #ifdef DEBUG
  Serial.println(F("Init setup"));
  #endif
  led_matrix = new LedMatrix;
  #ifdef DEBUG
  Serial.println(F("Setup finished"));
  #endif
}

void loop() {
  // put your main code here, to run repeatedly:
  #ifdef DEBUG
  Serial.println(F("Loop"));
  #endif
  if(!led_matrix->load_animation("animations/boot.txt")){
    led_matrix->show_error();
    while (true){
      delay(1000);
    }
  }
  while(led_matrix->next_frame()){
    led_matrix->show_frame();
    delay(500);
  }
}
