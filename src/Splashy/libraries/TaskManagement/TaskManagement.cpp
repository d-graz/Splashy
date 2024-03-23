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
    this->task_list = nullptr;
    this->current_task = nullptr;
    this->need_clean = false;
}

void Scheduler::add_task(Task* task){
    task_list_t* new_task = new task_list_t;
    new_task->task = task;

    if(this->task_list == nullptr){
        new_task->next = new_task;
        this->task_list = new_task;
        this->current_task = new_task;
    } else {
        task_list_t* runner;
        for(runner = this->task_list; runner->next != this->task_list; runner = runner->next);
        runner->next = new_task;
        new_task->next = this->task_list;
    }
}

void Scheduler::delete_task(task_list_t* task_to_delete) {
    if(this->task_list == nullptr) {
        return;
    }
    task_list_t* runner = this->task_list;
    if(runner == task_to_delete) {
        if(runner->next == this->task_list) {
            this->task_list = nullptr;
        } else {
            task_list_t* last_node;
            for(last_node = this->task_list; last_node->next != this->task_list; last_node = last_node->next);
            last_node->next = runner->next;
            this->task_list = runner->next;
        }
        delete runner;
        return;
    }
    while(runner->next != task_to_delete && runner->next != this->task_list) {
        runner = runner->next;
    }
    if(runner->next == this->task_list) {
        return;
    }
    task_list_t* temp = runner->next;
    runner->next = temp->next;
    delete temp;
}

void Scheduler::clean() {
    if(this->task_list == nullptr) {
        return;
    }
    task_list_t* runner = this->task_list;
    do {
        task_list_t* next = runner->next;
        if(next->task->get_status() == TaskStatus::DEAD) {
            if(next == this->task_list) {
                this->task_list = next->next;
            }
            runner->next = next->next;
            delete next;
        } else {
            runner = next;
        }
    } while(runner != this->task_list);
    if(this->task_list->task->get_status() == TaskStatus::DEAD) {
        task_list_t* next = this->task_list->next;
        if(this->task_list == next) {
            this->task_list = nullptr;
        } else {
            this->task_list = next;
        }
        delete this->task_list;
    }
}

void Scheduler::forceClean() {
    if(this->need_clean) {
        this->clean();
        this->need_clean = false;
    }
}

void Scheduler::killAll() {
    if(this->task_list == nullptr) {
        return;
    }
    this->need_clean = true;
    task_list_t* runner = this->task_list;
    do {
        runner->task->kill();
        runner = runner->next;
    } while(runner != this->task_list);
}

//FIXME: [HIGH] need to skip the task that are not ready + update in case clean istance
bool Scheduler::executeOne() {
    if(this->current_task == nullptr) {
        return true;
    }
    bool r = this->current_task->task->next();
    this->current_task = this->current_task->next;
    return r;
}

bool Scheduler::executeAll() {
    if(this->task_list == nullptr) {
        return true;
    }
    task_list_t* runner = this->task_list;
    bool control, empty_execution = true;
    do {
        if(runner->task->get_status() == TaskStatus::READY) {
            empty_execution = false;
            control = runner->task->next();
            if(!control) {
                return false;
            }
        } else if (runner->task->get_status() == TaskStatus::DEAD){
            this->need_clean = true;
        }
        runner = runner->next;
    } while(runner != this->task_list);
    if (empty_execution && this->need_clean){
        this->clean();
    }
    return true;
}

bool Scheduler::assertSize(byte list_size) {
    if(this->task_list == nullptr and list_size == 0) {
        return true;
    } else if (this->task_list == nullptr and list_size != 0) {
        return false;
    }
    task_list_t* runner = this->task_list;
    byte count = 1;
    while(runner->next != this->task_list) {
        count++;
        runner = runner->next;
    }
    return count == list_size;
}