/**
 * @file ProximitySensor.hpp
 * @brief Header file for the ProximitySensor class.
 * @version 1.2
 */

#ifndef __PROXIMITYSENSOR__
#define __PROXIMITYSENSOR__

#include "../Config/Config.hpp"
#include "../TaskManagement/TaskManagement.hpp"

#ifdef DEBUG
//#define PROXIMITY_SENSOR_DEBUG
//#define PROXIMITY_SENSOR_SIMULATION
#endif

//TODO: [TEST] see if 3000 ms is ok
#define SLEEP_TIME 3000 ///< Time to sleep (Minumum 3s, hardware imposed).

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
         * @brief Constructor for ProximitySensor class.
         *
         * Initializes a new instance of the ProximitySensor class with a given name.
         *
         * @param name The name of the task. This is passed to the base Task class.
         */
        ProximitySensor(const char* name);

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