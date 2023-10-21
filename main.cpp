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
        std::cout << "1. Display Tasks\n";
        std::cout << "2. Add Task\n";
        std::cout << "3. Delete Tasks\n";
        std::cout << "4. Edit Tasks\n";
        std::cout << "5. Search Tasks\n";
        std::cout << "6. Mission status statistics\n";
        std::cout << "7. Sort by priority\n";
        std::cout << "8. Filter Task\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 0:
                std::cout << "Goodbye!\n";
                break;
            case 2:
                TaskManager::AddTaskToSave(taskManager);
                break;
            case 1:
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
                break;
            case 6:
                TaskManager::findStatus(taskManager);
                break;
            case 7:
                TaskManager::sortTasksByPriority(taskManager);
                break;
            case 8:
                TaskManager::filter(taskManager);
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
