// ####################### LIBRARIES ###########################
// release libraries
#include "libraries/Config/Config.hpp"


#define DEBUG
//#define WARN
//#define TEST 
// debug libraries
#include "libraries/LedMatrix/LedMatrix.hpp"
#include "libraries/LedMatrix/LedMatrix.cpp"
#include "libraries/MySD/MySD.hpp"
#include "libraries/MySD/MySD.cpp"
#include "libraries/TaskManagement/TaskManagement.hpp"
#include "libraries/TaskManagement/TaskManagement.cpp"
#include "libraries/ServoController/ServoController.hpp"
#include "libraries/ServoController/ServoController.cpp"
#include "libraries/UltrasonicSensor/UltrasonicSensor.hpp"
#include "libraries/UltrasonicSensor/UltrasonicSensor.cpp"
#include "libraries/ProximitySensor/ProximitySensor.hpp"
#include "libraries/ProximitySensor/ProximitySensor.cpp"
#include "libraries/FiniteStateMachine/FiniteStateMachine.hpp"
#include "libraries/FiniteStateMachine/FiniteStateMachine.cpp"
#include "libraries/Pump/Pump.hpp"
#include "libraries/Pump/Pump.cpp"
#include "libraries/TouchSensor/TouchSensor.hpp"
#include "libraries/TouchSensor/TouchSensor.cpp"
#include "libraries/Config/Global.hpp"
#include "libraries/Core/Core.hpp"
#include "libraries/Core/Core.cpp"


// ######################## DEFINE #############################
#define BAUD_RATE 9600

// ##################### GLOBAL VARS ###########################
// scheduler
Scheduler *scheduler;

// fsm
FiniteStateMachine *fsm;


