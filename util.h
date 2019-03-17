//
// Created by michaellee8 on 3/17/19.
//
#include <string>

#ifndef HKU_ENGG1340_COURSE_PROJECT_UTIL_H

std::string generateUuid();
std::string randomHex();
bool writeToFS(std::string, std::string);
std::string readFromFS(std::string);
#define HKU_ENGG1340_COURSE_PROJECT_UTIL_H

#endif //HKU_ENGG1340_COURSE_PROJECT_UTIL_H
