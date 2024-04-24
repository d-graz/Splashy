/**
 * @file TaskManagement.hpp
 * @brief Task management library for Arduino.
 * @version 2.8
 */

#ifndef __TASKMANAGEMENT__
#define __TASKMANAGEMENT__

#include <Arduino.h>

#ifdef DEBUG
//#define TASK_DEBUG ///< Enable fine grained debugging for the Task management operations.
//#define SCHEDULER_DEBUG ///< Enable fine grained debugging for the Scheduler operations.
#endif

#define MAX_CONCURRENT_TASKS 6 ///< Maximum number of concurrent tasks.

#define TASK_NAME_LENGTH 10 ///< Maximum length of a task name.

/**
 * @enum TaskStatus
 * @brief Enumeration for the status of a task.
 */
enum TaskStatus {
    READY,       /**< Task is ready to be executed. */
    WAITING,     /**< Task is waiting for its next execution. */
    DEAD,        /**< Task has finished its execution and can be removed. */
    HIBERNATED   /**< Task is temporarily paused and will not be executed. */
};

#ifdef DEBUG
const char* task_status_to_string(TaskStatus status){
    switch (status){
        case TaskStatus::READY:
            return "READY";
        case TaskStatus::WAITING:
            return "WAITING";
        case TaskStatus::DEAD:
            return "DEAD";
        case TaskStatus::HIBERNATED:
            return "HIBERNATED";
        default:
            return "UNKNOWN";
    }
}
#endif

/**
 * @class Task
 * @brief Base class for tasks.
 *
 * This class provides the basic functionality for a task, including
 * managing its status and execution time, and executing the task.
 */
class Task {
    protected:
        TaskStatus status;                   /**< Current status of the task. */
        unsigned long int next_execution_millis;  /**< Time for the next execution of the task. */
        unsigned long int sleep_time_millis;      /**< Next sleep time between executions of the task. */
        char name[TASK_NAME_LENGTH];         /**< Name of the task. */

        /**
         * @brief Updates the time for the next execution of the task.
         */
        void update_next_execution_millis();

    public:
        /**
         * @brief Constructor for Task class.
         *
         * Initializes a new instance of the Task class with a given name.
         *
         * @param name The name of the task. This is stored internally and can be retrieved with the get_name() method.
         */
        Task(const char* name);

        /**
         * @brief Executes the task.
         *
         * This method must be implemented in derived classes.
         *
         * @return true if the task was executed successfully, false otherwise.
         */
        virtual bool next() = 0;

        /**
         * @brief Returns the current status of the task.
         *
         * @return The current status of the task.
         */
        TaskStatus get_status();

        /**
         * @brief Kills the task.
         *
         * This sets the status of the task to DEAD.
         */
        void kill();

        /**
         * @brief Hibernates the task.
         *
         * This sets the status of the task to HIBERNATED.
         */
        virtual void hibernate();

        /**
         * @brief Activates the task.
         *
         * This sets the status of the task to READY.
         *
         * @return true if the task was activated successfully, false otherwise.
         */
        virtual bool activate();

        /**
         * @brief Returns the name of the task.
         *
         * @return The name of the task.
         */
        const char* get_name();
};

/**
 * @class Scheduler
 * @brief Class for scheduling and executing tasks.
 *
 * This class manages a list of tasks and provides methods for adding tasks,
 * executing tasks, and cleaning up finished tasks.
 */
class Scheduler {
    private:
        Task* task_list[MAX_CONCURRENT_TASKS];     /**< Array of pointers to Task objects. */
        byte task_count;                           /**< Number of task present in the scheduler */
        bool need_clean;                           /**< Flag indicating whether the task list needs to be cleaned. */

        /**
         * @brief Cleans the task list by removing dead tasks.
         */
        void clean();

        /**
         * @brief Deletes a task from the task list.
         *
         * @param task Pointer to the task to delete.
         */
        void delete_task(Task* task);

    public:
        /**
         * @brief Constructor.
         */
        Scheduler ();

        /**
         * @brief Adds a task to the task list.
         *
         * @param task Pointer to the task to add.
         * 
         * @return true if the task was added successfully, false otherwise.
         */
        bool add_task(Task* task);

        /**
         * @brief Executes all tasks.
         *
         * This method executes all tasks in the list that are ready.
         *
         * @return true if all tasks were executed successfully, false if any task failed.
         */
        bool executeAll();

        /**
         * @brief Executes all tasks a specified number of times.
         *
         * This method executes all tasks in the list that are ready a specified number of times.
         *
         * @param loop_count The number of times to execute all tasks.
         * @return true if all tasks were executed successfully, false if any task failed.
         */
        bool executeAll(byte loop_count);

        /**
         * @brief Kills all tasks.
         *
         * This method sets the status of all tasks in the list to DEAD.
         */
        void killAll();

        /**
         * @brief Forces a clean of the task list.
         *
         * This method immediately cleans the task list by removing all dead tasks.
         */
        void forceClean();

        /**
         * @brief Executes a task by its name.
         *
         * This method allows to execute a task by providing its name. The task will be executed a specified number of times.
         *
         * @param name The name of the task to be executed.
         * @param loop_count The number of times the task should be executed. Default is 1.
         * @return true if the task was executed successfully, false otherwise.
         */
        bool executeByName(String name, byte loop_count = 1);
};

#endif