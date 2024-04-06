// ####################### LIBRARIES ###########################
// release libraries
#include "libraries/Config/Config.hpp"


#define DEBUG
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
  #ifdef DEBUG
  // start serial communication
  Serial.begin(BAUD_RATE);
  delay(2000);
  Serial.println(F("Init setup"));
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
  Serial.println(F("Init SD card"));
  #endif
  handle_error(init_sd(), F("Failed to initialize SD card"));

  //load the boot animation
  #ifdef DEBUG
  Serial.println(F("Loading boot animation"));
  #endif
  handle_error(led_matrix->load_animation(LedMatrixAnimation::Boot), F("Failed to load boot animation"));
  handle_error(scheduler->executeByName(F("Led"), 3), F("Failed to execute LedMatrix"));

  //init the servo controller
  #ifdef DEBUG
  Serial.println(F("Init ServoController, adding to the scehduler and homing the servo"));
  #endif
  servo_controller = new ServoController("Servo");
  handle_error(scheduler->add_task(servo_controller), F("Failed to add ServoController to the scheduler"));
  handle_error(scheduler->executeByName(F("Led")), F("Failed to execute LedMatrix"));
  servo_controller->home(true);
  handle_error(scheduler->executeByName(F("Led"), 3), F("Failed to execute LedMatrix"));

  //init the ultrasonic sensor
  #ifdef DEBUG
  Serial.println(F("Init UltrasonicSensor and adding to the scheduler"));
  #endif
  ultrasonic_sensor = new UltrasonicSensor("Usonic");
  handle_error(scheduler->executeByName(F("Led")), F("Failed to execute LedMatrix"));
  handle_error(scheduler->add_task(ultrasonic_sensor), F("Failed to add UltrasonicSensor to the scheduler"));
  handle_error(scheduler->executeByName(F("Led"), 3), F("Failed to execute LedMatrix"));

  //init the proximity sensor
  #ifdef DEBUG
  Serial.println(F("Init ProximitySensor and adding to the scheduler"));
  #endif
  proximity_sensor = new ProximitySensor("Prox");
  handle_error(scheduler->executeByName(F("Led")), F("Failed to execute LedMatrix"));
  handle_error(scheduler->add_task(proximity_sensor), F("Failed to add ProximitySensor to the scheduler"));
  handle_error(scheduler->executeByName(F("Led"), 3), F("Failed to execute LedMatrix"));

  //init the pump
  #ifdef DEBUG
  Serial.println(F("Init Pump and adding to the scheduler"));
  #endif
  pump = new Pump("Pump");
  handle_error(scheduler->executeByName(F("Led")), F("Failed to execute LedMatrix"));
  handle_error(scheduler->add_task(pump), F("Failed to add Pump to the scheduler"));
  handle_error(scheduler->executeByName(F("Led")), F("Failed to execute LedMatrix"));

  //init the fsm
  #ifdef DEBUG
  Serial.println(F("Init FiniteStateMachine"));
  #endif
  fsm = new FiniteStateMachine();
  handle_error(scheduler->executeByName(F("Led"), 2), F("Failed to execute LedMatrix"));

  // activating proximity sensor and ultrasonic sensor before entering the loop in IDLE status
  #ifdef DEBUG
  Serial.println(F("Activating proximity sensor and ultrasonic sensor before entering the loop in IDLE status"));
  #endif
  handle_error(proximity_sensor->activate(), F("Failed to activate proximity sensor"));
  handle_error(ultrasonic_sensor->activate(), F("Failed to activate ultrasonic sensor"));
  handle_error(scheduler->executeByName(F("Led"), 2), F("Failed to execute LedMatrix"));

  //load the idle animation facial expression
  handle_error(led_matrix->load_animation(LedMatrixAnimation::Idle), F("Failed to load idle animation"));
  //TODO: [EXTERN] servo motor animation for idle ?

  #ifdef DEBUG
  Serial.println(F("Setup done"));
  #endif

  

}


// ######################## LOOP ###############################
void loop() {
  // execute the fsm
  #ifdef DEBUG
  Serial.println(F("Executing the FSM"));
  #endif
  fsm->next();

  // execute the scheduler
  #ifdef DEBUG
  Serial.println(F("Executing the scheduler"));
  #endif
  handle_error(scheduler->executeAll(), F("Failed to execute the scheduler"));
}
