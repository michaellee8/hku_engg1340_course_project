#include <iostream>
#include "./template_resolver.h"

void render();

int main() {
  render();
  return 0;
}

void render() {
  // Clear screen with this magic character
  std::cout << "\033c" << std::flush;
  TemplateResolver tr;
  std::map<std::string, std::string> m;
  m["author_name_1"] = "michaellee8";
  m["author_name_2"] = "Lee Chun Kok Michael";
  m["version code"] = "v0.0.1";
  std::cout << tr.renderTemplate("welcome", m);
}