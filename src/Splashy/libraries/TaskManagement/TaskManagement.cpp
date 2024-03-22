#include "TaskManagement.hpp"

Task::Task(){
    this->status = TaskStatus::READY;
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