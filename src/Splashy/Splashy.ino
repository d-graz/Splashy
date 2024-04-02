// LIBRARIES
//libraries in release mode
#include "libraries/Config/Global.hpp"
#include "libraries/Core/src/Core.hpp"

#define DEBUG
//libraries in debug mode
#include "libraries/LedMatrix/LedMatrix.hpp"
#include "libraries/LedMatrix/LedMatrix.cpp"
#include "libraries/MySD/MySD.hpp"
#include "libraries/MySD/MySD.cpp"
#include "libraries/TaskManagement/TaskManagement.hpp"
#include "libraries/TaskManagement/TaskManagement.cpp"
#include "libraries/ServoController/ServoController.hpp"
#include "libraries/ServoController/ServoController.cpp"

// DEFINE
#define BAUD_RATE 9600

// FUNCTIONS
#ifdef DEBUG
void handel_error(bool r, String e){
  if(!r){
    Serial.print(F("Error: "));
    Serial.println(e);
    led_matrix->show_error();
    while (true){
      delay(600000);
    }
  }
}
#else
void handel_error(bool r){
  if(!r){
    led_matrix->show_error();
    while (true){
      delay(600000);
    }
  }
}
#endif

// setup
void setup() {
  #ifdef DEBUG
  // start serial communication
  Serial.begin(BAUD_RATE);
  delay(2000);
  Serial.println(F("Init setup"));
  #endif

  //init the scheduler
  scheduler = new Scheduler();

  //init the led matrix
  led_matrix = new LedMatrix();

  //init the servo controller
  servo_controller = new ServoController();

  //init the sd card
  #ifdef DEBUG
  Serial.println(F("Initializing SD card"));
  #endif
  #ifdef DEBUG
  handel_error(init_sd(), "Failed to initialize SD card");
  #else
  handel_error(init_sd());
  #endif

  //add led matrix to scheduler
  #ifdef DEBUG
  Serial.println(F("Adding LedMatrix to scheduler and loading boot animation"));
  #endif
  scheduler->add_task(led_matrix);
  #ifdef DEBUG
  handel_error(led_matrix->load_animation("an/boot.txt", 0), "Failed to load an/boot.txt");
  #else
  handel_error(led_matrix->load_animation("an/boot.txt", 0));
  #endif

  //add servo controller to scheduler
  #ifdef DEBUG
  Serial.println(F("Adding ServoController to scheduler"));
  #endif
  scheduler->add_task(servo_controller);

  scheduler->executeAll();

  //homing the servo
  #ifdef DEBUG
  Serial.println(F("Homing the servo"));
  #endif
  servo_controller->home(true);

  #ifdef DEBUG
  Serial.println(F("Setup finished"));
  #endif
}

// loop
void loop() {
  #ifdef DEBUG
  Serial.println(F("Loop cycle"));
  Serial.println(F("Loading servo moto animation"));
  #endif
  #ifdef DEBUG
  handel_error(servo_controller->load_animation("mtr/tst.txt", 0), "Failed to load mtr/tst.txt");
  #else
  handel_error(servo_controller->load_animation("mtr/tst.txt", 0));
  #endif
  
  while(true){
    #ifdef DEBUG
    Serial.println(F("Scheduler loop"));
    #endif
    #ifdef DEBUG
    handel_error(scheduler->executeAll(), "Failed to execute scheduler");
    delay(2000);
    #else
    handel_error(scheduler->executeAll());
    #endif
  }
}
