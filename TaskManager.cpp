#pragma once 
#include "TaskManager.h"

void TaskManager::add(Task task) {
    tasks.push_back(task);
}

void TaskManager::deletetask(TaskManager& taskmanager) {
    std::cout << "Enter title to delete: ";
    std::string title;
    std::cin.ignore();
    std::getline(std::cin, title);
    int count(0);
    TaskManager temp;
    for(int i=0; i<taskmanager.tasks.size(); i++) {
        if(Task::fomatTitle(taskmanager.tasks[i].getTitle())==Task::fomatTitle(title)) {
            count++;
            temp.tasks.push_back(taskmanager.tasks[i]);
        }
    }
    if(count==1) {
    for(auto it=taskmanager.tasks.begin(); it!=taskmanager.tasks.end(); it++) {
        if(Task::fomatTitle(it->getTitle())==Task::fomatTitle(title)) {
            taskmanager.tasks.erase(it);
                std::cout << "=========================================================" << std::endl;
                std::cout << "==============Task deleted successfully==================" << std::endl;
                std::cout << "=========================================================" << std::endl;
                temp.tasks.clear();
            return;
        }
    }
    }
    else if(count==0) {
        std::cout << "Task with title '" << title << "' not found." << std::endl;
        std::cout << "Please check again" << std::endl;
    }
    else {
        std::cout << "=================Tasks with the same title===============" << std::endl;
        std::cout << std::endl;
        temp.display();
        temp.tasks.clear();
        std::cout << "Please enter ordinal to delete: " ;
        int x, removedCount(0); std::cin >> x;
        while(x<=0 || x>count) {
            std::cout << "input error, please enter ordinal to delete again: ";
            std::cin >> x;
        }
        for(auto it=taskmanager.tasks.begin(); it!=taskmanager.tasks.end(); it++) {
            if(Task::fomatTitle(it->getTitle())==Task::fomatTitle(title) && removedCount==x-1) {
                taskmanager.tasks.erase(it);
                std::cout << "=========================================================" << std::endl;
                std::cout << "==============Task deleted successfully==================" << std::endl;
                std::cout << "=========================================================" << std::endl;
                return;
            }
            else {
                removedCount++;
            }
    }
    }
        
}

void TaskManager::display() const{
std::string statusStrings[] = {"NotCompleted", "InProgress", "Completed", "Canceled", "Overdue"};
std::string priorityStrings[] = {"In_Today", "In_ThreeDay", "In_OneWeek", "In_TwoWeeks", "In_OneMonth"};
std::cout << "======================List Tasks==========================" << std::endl;
for(int i = 0; i < tasks.size(); i++) {
    std::cout << "Ordinal: " << i+1 << std::endl;
    std::cout << "Title: " << Task::fomatTitle(tasks[i].getTitle()) << std::endl;
    std::cout << "Status: " << statusStrings[tasks[i].getStatus()] << std::endl;
    std::cout << "Scheduling time: " << Task::fomatDate(tasks[i].getschedulingDate()) << std::endl;
    std::cout << "Priority: " << priorityStrings[tasks[i].getpriority()] << std::endl;
    std::cout << "Deadline: " << Task::fomatDate(tasks[i].getDate()) << std::endl;
    std::cout << "Note: " << Task::fomatNotes(tasks[i].getNote()) << std::endl; 
    std::cout << std::endl;
}
std::cout << "=========================================================" << std::endl;
}



