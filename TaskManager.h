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
};
