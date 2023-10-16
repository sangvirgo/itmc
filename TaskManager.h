#pragma once 
#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "Task.h"
#include "Task.cpp"
#include <vector>
#include <iomanip>

class TaskManager : public Task {
private:
    std::vector<Task> tasks;

public:
    void add(Task task);
    void display() const;
    static void deletetask(TaskManager& taskmanager);
    static void edittask(TaskManager& taskmanager);
};

#endif