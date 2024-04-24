/**
 * @file TouchSensor.hpp
 * @brief This file contains the declaration of the TouchSensor class.
 * @version 1.1
*/
#ifndef __TOUCH_SENSOR__
#define __TOUCH_SENSOR__

#include <CapacitiveSensor.h>
#include "../Config/Config.hpp"
#include "../TaskManagement/TaskManagement.hpp"

#ifdef DEBUG
#define TOUCH_SENSOR_DEBUG
#endif

//TODO: [TEST] scoprire la causa delle oscillazioni + test del nuovo filtro
#define SAMPLES 1500 ///< The number of samples to take when reading the touch sensor.
#define THRESHOLD 200 ///< The threshold value for the touch sensor to be recognized as active.
#define SLEEP_TIME 200 ///< The time to sleep between samples in milliseconds.
#define FILTER_SIZE_TS 4 ///< The size of the filter to use when smoothing the sensor readings.
#define FILTER_UPDATE_SIZE_TS 2 ///< The number of samples to use when updating the filter.

/**
 * @class TouchSensor
 * @brief This class represents a touch sensor.
 * 
 * The TouchSensor class extends the Task class and provides methods for checking if the touch sensor is active.
 */
class TouchSensor: public Task {
    private:
        CapacitiveSensor sensor; ///< The capacitive sensor object.
        unsigned int samples[SAMPLES]; ///< The array of samples taken from the sensor.
        byte index; ///< The current index in the samples array.
        bool touch; ///< A flag to indicate whether the touch sensor is currently active.

        /**
         * @brief Get the filtered value of the sensor.
         * 
         * This method calculates the filtered value of the sensor by taking the average of the samples in the filter.
         * 
         * @return The filtered value of the sensor.
         */
        float get_filtered_value();

    public:
        /**
         * @brief Construct a new TouchSensor object.
         * 
         * This constructor creates a new TouchSensor object with the given name.
         * 
         * @param name The name of the task.
         */
        TouchSensor(const char* name);

        /**
         * @brief Perform the next step in the task.
         * 
         * This method should be implemented to perform the next step in the task. It is called periodically by the task manager.
         * 
         * @return true if the task is complete, false otherwise.
         */
        bool next() override;

        /**
         * @brief Check if the touch sensor is active.
         * 
         * This method checks if the touch sensor is currently active. It does this by reading the value from the capacitive sensor and comparing it to a threshold.
         * 
         * @return true if the touch sensor is active, false otherwise.
         */
        bool is_active();
};

#endif