//
// Created by michaellee8 on 3/16/19.
//

#include "template_resolver.h"
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <regex>

// Took code from https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
std::string TemplateResolver::getTemplateFromFS(std::string path) {
  // Should immediately break if template does not exist
  std::ifstream t(path);
  std::stringstream buffer;
  buffer << t.rdbuf();
  return buffer.str();
}

std::string TemplateResolver::getTemplate(std::string path) {
  if (this->cache.find(path) == this->cache.end()) {
    // Get from FS if template is not in cache
    this->cache[path] = this->getTemplateFromFS(path);
  }
  return this->cache[path];
}

std::string TemplateResolver::trim(std::string s, size_t l) {
  auto rs = s;
  while (rs.length() < l) {
    rs += " ";
  }
  return rs.substr(0, l);
}

// Took reference here https://stackoverflow.com/questions/26281979/c-loop-through-map
std::string TemplateResolver::renderTemplate(std::string name, std::map<std::string, std::string> textMap) {
  auto tpl = this->getTemplate("./res/templates/" + name + ".template.txt");
  for (auto const &t:textMap) {
    // I must admit that this is nowhere efficient, but it just works.
  }
}