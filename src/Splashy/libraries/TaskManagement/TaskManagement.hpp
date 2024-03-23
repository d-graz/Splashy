/**
 * @file TaskManagement.hpp
 * @brief Task management library for Arduino.
 * @version 1.0
 */
//TODO: [LOW] Explore the usage of static task list instead of dynamic allocation

#ifndef __TASKMANAGEMENT__
#define __TASKMANAGEMENT__

#include <Arduino.h>

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

class Task;

/**
 * @struct task_list
 * @brief Structure for a node in the task list.
 */
typedef struct task_list {
    Task* task;          /**< Pointer to the task. */
    task_list* next;     /**< Pointer to the next node in the list. */
} task_list_t;

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
        unsigned int next_execution_millis;  /**< Time for the next execution of the task. */
        unsigned int sleep_time_millis;      /**< Next sleep time between executions of the task. */

        /**
         * @brief Updates the time for the next execution of the task.
         */
        void update_next_execution_millis();

    public:
        /**
         * @brief Constructor.
         */
        Task();

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
        task_list_t* task_list;     /**< Pointer to the first task in the list. */
        task_list_t* current_task;  /**< Pointer to the current task. */
        bool need_clean;            /**< Flag indicating whether the task list needs to be cleaned. */

        /**
         * @brief Cleans the task list by removing dead tasks.
         */
        void clean();

        /**
         * @brief Deletes a task from the task list.
         *
         * @param task Pointer to the task to delete.
         */
        void delete_task(task_list_t* task);

    public:
        /**
         * @brief Constructor.
         */
        Scheduler ();

        /**
         * @brief Adds a task to the task list.
         *
         * @param task Pointer to the task to add.
         */
        void add_task(Task* task);

        /**
         * @brief Executes one task.
         *
         * This method executes the next task in the list that is ready.
         *
         * @return true if the task was executed successfully, false otherwise.
         */
        bool executeOne();

        /**
         * @brief Executes all tasks.
         *
         * This method executes all tasks in the list that are ready.
         *
         * @return true if all tasks were executed successfully, false if any task failed.
         */
        bool executeAll();

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
         * @brief Asserts the size of the task list.
         *
         * This method checks if the size of the task list is equal to the specified size.
         *
         * @param list_size The expected size of the task list.
         * @return true if the size of the task list is equal to list_size, false otherwise.
         */
        bool assertSize(byte list_size);
};

#endif