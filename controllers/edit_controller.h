//
// Created by michaellee8 on 4/27/19.
//

#ifndef HKU_ENGG1340_COURSE_PROJECT_EDIT_CONTROLLER_H
#define HKU_ENGG1340_COURSE_PROJECT_EDIT_CONTROLLER_H

#include "controller.h"
ControllerResult editController(std::string route,
                                std::map<std::string, std::string> params,
                                std::string input,
                                TemplateResolver resolver);

#endif //HKU_ENGG1340_COURSE_PROJECT_EDIT_CONTROLLER_H