// ##################### SETUP #################################
void setup() {
  // start serial communication
  Serial.begin(BAUD_RATE);
  delay(2000);
  #ifdef DEBUG
    Serial.println(F("Init setup"));
    #ifdef TEST
      delay(1000);
    #endif
  #endif

  //init the scheduler
  scheduler = new Scheduler();

  //init the led matrix early to enable error handling
  #ifdef DEBUG
    Serial.println(F("Init LedMatrix"));
  #endif
  led_matrix = new LedMatrix("Led");
  handle_error(scheduler->add_task(led_matrix), F("Failed to add LedMatrix to the scheduler"));

  //init the sd card early to load boot animation
  #ifdef DEBUG
    #ifdef TEST
      delay(1000);
    #endif
    Serial.println(F("Init SD card"));
  #endif
  handle_error(init_sd(), F("Failed to initialize SD card"));

  //load the boot animation
  #ifdef DEBUG
    #ifdef TEST
      delay(1000);
    #endif
    Serial.println(F("Loading boot animation"));
  #endif
  handle_error(led_matrix->load_animation(LedMatrixAnimation::Boot), F("Failed to load boot animation"));
  handle_error(scheduler->executeByName(F("Led"), 3), F("Failed to execute LedMatrix"));

  //init the servo controller
  #ifdef DEBUG
    #ifdef TEST
      delay(1000);
    #endif
    Serial.println(F("Init ServoController, adding to the scehduler and homing the servo"));
  #endif
  servo_controller = new ServoController("Servo");
  handle_error(scheduler->add_task(servo_controller), F("Failed to add ServoController to the scheduler"));
  handle_error(scheduler->executeByName(F("Led")), F("Failed to execute LedMatrix"));
  servo_controller->home(true);
  handle_error(scheduler->executeByName(F("Led"), 3), F("Failed to execute LedMatrix"));

  //testing servo motors if test
  #ifdef DEBUG
    #ifdef TEST
      Serial.println(F("Testing servo motors"));
      handle_error(servo_controller->load_animation(ServoMotorAnimation::Test), F("Failed to load test animation for servocontroller"));
      while(servo_controller->get_status() != TaskStatus::HIBERNATED){
        handle_error(scheduler->executeAll(), F("Failed to execute the scheduler"));
      }
      Serial.println(F("Test done"));
      Serial.println(F("Continuing the boot process"));
    #endif
  #endif

  //init the ultrasonic sensor
  #ifdef DEBUG
    #ifdef TEST
      delay(1000);
    #endif
    Serial.println(F("Init UltrasonicSensor and adding to the scheduler"));
  #endif
  ultrasonic_sensor = new UltrasonicSensor("Usonic");
  handle_error(scheduler->executeByName(F("Led")), F("Failed to execute LedMatrix"));
  handle_error(scheduler->add_task(ultrasonic_sensor), F("Failed to add UltrasonicSensor to the scheduler"));
  handle_error(scheduler->executeByName(F("Led"), 3), F("Failed to execute LedMatrix"));

  //init the proximity sensor
  #ifdef DEBUG
    #ifdef TEST
      delay(1000);
    #endif
    Serial.println(F("Init ProximitySensor and adding to the scheduler"));
  #endif
  proximity_sensor = new ProximitySensor("Prox");
  handle_error(scheduler->executeByName(F("Led")), F("Failed to execute LedMatrix"));
  handle_error(scheduler->add_task(proximity_sensor), F("Failed to add ProximitySensor to the scheduler"));
  handle_error(scheduler->executeByName(F("Led"), 3), F("Failed to execute LedMatrix"));

  //init the pump
  #ifdef DEBUG
    #ifdef TEST
      delay(1000);
    #endif
    Serial.println(F("Init Pump and adding to the scheduler"));
  #endif
  pump = new Pump("Pump");
  handle_error(scheduler->executeByName(F("Led")), F("Failed to execute LedMatrix"));
  handle_error(scheduler->add_task(pump), F("Failed to add Pump to the scheduler"));
  handle_error(scheduler->executeByName(F("Led")), F("Failed to execute LedMatrix"));

  //init the touch sensor
  #ifdef DEBUG
    #ifdef TEST
      delay(1000);
    #endif
    Serial.println(F("Init TouchSensor and adding to the scheduler"));
  #endif
  touch_sensor = new TouchSensor("Touch");
  handle_error(scheduler->executeByName(F("Led")), F("Failed to execute LedMatrix"));
  handle_error(scheduler->add_task(touch_sensor), F("Failed to add TouchSensor to the scheduler"));
  handle_error(scheduler->executeByName(F("Led"), 3), F("Failed to execute LedMatrix"));

  //init the fsm
  #ifdef DEBUG
    #ifdef TEST
      delay(1000);
    #endif
    Serial.println(F("Init FiniteStateMachine"));
  #endif
  fsm = new FiniteStateMachine();
  handle_error(scheduler->executeByName(F("Led"), 2), F("Failed to execute LedMatrix"));

  // activating proximity sensor, ultrasonic sensor and proximity before entering the loop in IDLE status
  #ifdef DEBUG
    #ifdef TEST
      delay(1000);
    #endif
    Serial.println(F("Activating proximity sensor and ultrasonic sensor before entering the loop in IDLE status"));
  #endif
  handle_error(proximity_sensor->activate(), F("Failed to activate proximity sensor"));
  handle_error(ultrasonic_sensor->activate(), F("Failed to activate ultrasonic sensor"));
  handle_error(touch_sensor->activate(), F("Failed to activate touch sensor"));
  handle_error(scheduler->executeByName(F("Led"), 3), F("Failed to execute LedMatrix"));

  //load the idle animation facial expression
  handle_error(led_matrix->load_animation(LedMatrixAnimation::Idle), F("Failed to load idle animation"));

  #ifdef DEBUG
    Serial.println(F("Setup done"));
    #ifdef TEST
      delay(1000);
    #endif
  #endif

}


// ######################## LOOP ###############################
void loop() {
  // execute the fsm
  #ifdef DEBUG
    #ifdef WARN
      Serial.println(F("Executing the FSM"));
    #endif
  #endif
  fsm->next();

  // execute the scheduler
  #ifdef DEBUG
    #ifdef WARN
      Serial.println(F("Executing the scheduler"));
    #endif
  #endif
  handle_error(scheduler->executeAll(), F("Failed to execute the scheduler"));

  #ifdef DEBUG
    #ifdef TEST
      delay(5000);
    #endif
  #endif

}
