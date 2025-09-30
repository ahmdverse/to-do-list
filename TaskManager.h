#include <fstream>
#include <iostream>
#include <iterator>
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
      size_t delimiterPos = line.find('|');
      bool isCompleted = (line[0] == '1');
      string taskDescription = line.substr(delimiterPos + 1);
      tasks.push_back({taskDescription, isCompleted});
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
  void completeTask(int index) {
    if (index <= 0 || index > tasks.size()) {
      cout << "Please, choose valid task\n";
      return;
    }
    tasks[index - 1].status = true;
  }
  void deleteTask(int index) {
    if (index <= 0 || index > tasks.size()) {
      cout << "Please, choose valid task\n";
      return;
    }
    tasks.erase(tasks.begin() + index - 1);
  }
  void saveTasks() {
    ofstream file("task.txt");

    if (!file) {
      cout << "Error: can't open file!\n";
      return;
    }
    for (auto tk : tasks) {
      file << tk.status << "|" << tk.task << endl;
    }
    file.close();
  }
};
