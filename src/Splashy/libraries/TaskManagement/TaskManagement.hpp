#ifndef __TASKMANAGEMENT__
#define __TASKMANAGEMENT__

#include <Arduino.h>

enum TaskStatus {
    READY,
    WAITING,
    DEAD,
    HIBERNATED
};

class Task;

typedef struct task_list {
    Task* task;
    task_list* next;
    task_list* prev;
} task_list_t;

class Task {
    protected:
        TaskStatus status;
        unsigned int next_execution_millis;
        unsigned int sleep_time_millis;
        void update_next_execution_millis();
    public:
        Task();
        virtual bool next() = 0;
        TaskStatus get_status();
        void kill();
};

class Kernel {
    private:
        task_list_t* task_list;
        task_list_t* current_task;
        void clean();
    public:
        Kernel();
        void add_task(Task* task);
        bool executeOne();
        bool executeAll();
        void killAll();
        void forceClean();
};

#endif