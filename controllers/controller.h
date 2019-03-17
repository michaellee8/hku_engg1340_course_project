//
// Created by michaellee8 on 3/17/19.
//

#include <functional>
#include <map>
#include "../template_resolver.h"

#ifndef HKU_ENGG1340_COURSE_PROJECT_CONTROLLER_H
#define HKU_ENGG1340_COURSE_PROJECT_CONTROLLER_H

class ControllerResult {
 public:
  std::string route;
  std::map<std::string, std::string> params;
  std::string input;
  std::string output;
  ControllerResult(std::string route,
                   std::map<std::string, std::string> params,
                   std::string input, std::string output);
};

typedef std::function<ControllerResult(std::string,
                                       std::map<std::string, std::string>,
                                       std::string,
                                       TemplateResolver)>
    controller;

#endif //HKU_ENGG1340_COURSE_PROJECT_CONTROLLER_H
