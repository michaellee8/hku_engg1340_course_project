//
// Created by michaellee8 on 4/28/19.
//
#include "../../models/employee.h"
#ifndef HKU_ENGG1340_COURSE_PROJECT_COMPARISON_H
#define HKU_ENGG1340_COURSE_PROJECT_COMPARISON_H

typedef std::function<bool(Employee)> selectFunction;

selectFunction getComparisonFunction(std::string, std::string, std::string);
selectFunction logicalAndFunction(std::vector<selectFunction>);
selectFunction logicalOrFunction(std::vector<selectFunction>);

#endif //HKU_ENGG1340_COURSE_PROJECT_COMPARISON_H
