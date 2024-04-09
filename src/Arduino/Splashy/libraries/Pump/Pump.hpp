/**
 * @file Pump.hpp
 * @brief Defines the Pump class and related variables and constants.
 * @version 1.1
 */

#ifndef __PUMP__
#define __PUMP__

#ifdef DEBUG
#define PUMP_DEBUG
#define PUMP_SIMULATION
#endif

#define FLOW_SENSOR_CONSTANT 0.001 ///< The constant to convert flow sensor pulses to litres.

#define MINUMUM_WATER_DISPENSED 0.2 ///< Minimum amount of water that can be dispensed in litres.
#define MAXIMUM_WATER_DISPENSED 1.5 ///< Maximum amount of water that can be dispensed in litres.

#include <Arduino.h>
#include "../Config/Config.hpp"
#include "../TaskManagement/TaskManagement.hpp"
#include "../Core/Core.hpp"

volatile unsigned int _pulse_count = 0.0; ///< The count of pulses from the flow sensor.

/**
 * @class Pump
 * @brief A class to control a water pump.
 * 
 * This class extends the Task class and provides methods to activate the pump, check if the pump is active, and manage the dispensing of water.
 */
class Pump: public Task {
    private:
        float water_dispensed; ///< The amount of water that has been dispensed in litres.
        float target_water_dispensed; ///< The target amount of water to dispense in litres.
        bool pump_active; ///< A flag to indicate whether the pump is currently active.

        /**
         * @brief Get the quantity of water to be dispensed from the user.
         * 
         * This method should be implemented to get the target quantity of water from the user.
         */
        void get_user_water_quantity();

    public:
        /**
         * @brief Construct a new Pump object.
         * 
         * @param name The name of the task.
         */
        Pump(const char* name);

        /**
         * @brief Perform the next step in the task.
         * 
         * This method should be implemented to perform the next step in the task.
         * 
         * @return true if the task is complete, false otherwise.
         */
        bool next() override;

        /**
         * @brief Put the task into a hibernation state.
         * 
         * This method should be implemented to put the task into a hibernation state.
         */
        void hibernate() override;

        /**
         * @brief Activate the task.
         * 
         * This method should be implemented to activate the task.
         * 
         * @return true if the task was successfully activated, false otherwise.
         */
        bool activate() override;

        /**
         * @brief Activate the pump.
         * 
         * This method should be implemented to activate the pump.
         */
        void activate_pump();

        /**
         * @brief Check if the pump is active.
         * 
         * @return true if the pump is active, false otherwise.
         */
        bool is_pump_active();
};

#endif