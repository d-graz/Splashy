#ifndef __TOUCH_SENSOR__
#define __TOUCH_SENSOR__

#include <CapacitiveSensor.h>
#include "../Config/Config.hpp"
#include "../TaskManagement/TaskManagement.hpp"

#ifdef DEBUG
#define TOUCH_SENSOR_DEBUG
#endif

#define SAMPLES 1500 ///< The number of samples to take when reading the touch sensor.
#define THRESHOLD 75 ///< The threshold value for the touch sensor to be recognized as active.
#define SLEEP_TIME 200 ///< The time to sleep between samples in milliseconds.

class TouchSensor: public Task {
    private:
        CapacitiveSensor sensor; ///< The capacitive sensor object.
        bool touch; ///< A flag to indicate whether the touch sensor is currently active.

    public:
        /**
         * @brief Construct a new TouchSensor object.
         * 
         * @param name The name of the task.
         */
        TouchSensor(const char* name);

        /**
         * @brief Perform the next step in the task.
         * 
         * This method should be implemented to perform the next step in the task.
         * 
         * @return true if the task is complete, false otherwise.
         */
        bool next() override;

        /**
         * @brief Check if the touch sensor is active.
         * 
         * @return true if the touch sensor is active, false otherwise.
         */
        bool is_active();
};

#endif
