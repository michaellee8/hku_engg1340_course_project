//
// Created by michaellee8 on 4/28/19.
//

#include "./comparison.h"
#ifndef HKU_ENGG1340_COURSE_PROJECT_BUILD_H
#define HKU_ENGG1340_COURSE_PROJECT_BUILD_H

selectFunction buildQuery(std::vector<std::string>);
selectFunction buildOrQuery(std::vector<std::string>);
selectFunction buildAndQuery(std::vector<std::string>);
selectFunction buildSimpleQuery(std::vector<std::string>);

#endif //HKU_ENGG1340_COURSE_PROJECT_BUILD_H
