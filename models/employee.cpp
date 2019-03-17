//
// Created by michaellee8 on 3/16/19.
//

#include <sstream>
#include "employee.h"
#include "../util.h"
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

bool Employee::insert(Employee &e) {
  if (!e.fileId.empty()) {
    // Already inserted
    return false;
  }
  auto fileId = generateUuid();
  auto id = Employee::getCounter();
  e.id = id;
  e.fileId = fileId;
  auto ser = Employee::serialize(e);
  Employee::increaseCounter();
  return writeToFS("./data/employees/" + e.fileId+".employeedata", ser);
}

std::vector<Employee> select(const std::function<bool(Employee)> selectFunc){
  for(auto& p: fs::directory_iterator("./data/employees/")){

  }
}

std::string Employee::serialize(const Employee e) {
  std::stringstream ss;
  ss << e.fileId << std::endl;
  ss << e.id << std::endl;
  ss << e.name << std::endl;
  ss << e.age << std::endl;
  ss << e.role << std::endl;
  ss << e.salary << std::endl;
  ss << e.fired << std::endl;
  ss << e.customAttr << std::endl;
  return ss.str();
}

Employee Employee::deserialize(const std::string s) {
  std::stringstream ss(s);
  Employee e;
  std::string line;
  std::getline(ss, line);
  e.fileId = std::string(line);
  std::getline(ss, line);
  e.id = std::stoi(line);
  std::getline(ss, line);
  e.name = std::string(line);
  std::getline(ss, line);
  e.age = std::stoi(line);
  std::getline(ss, line);
  e.role = std::string(line);
  std::getline(ss, line);
  e.salary = std::stof(line);
  std::getline(ss, line);
  std::istringstream(line) >> e.fired;
  std::getline(ss, line);
  e.customAttr = std::string(line);
  return e;
}

int Employee::getCounter() {
  auto s = readFromFS("./data/counters/employees");
  return std::stoi(s);
}

bool Employee::setCounter(int i) {
  return writeToFS("./data/counters/employees", std::to_string(i));
}

bool Employee::increaseCounter() {
  return Employee::setCounter(Employee::getCounter() + 1);
}