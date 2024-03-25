//TODOS
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
#include "libraries/ServoController/ServoController.hpp"
#include "libraries/ServoController/ServoController.cpp"

// DEFINE
#define BAUD_RATE 9600

// GLOBAL VARIABLES

// led matrix object
LedMatrix led_matrix = LedMatrix();

// scheduler
Scheduler scheduler = Scheduler();

// sevo controller
ServoController servo_controller = ServoController();

// FUNCTIONS
#ifdef DEBUG
void handel_error(bool r, String e){
  if(!r){
    Serial.print(F("Error: "));
    Serial.println(e);
    led_matrix.show_error();
    while (true){
      delay(600000);
    }
  }
}
#else
void handel_error(bool r){
  if(!r){
    led_matrix.show_error();
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
  scheduler.add_task(&led_matrix);
  #ifdef DEBUG
  handel_error(led_matrix.load_animation("boot.txt", 0), "Failed to load boot.txt");
  #else
  handel_error(led_matrix.load_animation("boot.txt", 0));
  #endif

  scheduler.executeAll();

  //add servo controller to scheduler
  #ifdef DEBUG
  Serial.println(F("Adding ServoController to scheduler"));
  #endif
  scheduler.add_task(&servo_controller);

  //check if the servos are attached
  #ifdef DEBUG
  Serial.println(F("Checking if the servos are attached"));
  #endif
  #ifdef DEBUG
  handel_error(servo_controller.check_servos(), "Servos are not attached");
  #else
  handel_error(servo_controller.check_servos());
  #endif

  //homing the servo
  #ifdef DEBUG
  Serial.println(F("Homing the servo"));
  #endif
  servo_controller.home(true);

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
  handel_error(servo_controller.load_animation("prova_motori.txt", 0), "Failed to load prova_motori.txt");
  #else
  handel_error(servo_controller.load_animation("prova_motori.txt", 0));
  #endif
  
  while(true){
    #ifdef DEBUG
    Serial.println(F("Executing scheduler"));
    #endif
    #ifdef DEBUG
    handel_error(scheduler.executeAll(), "Failed to execute scheduler");
    #else
    handel_error(scheduler.executeAll());
    #endif
  }
}
