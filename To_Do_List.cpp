#include <iostream>
#include <string>

using namespace std;

int main() {
    string todoList[20]; 
    int taskCount = 0; 
    int choice;

    while (true) {
        cout << "4--- TO-DO LIST ---\n";
        cout << "1. View Tasks\n";
        cout << "2. Add Task\n";
        cout << "3. Delete All Tasks\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

switch (choice) {
            case 1:
                if (taskCount == 0) {
                    cout << "Your list is empty!\n";
                } else {
                    cout << "YOUR TASKS:\n";
                    for (int i = 0; i < taskCount; i++) {
                        cout << (i + 1) << ". " << todoList[i] << "\n";
                    }
                }
                break;

            case 2:
                if (taskCount < 20) {
                    cout << "Enter task (use underscores like buy_milk): ";
                    cin >> todoList[taskCount]; 
                    taskCount++; 
                    cout << "Task added successfully!\n";
                } else {
                    cout << "List is full!\n";
                }
                break;

            case 3:
                taskCount = 0;
                cout << "All tasks cleared!\n";
                break;

            case 4:
                cout << "Goodbye!\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
                break;
        }
    }
    return 0;
}