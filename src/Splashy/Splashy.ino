//TODOS
//TODO: add servocontroller class
//TODO: add state controller class

// LIBRARIES

//libraries in release mode

#define DEBUG
//libraries in debug mode
#include "libraries/LedMatrix/LedMatrix.hpp"
#include "libraries/LedMatrix/LedMatrix.cpp"
#include "libraries/MySD/MySD.hpp"
#include "libraries/MySD/MySD.cpp"
#include "libraries/TaskManagement/TaskManagement.hpp"
#include "libraries/TaskManagement/TaskManagement.cpp" 

// DEFINE
#define BAUD_RATE 9600

// GLOBAL VARIABLES

// led matrix object
LedMatrix *led_matrix;

// scheduler
Scheduler *scheduler;

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

  //initialize scheduler
  scheduler = new Scheduler;

  //add led matrix to scheduler
  scheduler->add_task(led_matrix);

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
  while(true){
    if(!scheduler->executeAll()){
      #ifdef DEBUG
      Serial.println(F("Failed to execute all tasks"));
      #endif
      led_matrix->show_error();
      while (true){
        delay(600000);
      }
    }
  }
}
