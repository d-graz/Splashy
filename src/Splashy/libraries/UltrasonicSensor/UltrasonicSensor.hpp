/**
 * @file UltrasonicSensor.hpp
 * @brief Header file for the UltrasonicSensor class.
 * @version 1.0
 */

#ifndef __ULTRASONICSENSOR__
#define __ULTRASONICSENSOR__

#include<NewPing.h>
#include "../Config/Config.hpp"
#include "../TaskManagement/TaskManagement.hpp"

#ifdef DEBUG
#define ULTRASONIC_SENSOR_DEBUG
#endif

#define SLEEP_TIME 50 ///< Time to sleep after not detecting an object.
#define TRIGGERING_DISTANCE 3 ///< Distance in cm that triggers the ultrasonic sensor.
#define MAX_DISTANCE 15 ///< Maximum distance in cm that the ultrasonic sensor can detect.
#define FILTER_SIZE 9 ///< Size of the filter to smooth the distance readings.
#define FILTER_UPDATE_SIZE 3 ///< Number of distance readings to update the filter. Note: FILTER_SIZE % FILTER_UPDATE_SIZE == 0

/**
 * @class UltrasonicSensor
 * @brief A class that represents an ultrasonic sensor.
 *
 * This class is a task that checks if an object is detected by the ultrasonic sensor.
 */
class UltrasonicSensor : public Task {
    private:
        NewPing sonar; ///< NewPing object to interact with the ultrasonic sensor.
        bool object_detected; ///< Flag to indicate if an object has been detected.
        float filter[FILTER_SIZE]; ///< Filter to smooth the distance readings.
        byte filter_index = 0; ///< Index to update the filter.

        /**
         * @brief Update the filter with the new distance reading.
         * @return The filtered distance.
         */
        float get_distance(); 

    public:
        /**
         * @brief Constructor for the UltrasonicSensor class.
         * Initializes the sonar object and the filter array.
         */
        UltrasonicSensor();

        /**
         * @brief Override the next method from the Task class.
         * Updates the filter with new distance readings and checks if an object is detected.
         * @return true if the task was successful, false otherwise.
         */
        bool next() override;

        /**
         * @brief Check if an object has been detected by the ultrasonic sensor.
         * @return true if an object has been detected, false otherwise.
         */
        bool is_water_bottle_detected();
};

#endif