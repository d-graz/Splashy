//#define CSPIN 5 // Uncomment this line to use a custom CS pin for the SD card


//libraries in release mode
#include <SD.h>
#include <SPI.h>

#define DEBUG

//libraries in debug mode
#include "libraries/Animations/Animations.hpp"

// define
#define BAUD_RATE 9600

void setup() {
  // start serial communication
  Serial.begin(BAUD_RATE);

  // create a new animation object
  Animations animation = Animations();
  //TODO: create a hardware new matrix led object

  // check sd card status
  if(!check_sd_status()){
    //TODO: display error message on the led matrix
  }

  // load loading animation
  //TODO: load the animation and display it on the led matrix

}

void loop() {
  // put your main code here, to run repeatedly:

}

// function to check sd card status
bool check_sd_status(){
  bool sd_status;
    #ifdef DEBUG
    Serial.println("Opening animation");
    #endif
    #ifdef CSPIN
    sd_status = SD.begin(CSPIN);
    #else
    sd_status = SD.begin();
    #endif
    if(!sd_status){
        #ifdef DEBUG
        Serial.println("SD card failed to initialize");
        #endif
        return false;
    }
    return true;
}