#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Task {
  string task;
  bool status;
};

class TaskManger {
private:
  vector<Task> tasks;

public:
  void loadTasks() {
    string line;
    ifstream file("tasks.txt");

    if (!file) {
      cout << "Error: can't open file!";
      return;
    }
    while (getline(file, line)) {
      tasks.push_back({line, false});
    }
    file.close();
  }
  void viewTasks() {
    for (int i = 0; i < tasks.size(); i++) {
      if (tasks[i].status) {
        cout << i + 1 << " .[✓] " << tasks[i].task << endl;
      } else {
        cout << i + 1 << " .[ ] " << tasks[i].task << endl;
      }
    }
  }
  void addTasks(const string &newTask) { tasks.push_back({newTask, false}); }
};