void TaskManager::edittask(TaskManager& taskmanager) {
    taskmanager.display();
    
    int cnt = taskmanager.tasks.size();
    
    if (cnt == 0) {
        std::cout << "No tasks to edit." << std::endl;
        return;
    }
    
    std::cout << "Please enter ordinal to edit: ";
    int x;
    std::cin >> x;

    while (x <= 0 || x > cnt) {
            std::cout << "Invalid ordinal. Please enter a valid ordinal." << std::endl;
            std::cin >> x;
}
    
    
    x--;
    
    std::cout << "1. Edit Title" << std::endl;
    std::cout << "2. Edit Status" << std::endl;
    std::cout << "3. Edit Scheduling time" << std::endl;
    std::cout << "4. Edit Priority" << std::endl;
    std::cout << "5. Edit Deadline" << std::endl;
    std::cout << "6. Edit Note" << std::endl;
    
    int choicetwo;
    std::cout << "Enter the number of the option you want to edit: ";
    std::cin >> choicetwo;
    cnt=0;
    // You can now implement the editing logic for each choicetwo.

    std::string strtemp;
    Task::Status statustemp;
    Task::Date schedulingDateTemp;
    Task::Priority prioritytemp;
    Task::Date deadlineDateTemp;
    std::string notetemp;
    Task::Date current= Task::getCurrentDate();
    switch (choicetwo) {
        case 1:
        std::cin.ignore();
        std::cout << "Enter the new title: ";
        std::getline(std::cin, strtemp);
        taskmanager.tasks[x].setTitle(Task::fomatTitle(strtemp));
        std::cout << "Title updated successfully." << std::endl;
        break;
        case 2:
            std::cout << "0. NotCompleted\n";
            std::cout << "1. InProgress\n";
            std::cout << "2. Completed\n";
            std::cout << "3. Canceled\n";
            std::cout << "4. Overdue\n";
            std::cout << "Enter status (0-4): ";
            int status;
            std::cin >> status;
            while (status < 0 || status > 4) {
            std::cout << "0. NotCompleted\n";
            std::cout << "1. InProgress\n";
            std::cout << "2. Completed\n";
            std::cout << "3. Canceled\n";
            std::cout << "4. Overdue\n";
            std::cout << "Invalid status. Please enter a value between 0 and 4: ";
            std::cin >> status;
            }
            statustemp=static_cast<Task::Status>(status);
            taskmanager.tasks[x].setStatus(statustemp);
            std::cout << "Status updated successfully." << std::endl;
            break;
        case 3:
        do {
            std::cout << "Enter the new Scheduling Date" << std::endl;
            std::cout << "Enter day: "; std::cin >> schedulingDateTemp.day;
            std::cout << "Enter month: "; std::cin >> schedulingDateTemp.month;
            std::cout << "Enter year: "; std::cin >> schedulingDateTemp.year;
        } while (!Task::isValidDate(schedulingDateTemp.day, schedulingDateTemp.month, schedulingDateTemp.year));
        taskmanager.tasks[x].setSchedulingDate(schedulingDateTemp);
        std::cout << "Scheduling Date updated successfully." << std::endl;
            break;
        case 4:
            std::cout << "0. In_Today\n";
            std::cout << "1. In_ThreeDay\n";
            std::cout << "2. In_OneWeek\n";
            std::cout << "3. In_TwoWeeks\n";
            std::cout << "4. In_OneMonth\n";
            std::cout << "Enter priority (0-4): ";
            int priority;
            std::cin >> priority;
            while (priority < 0 || priority > 4) {
                std::cout << "0. In_Today\n";
                std::cout << "1. In_ThreeDay\n";
                std::cout << "2. In_OneWeek\n";
                std::cout << "3. In_TwoWeeks\n";
                std::cout << "4. In_OneMonth\n";
                std::cout << "Invalid priority. Please enter a value between 0 and 4: ";
                std::cin >> priority;
            }
            prioritytemp=static_cast<Task::Priority>(priority);
            taskmanager.tasks[x].setPriority(prioritytemp);
            std::cout << "Priority updated successfully." << std::endl;
            break;
        case 5:
            do {
                std::cout << "Enter the new Deadline (Greater than the current date)" << std::endl;
                std::cout << "Enter day: "; std::cin >> deadlineDateTemp.day;
                std::cout << "Enter month: "; std::cin >> deadlineDateTemp.month;
                std::cout << "Enter year: "; std::cin >> deadlineDateTemp.year;
            } while (!Task::compare(current, deadlineDateTemp) || !Task::isValidDate(deadlineDateTemp.day, deadlineDateTemp.month, deadlineDateTemp.year));
                taskmanager.tasks[x].setDate(deadlineDateTemp);
                std::cout << "Deadline Date updated successfully." << std::endl;
            break;
        case 6:
                std::cin.ignore();
                std::cout << "Enter the new note: ";
                std::getline(std::cin, notetemp);
                taskmanager.tasks[x].setNote(notetemp);
                std::cout << "Note updated successfully." << std::endl;
                    break;
        default:
                    std::cout << "Invalid choice. Please enter a valid option." << std::endl;
            break;
    }
}

void TaskManager::readAFile(TaskManager& taskmanager) {
    std::ifstream file("Task.txt");
    Task task;
    if(!file.is_open()) {
        std::cout << "Cannot open file!!!!" << std::endl;
        return;
    }

    std::string line;
    while(std::getline(file, line)) {
        std::stringstream ss(line);
        std::string titletemp;
        std::string notetemp;
        Task::Priority prioritytemp;
        int priority;
        Task::Status statustemp;
        int status;
        Task::Date schedulingDate;
        Task::Date deadline;

        // Đọc thông tin từ dòng
        std::getline(ss, titletemp, ',');
        ss >> status;
        ss.ignore();  // Đọc và bỏ dấu phẩy thừa
        ss >> schedulingDate.day;
        ss.ignore();  // Đọc và bỏ dấu phẩy thừa
        ss >> schedulingDate.month;
        ss.ignore();  // Đọc và bỏ dấu phẩy thừa
        ss >> schedulingDate.year;
        ss.ignore();  // Đọc và bỏ dấu phẩy thừa
        ss >> priority;
        ss.ignore();  // Đọc và bỏ dấu phẩy thừa
        ss >> deadline.day;
        ss.ignore();  // Đọc và bỏ dấu phẩy thừa
        ss >> deadline.month;
        ss.ignore();  // Đọc và bỏ dấu phẩy thừa
        ss >> deadline.year;
        ss.ignore();  // Đọc và bỏ dấu phẩy thừa
        std::getline(ss, notetemp);
        ss.ignore();
        // Thiết lập thông tin cho đối tượng Task
        task.setDate(deadline);
        task.setTitle(titletemp);
        task.setNote(notetemp);
        task.setSchedulingDate(schedulingDate);
        prioritytemp = static_cast<Task::Priority>(priority);
        task.setPriority(prioritytemp);
        statustemp = static_cast<Task::Status>(status);
        task.setStatus(statustemp);

        // Thêm Task vào TaskManager
        taskmanager.add(task);
    }
}

