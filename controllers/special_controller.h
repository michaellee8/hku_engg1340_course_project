//
// Created by michaellee8 on 3/17/19.
//

#ifndef HKU_ENGG1340_COURSE_PROJECT_SPECIAL_CONTROLLER_H
#define HKU_ENGG1340_COURSE_PROJECT_SPECIAL_CONTROLLER_H
#include <string>
#include <map>
#include "controller.h"
ControllerResult specialController(std::string route,
                              std::map<std::string, std::string> params,
                              std::string input,
                              TemplateResolver resolver);
#endif //HKU_ENGG1340_COURSE_PROJECT_SPECIAL_CONTROLLER_H
