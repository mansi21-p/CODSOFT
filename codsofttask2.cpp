#include <iostream>
#include <vector>
#include <string>
#include <limits>

struct Tasks{
    std::string description;
    bool completed;
    Tasks(const std::string& desc):description(desc),completed(false){}
};

class ToDoList {
private:
    std::vector<Tasks>tasks;

public:
    void addTask(const std::string& taskDescription){
        tasks.emplace_back(taskDescription);
        std::cout<<"Task added successfully!"<<std::endl;
    }

    void viewTasks()const{
        if(tasks.empty()){
            std::cout <<"No tasks in the list."<<std::endl;
        }else{
            std::cout <<"Your tasks:"<<std::endl;
            for(size_t i = 0;i<tasks.size(); ++i){
                std::cout << i + 1 <<". "<<tasks[i].description
                          <<" [" << (tasks[i].completed ? "Completed" : "Pending") << "]" << std::endl;
            }
        }
    }

    void markTaskAsCompleted(size_t index) {
        if (index > 0 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            std::cout<<"Task marked as completed!"<<std::endl;
        } else {
            std::cout<<"Invalid task number. Please try again."<<std::endl;
        }
    }

    void removeTask(size_t index) {
        if (index > 0 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            std::cout << "Task removed successfully!" << std::endl;
        } else {
            std::cout << "Invalid task number. Please try again." << std::endl;
        }
    }
}

void displayMenu() {
    std::cout << "\nTo-Do list funtions available:-" << std::endl;
    std::cout << "1. Add Task" << std::endl;
    std::cout << "2. View Tasks" << std::endl;
    std::cout << "3. Mark Task as Completed" << std::endl;
    std::cout << "4. Remove Task" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter your choice: ";,
}

int main() {
    ToDoList toDoList;
    int choice;
    std::string detailedtask;
    size_t taskNumber;

    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::getline(std::cin,detailedtask);
                toDoList.addTask(detailedtask);
                break;
            case 2:
                toDoList.viewTasks();
                break;
            case 3:
                std::cout << "Enter task no to mark as completed: ";
                std::cin >> taskNumber;
                toDoList.markTaskAsCompleted(taskNumber);
                break;
            case 4:
                std::cout << "Enter task no to remove: ";
                std::cin >> taskNumber;
                toDoList.removeTask(taskNumber);
                break;
            case 5:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice,try again." << std::endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
