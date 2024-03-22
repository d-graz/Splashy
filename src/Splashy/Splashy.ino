//libraries in release mode

#define DEBUG
//libraries in debug mode
#include "libraries/LedMatrix/LedMatrix.hpp"
#include "libraries/LedMatrix/LedMatrix.cpp"
#include "libraries/MySD/MySD.hpp"
#include "libraries/MySD/MySD.cpp"
#include "libraries/TaskManagement/TaskManagement.hpp"
#include "libraries/TaskManagement/TaskManagement.cpp" 

// define
#define BAUD_RATE 9600

// global variables
LedMatrix *led_matrix;

// setup
void setup() {
  // start serial communication
  Serial.begin(BAUD_RATE);
  delay(2000);

  #ifdef DEBUG
  Serial.println(F("Init setup"));
  #endif

  //initialize early led matrix to show error
  led_matrix = new LedMatrix;

  // initialize the SD card
  if(!init_sd()){
    #ifdef DEBUG
    Serial.println(F("Failed to initialize SD card"));
    #endif
    led_matrix->show_error();
    while (true){
      delay(600000);
    }
  }

  #ifdef DEBUG
  Serial.println(F("Setup finished"));
  #endif
}

// loop
void loop() {
  #ifdef DEBUG
  Serial.println(F("Loop cycle"));
  #endif
  if(!led_matrix->load_animation("boot.txt", 0)){
    Serial.println("Failed to load boot.txt");
    led_matrix->show_error();
    while (true){
      delay(600000);
    }
  }
  unsigned int start_milliseconds = 0, end_milliseconds = 0;
  while(true){
    start_milliseconds = millis();
    if(led_matrix->get_status() == TaskStatus::READY){
      led_matrix->next();
      end_milliseconds = millis();
      start_milliseconds = end_milliseconds - start_milliseconds;
      Serial.print(F("Cycle time: "));
      Serial.println(start_milliseconds);
    }
  }
}
