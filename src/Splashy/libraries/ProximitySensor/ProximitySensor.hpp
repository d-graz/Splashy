/**
 * @file ProximitySensor.hpp
 * @brief Header file for the ProximitySensor class.
 * @version 1.0
 */

#ifndef __PROXIMITYSENSOR__
#define __PROXIMITYSENSOR__

#include "../Config/Config.hpp"
#include "../TaskManagement/TaskManagement.hpp"

#ifdef DEBUG
#define PROXIMITY_SENSOR_DEBUG
#endif

//TODO: define sleep time after detection
#define SLEEP_AFTER_DETECTION 600000 ///< Time to sleep after detecting an object.
#define SLEEP_AFTER_NO_DETECTION 150 ///< Time to sleep after not detecting an object.

/**
 * @class ProximitySensor
 * @brief A class that represents a proximity sensor.
 *
 * This class is a task that checks if an object is detected by the proximity sensor.
 */
class ProximitySensor : public Task {
    private:
        bool object_detected; ///< Flag to indicate if an object has been detected.
    public:
        /**
         * @brief Constructor for the ProximitySensor class.
         */
        ProximitySensor();

        /**
         * @brief Override the next method from the Task class.
         * @return true if the task was successful, false otherwise.
         */
        bool next() override;

        /**
         * @brief Check if a person has been detected by the proximity sensor.
         * @return true if a person has been detected, false otherwise.
         */
        bool is_person_detected();
};

#endif