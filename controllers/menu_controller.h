//
// Created by michaellee8 on 3/17/19.
//

#include <string>
#include <map>
#include "../template_resolver.h"
#include "./controller.h"
#ifndef HKU_ENGG1340_COURSE_PROJECT_MENU_CONTROLLER_H
#define HKU_ENGG1340_COURSE_PROJECT_MENU_CONTROLLER_H
ControllerResult menuController(std::string route,
                              std::map<std::string, std::string> params,
                              std::string input,
                              TemplateResolver resolver);
#endif //HKU_ENGG1340_COURSE_PROJECT_MENU_CONTROLLER_H
