#include "TaskManager.h"
#include "Task.h"
#include "TaskManager.cpp"
#include "Task.cpp"
int main() {
    TaskManager taskManager;
    int choice;
    Task task; // Đặt biến Task task ở đầu hàm main
    TaskManager::readAFile(taskManager);

    do {
        std::cout << "-----------------------------------------\n";
        std::cout << "         Task Management System\n";
        std::cout << "-----------------------------------------\n";
        std::cout << "0. Exit\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Display Tasks\n";
        std::cout << "3. Delete Tasks\n";
        std::cout << "4. Edit Tasks\n";
        std::cout << "5. Search Tasks\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 0:
                std::cout << "Goodbye!\n";
                break;
            case 1:
                task=task.getTask();
                taskManager.add(task);
                break;
            case 2:
                taskManager.display();
                break;
            case 3:
                TaskManager::deletetask(taskManager);
                break;
            case 4:
                TaskManager::edittask(taskManager);
                break;
            case 5:
                TaskManager::find(taskManager);
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
