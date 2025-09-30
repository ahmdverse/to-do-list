#include "TaskManager.h"
#include <iostream>
#include <string>

int main() {
  TaskManger p1;
  p1.loadTasks();
  int choice;
  do {
    cout << "============================\n";
    cout << "1.Add task\n";
    cout << "2.View tasks\n";
    cout << "3.Complete task\n";
    cout << "4.Delete task\n";
    cout << "5.Exit\n";
    cout << "============================\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 1: {
      string task;
      cout << "Enter your task: ";
      cin.ignore();
      getline(cin, task);
      p1.addTasks(task);
    } break;
    case 2:
      p1.viewTasks();
      break;
    case 3: {
      int index;
      cout << "Enter your task to complete: ";
      cin >> index;
      p1.completeTask(index);
    } break;
    case 4: {
      int index;
      cout << "Enter your task to delete: ";
      cin >> index;
      p1.deleteTask(index);
    } break;
    case 5:
      p1.saveTasks();
      break;
    default:
      break;
    }
  } while (choice != 5);
}
