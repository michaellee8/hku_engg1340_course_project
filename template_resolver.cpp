//
// Created by michaellee8 on 3/16/19.
//

#include "template_resolver.h"
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <regex>
#include <stdexcept>

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

std::string TemplateResolver::rtrim(std::string s, size_t l) {
  auto rs(s);
  while (rs.length() < l) {
    rs = " " + rs;
  }
  return rs.substr(0, l);
}

std::string TemplateResolver::ltrim(std::string s, size_t l) {
  auto rs(s);
  while (rs.length() < l) {
    rs += " ";
  }
  return rs.substr(0, l);
}

std::string TemplateResolver::ctrim(std::string s, size_t l) {
  auto rs(s);
  while (rs.length() < l / 2 + s.length() / 2) {
    rs = " " + rs;
  }
  while (rs.length() < l) {
    rs += " ";
  }
  return rs.substr(0, l);
}

// Took reference here https://stackoverflow.com/questions/26281979/c-loop-through-map
std::string TemplateResolver::renderTemplate(std::string name, std::map<std::string, std::string> textMap) {
  auto tpl = this->getTemplate("./res/templates/" + name + ".template.txt");
  std::string nstr(tpl);
  std::regex r("\\{\\{\\s*(\\w+):([clr])\\s*\\}\\}"); // This regular expression matches all placeholders
  std::smatch mr;
  std::regex_iterator<std::string::iterator> rit(tpl.begin(), tpl.end(), r);
  std::regex_iterator<std::string::iterator> rend;
  while (rit != rend) {
    auto key = (*rit)[1].str();
    auto mode = (*rit)[2].str();
    if (textMap.find(key) == textMap.end()) {
      // key does not exist
      ++rit;
      continue;
    }
    std::string tstr;
    if (mode == "c") {
      tstr = this->ctrim(textMap[key], rit->length());
    } else if (mode == "l") {
      tstr = this->ltrim(textMap[key], rit->length());
    } else if (mode == "r") {
      tstr = this->rtrim(textMap[key], rit->length());
    } else {
      throw std::invalid_argument("no padding options");
    }
    nstr.replace(rit->position(), rit->length(), tstr);
    ++rit;
  }
  return nstr;
}