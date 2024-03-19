//libraries in release mode

#define DEBUG
//libraries in debug mode
#include "libraries/LedMatrix/LedMatrix.hpp"
#include "libraries/LedMatrix/LedMatrix.cpp"
#include "libraries/MySD/MySD.cpp"

// define
#define BAUD_RATE 9600
LedMatrix *led_matrix;
void setup() {
  // start serial communication
  Serial.begin(BAUD_RATE);
  #ifdef DEBUG
  Serial.println(F("Init setup"));
  #endif
  // initialize the SD card
  if(!init_sd()){
    #ifdef DEBUG
    Serial.println(F("Failed to initialize SD card"));
    #endif
    while (true){
      delay(1000);
    }
  }
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
    Serial.println("Failed to load boot.txt");
    led_matrix->show_error();
    while (true){
      delay(1000);
    }
  }
  for(byte i =0; i <23 ; i++){
    led_matrix->next_frame();
    led_matrix->show_frame();
    delay(500);
  }
  if(!led_matrix->load_animation("animations/FillingHeart.txt")){
    Serial.println("Failed to load FillingHeart.txt");
    led_matrix->show_error();
    while (true){
      delay(1000);
    }
  }
  for(byte i =0; i <7 ; i++){
    led_matrix->next_frame();
    led_matrix->show_frame();
    delay(1000);
  }
  if(!led_matrix->load_animation("animations/HeartToEye.txt")){
    Serial.println("Failed to load HeartToEye.txt");
    led_matrix->show_error();
    while (true){
      delay(1000);
    }
  }
  for(byte i =0; i <4 ; i++){
    led_matrix->next_frame();
    led_matrix->show_frame();
    delay(1000);
  }
}
