//
// Created by michaellee8 on 4/28/19.
//

#include "comparison.h"
#include "../../models/employee.h"
#include "../../util.h"

selectFunction idLessThan(int val) {
  return [val](Employee e) { return e.id < val; };
}

selectFunction idMoreThan(int val) {
  return [val](Employee e) { return e.id > val; };
}

selectFunction idLessEq(int val) {
  return [val](Employee e) { return e.id <= val; };
}

selectFunction idMoreEq(int val) {
  return [val](Employee e) { return e.id >= val; };
}

selectFunction idEqualTo(int val) {
  return [val](Employee e) { return e.id == val; };
}

selectFunction ageLessThan(int val) {
  return [val](Employee e) { return e.age < val; };
}

selectFunction ageMoreThan(int val) {
  return [val](Employee e) { return e.age > val; };
}

selectFunction ageLessEq(int val) {
  return [val](Employee e) { return e.age <= val; };
}

selectFunction ageMoreEq(int val) {
  return [val](Employee e) { return e.age >= val; };
}

selectFunction ageEqualTo(int val) {
  return [val](Employee e) { return e.age == val; };
}

selectFunction salaryLessThan(int val) {
  return [val](Employee e) { return e.salary < val; };
}

selectFunction salaryMoreThan(int val) {
  return [val](Employee e) { return e.salary > val; };
}

selectFunction salaryLessEq(int val) {
  return [val](Employee e) { return e.salary <= val; };
}

selectFunction salaryMoreEq(int val) {
  return [val](Employee e) { return e.salary >= val; };
}

selectFunction salaryEqualTo(int val) {
  return [val](Employee e) { return e.salary == val; };
}

selectFunction nameEqualTo(std::string val) {
  return [val](Employee e) { return e.name == val; };
}

selectFunction roleEqualTo(std::string val) {
  return [val](Employee e) { return e.role == val; };
}

selectFunction customEqualTo(std::string val) {
  return [val](Employee e) { return e.customAttr == val; };
}

bool isQuoted(std::string s) {
  return s[0] == '"' && s[s.size() - 1] == '"';
}

std::string extractQuoted(std::string s) {
  return s.substr(1, s.size() - 2);
}

selectFunction getComparisonFunction(std::string fieldName, std::string op, std::string val) {
  if (fieldName == "name" && op == "=" && isQuoted(val)) {
    return nameEqualTo(extractQuoted(val));
  }
  if (fieldName == "role" && op == "=" && isQuoted(val)) {
    return roleEqualTo(extractQuoted(val));
  }
  if (fieldName == "custom" && op == "=" && isQuoted(val)) {
    return customEqualTo(extractQuoted(val));
  }

  if (fieldName == "id" && isInt(val)) {
    auto intval = std::stoi(val);
    if (op == "=") {
      return idEqualTo(intval);
    }
    if (op == "<=") {
      return idLessEq(intval);
    }
    if (op == ">=") {
      return idMoreEq(intval);
    }
    if (op == "<") {
      return idLessThan(intval);
    }
    if (op == ">") {
      return idMoreThan(intval);
    }
  }

  if (fieldName == "age" && isInt(val)) {
    auto intval = std::stoi(val);
    if (op == "=") {
      return ageEqualTo(intval);
    }
    if (op == "<=") {
      return ageLessEq(intval);
    }
    if (op == ">=") {
      return ageMoreEq(intval);
    }
    if (op == "<") {
      return ageLessThan(intval);
    }
    if (op == ">") {
      return ageMoreThan(intval);
    }
  }

  if (fieldName == "salary" && isInt(val)) {
    auto intval = std::stoi(val);
    if (op == "=") {
      return salaryEqualTo(intval);
    }
    if (op == "<=") {
      return salaryLessEq(intval);
    }
    if (op == ">=") {
      return salaryMoreEq(intval);
    }
    if (op == "<") {
      return salaryLessThan(intval);
    }
    if (op == ">") {
      return salaryMoreThan(intval);
    }
  }

  return nullptr;
}

selectFunction logicalAndFunction(std::vector<selectFunction> fns) {
  for (selectFunction &f:fns) {
    if (f == nullptr) {
      return nullptr;
    }
  }
  if (fns.empty()) {
    return nullptr;
  }
  return [fns](Employee e) {
    for (selectFunction const f:fns) {
      if (!f(e)) {
        return false;
      }
    }
    return true;
  };
}

selectFunction logicalOrFunction(std::vector<selectFunction> fns) {
  for (selectFunction &f:fns) {
    if (f == nullptr) {
      return nullptr;
    }
  }
  if (fns.empty()) {
    return nullptr;
  }
  return [fns](Employee e) {
    for (selectFunction const f:fns) {
      if (f(e)) {
        return true;
      }
    }
    return false;
  };
}