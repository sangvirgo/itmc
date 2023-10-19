#pragma once 
#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <sstream>

class Task {
public:
    enum Status {
        NotCompleted,
        InProgress,
        Completed,
        Canceled,
        Overdue
    };

    enum Priority {
        In_Today,
        In_ThreeDay,
        In_OneWeek,
        In_TwoWeeks,
        In_OneMonth
    };

    struct Date {
        int day;
        int month;
        int year;
    };

    Task();

    Task(const std::string& title, const Date& date, const std::string& notes);

    static Date getCurrentDate();

    static std::string fomatDate(Date date);   // nhap sau ngay hien tai

    static bool compare(Date current, Date date);

    static std::string fomatTitle(const std::string title); // gioi han 100

    static std::string fomatNotes(const std::string notes); // gioi han 1000

    static bool isValidDate(int day, int month, int year);

    static int countDate(Date schedulingDate, Date deadline);

    static Task getTask();


    void setStatus(Status status) {
        this->status=status;
    }

    Status getStatus() const {
        return status;
    }

    void setDate(Date date) {
        this->date=date;
    }

    void setSchedulingDate(Date date) {
        this->schedulingDate=date;
    }

    void setPriority(Priority a) {
        this->priority=a;
    }

    void setTitle(std::string temp) {
        this->title=temp;
    }

    void setNote(std::string temp) {
        this->notes=temp;
    }

    Date getDate() const{
        return date;
    }

    Date getschedulingDate() const{
        return schedulingDate;
    }

    std::string getTitle() const{
        return title;
    }

    Priority getpriority() const{
        return priority;
    }

    std::string getNote() const {
        return notes;
    }
    
private:
    std::string title;
    Priority priority;
    Date date;
    std::string notes;
    Status status;
    Date schedulingDate;
};

#endif