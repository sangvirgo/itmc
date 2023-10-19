#pragma once 
#include "Task.h"

Task::Task() {
}

Task::Task(const std::string& title, const Date& date, const std::string& notes) {
    this->title=title;
    this->date=date;
    this->notes=notes;
    this->status=NotCompleted;
    this->schedulingDate=Task::getCurrentDate();
    int days=Task::countDate(schedulingDate, date);
    if(days==1) {
        this->priority=In_Today;
    }
    else if(days>1 && days<=3) {
        this->priority=In_ThreeDay;
    } 
    else if(days>3 &&  days <=7) {
        this->priority=In_OneWeek;
    }
    else if(days>7 && days <=14) {
        this->priority=In_TwoWeeks;
    }
    else {
        this->priority=In_OneMonth;
    }
}

Task::Date Task::getCurrentDate() {
    time_t currentTime;
    time(&currentTime);
    Date current;
    struct tm* currentDateStruct=localtime(&currentTime);
    current.day=currentDateStruct->tm_mday;
    current.month=currentDateStruct->tm_mon+1;
    current.year=currentDateStruct->tm_year+1900;
    return current;
}

std::string Task::fomatDate(Date current) {
    std::string result="", day, month, year;
    day=std::to_string(current.day);
    month=std::to_string(current.month);
    year=std::to_string(current.year);
    if(day.length()==1) {
        day="0"+day;
    }
    if(month.length()==1) {
        month="0"+month;
    }
    result = day + "/" + month + "/" + year;
    return result;
}

std::string Task::fomatTitle(std::string title) {
    std::string result="";
    std::stringstream ss(title);
    std::string temp;
    while (ss>>temp)
    {
        result+=toupper(temp[0]);
        for(int i=1; i<temp.length(); i++) {
            result+=tolower(temp[i]);
        }
        result+=" ";
    }
    result.erase(result.length()-1);
    return result;
}

std::string Task::fomatNotes(std::string notes) {
    std::string result="";
    bool inUpper=1;
    
    for(char c:notes) {
        if(std::isalpha(c)) {
            if(inUpper) {
                result+=std::toupper(c);
                inUpper=0;
            }
            else {
                result+=std::tolower(c);
            }
        }
        else if(c=='.') {
            inUpper=1;
            result+=c;
        }
        else {
            result+=c;
        }
    }
    return result;
}

bool Task::compare(Date current, Date date) {
    if (date.year < current.year) {
        return false; // The input year is in the past.
    }
    else if (date.year > current.year) {
        return true; // The input year is in the future.
    }
    else {
        if (date.month < current.month) {
            return false; // The input month is in the past.
        }
        else if (date.month > current.month) {
            return true; // The input month is in the future.
        }
        else {
            if (date.day < current.day) {
                return false; // The input day is in the past or today.
            }
            else {
                return true; // The input day is in the future.
            }
        }
    }
}


bool Task::isValidDate(int day, int month, int year) {
    if(day<1 || year <0 || month >12 || day >32) {
        return false;
    }
    static int daysMonth[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        daysMonth[2] = 29; // February has 29 days in a leap year
    }
    return day<=daysMonth[month];
}

Task Task::getTask() {
    std::string title;
    std::cout << "-------------Enter A Task-------------"<< std::endl;
    do {
        std::cout << "Enter Title (Size<=100): ";
        std::cin.ignore();
        std::getline(std::cin, title);
    } while (title.length()>100);

    std::string note;
    do {
        std::cout << "Enter Note (Size<=1000): ";
        std::getline(std::cin, note);
    } while (note.length()>1000);

    Task::Date date;
    Task::Date current= Task::getCurrentDate();
    do {
        std::cout << "Enter Deadline (Greater than the current date)" << std::endl;
        std::cout << "Enter day: "; std::cin >> date.day;
        std::cout << "Enter month: "; std::cin >> date.month;
        std::cout << "Enter year: "; std::cin >> date.year;
    } while (!Task::compare(current, date) || !Task::isValidDate(date.day, date.month, date.year));


    Task newTask(title, date, note);
    return newTask;
}


int Task::countDate(Date schedulingDate, Date deadline) {
    int days=0;
    static int daysMonth[13] ={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((deadline.year % 4 == 0 && deadline.year % 100 != 0) || deadline.year % 400 == 0) {
        daysMonth[2] = 29;
    }
    if(schedulingDate.year==deadline.year) {
        if(schedulingDate.month==deadline.month) {
            days=deadline.day-schedulingDate.day;
        }
        else {
            for(int i=schedulingDate.month; i<deadline.month; i++) {
                days+=daysMonth[i]-schedulingDate.day;
                schedulingDate.day=0;
            }
        }
    }
    else {
        // Different years, calculate days within different years
        for (int year = schedulingDate.year; year < deadline.year; year++) {
            for (int month = schedulingDate.month; month <= 12; month++) {
                days += daysMonth[month] - schedulingDate.day;
                schedulingDate.day = 0; // For the first year, days from schedulingDate to the end of the month
            }
            schedulingDate.month = 1; // Start from January for the following years
        }

        // Add days for the final year
        for (int month = schedulingDate.month; month < deadline.month; month++) {
            days += daysMonth[month] - schedulingDate.day;
            schedulingDate.day = 0; // For the last year, days from schedulingDate to the end of the month
        }
        days += deadline.day; // Add days from the last month
    }

    return days;
}
