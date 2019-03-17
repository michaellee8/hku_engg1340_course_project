//
// Created by michaellee8 on 3/16/19.
//

#include <vector>
#include <functional>
#include <string>

#ifndef HKU_ENGG1340_COURSE_PROJECT_EMPLOYEE_H
#define HKU_ENGG1340_COURSE_PROJECT_EMPLOYEE_H

class Employee {
 public:
  static bool insert(Employee&);
  static std::vector<Employee> select(std::function<bool(Employee)>);
  static bool remove(std::function<bool(Employee)>);

  bool remove();
  bool update();
  bool upsert();

  std::string fileId;
  int id;
  std::string name;
  int age;
  std::string role;
  float salary;
  bool fired;
  std::string customAttr;

 private:
  static std::string serialize(Employee);
  static Employee deserialize(std::string);
  static int getCounter();
  static bool setCounter(int);
  static bool increaseCounter();

};

#endif //HKU_ENGG1340_COURSE_PROJECT_EMPLOYEE_H
