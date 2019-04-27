//
// Created by michaellee8 on 3/17/19.
//
#include <string>
#include <map>

#ifndef HKU_ENGG1340_COURSE_PROJECT_UTIL_H
#define HKU_ENGG1340_COURSE_PROJECT_UTIL_H

std::string generateUuid();
std::string randomHex();
bool writeToFS(std::string, std::string);
std::string readFromFS(std::string);
bool keyExists(std::map<std::string, std::string> map, std::string key);
bool isNumber(std::string);
bool isInt(std::string);

#endif //HKU_ENGG1340_COURSE_PROJECT_UTIL_H
