#include "TaskManagement.hpp"

Task::Task(){
    this->status = TaskStatus::HIBERNATED;
    this->next_execution_millis = 0;
    this->sleep_time_millis = 0;
}

TaskStatus Task::get_status(){
    unsigned int milliseconds = millis();
    if(this->status == TaskStatus::WAITING && milliseconds >= this->next_execution_millis){
        this->status = TaskStatus::READY;
    }
    return this->status;

}

void Task::kill(){
    this->status = TaskStatus::DEAD;
}

void Task::update_next_execution_millis(){
    this->status = TaskStatus::WAITING;
    this->next_execution_millis = millis() + this->sleep_time_millis;
}

Scheduler::Scheduler(){
    this->task_count = 0;
    for (byte i = 0; i < MAX_CONCURRENT_TASKS; i++){
        this->task_list[i] = nullptr;
    }
}

bool Scheduler::add_task(Task* task){
    if (this->task_count == MAX_CONCURRENT_TASKS){
        #ifdef DEBUG
        Serial.println(F("Maximum number of tasks reached"));
        #endif
        return false;
    }
    byte i = 0;
    while (this->task_list[i] != nullptr){
        i++;
    }
    this->task_list[i] = task;
    this->task_count++;
    #ifdef SCHEDULER_DEBUG
    Serial.print(F("Task added at index "));
    Serial.println(i);
    Serial.print(F("Task count: "));
    Serial.println(this->task_count);
    #endif
    return true;
}

void Scheduler::delete_task(Task* task_to_delete) {
    byte i = 0;
    while (this->task_list[i] != task_to_delete && i < MAX_CONCURRENT_TASKS){
        i++;
    }
    if(this->task_list[i] == task_to_delete){
        this->task_list[i] = nullptr;
        this->task_count--;
    }
    #ifdef DEBUG
    else 
    {
        Serial.println(F("BAD ERROR HAPPEN IN SCHEDULER!!"));
        Serial.println(F("Task for deletion not found!!"));
    }
    #endif
}

void Scheduler::clean() {
    for(byte i = 0; i < MAX_CONCURRENT_TASKS; i++){
        if(this->task_list[i] != nullptr && this->task_list[i]->get_status() == TaskStatus::DEAD){
            this->delete_task(this->task_list[i]);
        }
    }
}

void Scheduler::forceClean() {
    if(this->need_clean) {
        this->clean();
        this->need_clean = false;
    }
    #ifdef SCHEDULER_DEBUG
    else
    {
        Serial.println(F("No need to clean"));
    }
    #endif
}

void Scheduler::killAll() {
    for(byte i = 0; i < MAX_CONCURRENT_TASKS; i++){
        if(this->task_list[i] != nullptr){
            this->task_list[i]->kill();
        }
    }
    this->need_clean = true;
}

//FIXME: [HIGH] need to skip the task that are not ready + update in case clean istance
//bool Scheduler::executeOne() {
//    if(this->current_task == nullptr) {
//        return true;
//    }
//    bool r = this->current_task->task->next();
//    this->current_task = this->current_task->next;
//    return r;
//}

bool Scheduler::executeAll() {
    bool control, empty_execution = true;
    for(byte i = 0; i < MAX_CONCURRENT_TASKS; i++){
        if(this->task_list[i] != nullptr){
            #ifdef SCHEDULER_DEBUG
            Serial.print(F("Checking task at index"));
            Serial.println(i);
            #endif
            TaskStatus status = this->task_list[i]->get_status();
            #ifdef SCHEDULER_DEBUG
            Serial.print(F("Task status: "));
            Serial.println(task_status_to_string(status));
            #endif
            if(status == TaskStatus::READY){
                #ifdef SCHEDULER_DEBUG
                Serial.print(F("Executing task "));
                Serial.println(i);
                #endif
                empty_execution = false;
                control = this->task_list[i]->next();
                if(!control){
                    #ifdef DEBUG
                    Serial.print(F("Error executing task "));
                    Serial.println(i);
                    #endif
                    return false;
                }
            } else if (status == TaskStatus::DEAD){
                this->need_clean = true;
            }
        }
    }
    #ifdef SCHEDULER_DEBUG
    if(empty_execution){
        Serial.println(F("No task executed"));
    } else {
        Serial.println(F("All tasks executed successfully"));
    }
    if(this->need_clean){
        Serial.println(F("Need to clean the task list"));
    }
    #endif
    if (empty_execution && this->need_clean){
        #ifdef SCHEDULER_DEBUG
        Serial.println(F("Cleaning the task list"));
        #endif
        this->clean();
    }
    return true;
}

bool Scheduler::executeAll(byte loop_count){
    for(byte i = 0; i < loop_count; i++) {
        if(!this->executeAll()) {
            #ifdef DEBUG
            Serial.print(F("Error executing all tasks in loop "));
            Serial.println(i);
            #endif
            return false;
        }
    }
    return true;
}