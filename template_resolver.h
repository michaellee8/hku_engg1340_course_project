//
// Created by michaellee8 on 3/16/19.
//
#include <string>
#include <map>

#ifndef HKU_ENGG1340_COURSE_PROJECT_TEMPLATE_RESOLVER_H
#define HKU_ENGG1340_COURSE_PROJECT_TEMPLATE_RESOLVER_H

class TemplateResolver {
 private:
  std::string getTemplateFromFS(std::string path);
  std::string getTemplate(std::string path);
  std::map<std::string, std::string> cache;
  std::string ltrim(std::string, size_t);
  std::string rtrim(std::string, size_t);
  std::string ctrim(std::string, size_t);
 public:
  std::string renderTemplate(std::string, std::map<std::string, std::string>);
};

#endif //HKU_ENGG1340_COURSE_PROJECT_TEMPLATE_RESOLVER_H