void TaskManager::find(TaskManager taskmanager) {
    std::string strtemp;
    std::cout << "Please enter the title to search: ";
    std::cin.ignore();
    std::getline(std::cin, strtemp);
    TaskManager objtemp;
    
    // Use a vector instead of a fixed-size array to store indices
    std::vector<int> indices;
    
    for (int i = 0; i < taskmanager.tasks.size(); i++) {
        if (Task::fomatTitle(taskmanager.tasks[i].getTitle()) == Task::fomatTitle(strtemp)) {
            objtemp.tasks.push_back(taskmanager.tasks[i]);
            indices.push_back(i); // Store the index
        }
    }
    
    if (objtemp.tasks.empty()) {
        std::cout << "Not found, please check again!!!!" << std::endl;
        return;
    }
    
    objtemp.display();
    
    std::cout << "At Ordinal: ";
    
    for (int i = 0; i < indices.size(); i++) {
        std::cout << indices[i];
        if (i < indices.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
    objtemp.tasks.clear();
}
/*
        NotCompleted,
        InProgress,
        Completed,
        Canceled,
        Overdue
*/
void TaskManager::findStatus(TaskManager taskmanager) {
    std::vector<std::string> strtemp0, strtemp1, strtemp2, strtemp3, strtemp4;
    int cnt0=0, cnt1=0, cnt2=0, cnt3=0, cnt4=0;
    for (const auto& task : taskmanager.tasks) {
        if(task.getStatus()==NotCompleted) {
            cnt0++;
            strtemp0.push_back(task.getTitle());
        }
        else if(task.getStatus()==InProgress) {
            cnt1++;
            strtemp1.push_back(task.getTitle());
        }
        else if(task.getStatus()==Completed) {
            cnt2++;
            strtemp2.push_back(task.getTitle());
        }
        else if(task.getStatus()==Canceled) {
            cnt3++;
            strtemp3.push_back(task.getTitle());
        }
        else {
            cnt4++;
            strtemp4.push_back(task.getTitle());
        }
    }
    std::cout << "================Mission status statistics================" << std::endl;
    std::cout << "NotCompleted: " << cnt0 << " tasks" << std::endl;
    for (const auto& it : strtemp0) {
        std::cout << it << std::endl;
    }
    std::cout << std::endl;
    std::cout << "InProgress: " << cnt1 << " tasks" << std::endl;
    for (const auto& it : strtemp1) {
        std::cout << it << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Completed: " << cnt2 << " tasks" << std::endl;
    for (const auto& it : strtemp2) {
        std::cout << it << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Canceled: " << cnt3 << " tasks" << std::endl;
    for (const auto& it : strtemp3) {
        std::cout << it << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Overdue: " << cnt4 << " tasks" << std::endl;
    for (const auto& it : strtemp4) {
        std::cout << it << std::endl;
    }

    std::cout << "=========================================================" << std::endl;

    strtemp0.clear();
    strtemp1.clear();
    strtemp2.clear();
    strtemp3.clear();
    strtemp4.clear();
}


void TaskManager::sortTasksByPriority(TaskManager& taskmanager) {
    auto cmp = [](const Task& a, const Task& b) {
        return a.getpriority() < b.getpriority();
    };

    std::sort(taskmanager.tasks.begin(), taskmanager.tasks.end(), cmp);

    std::cout << "Tasks sorted by priority!" << std::endl;
}

void TaskManager::AddTaskToSave(TaskManager& taskmanager) {
    Task newTask = Task::getTask();
    
    std::string filename = "Task.txt";
    std::ofstream file(filename, std::ios::app);

    if (!file) {
        std::cerr << "Cannot open file for writing." << std::endl;
        taskmanager.tasks.push_back(newTask);
        return;
    }
    
    char choice;
    std::cout << "Do you wanna save to .txt file(Y or N): ";
    std::cin >> choice;
    
    if (choice == 'Y' || choice == 'y') {
        file << Task::fomatTitle(newTask.getTitle()) << ", ";
        file << static_cast<int>(newTask.getStatus()) << ", ";
        file << newTask.getCurrentDate().day << " ";
        file << newTask.getCurrentDate().month << " ";
        file << newTask.getCurrentDate().year << " ";
        file << static_cast<int>(newTask.getpriority()) << ", ";
        file << newTask.getDate().day << " ";
        file << newTask.getDate().month << " ";
        file << newTask.getDate().year << ", ";
        file << Task::fomatNotes(newTask.getNote()) << "\n";
    }
    
    file.close();
    std::cout << "Add complete." << std::endl;

    // Add the new task to the task manager
    taskmanager.tasks.push_back(newTask);
}
