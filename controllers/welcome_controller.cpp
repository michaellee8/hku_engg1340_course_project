//
// Created by michaellee8 on 3/17/19.
//

#include "welcome_controller.h"
#include "../template_resolver.h"
#include "./menu_controller.h"

ControllerResult welcomeController(std::string route,
                                   std::map<std::string, std::string> params,
                                   std::string input,
                                   TemplateResolver resolver) {
  std::map<std::string, std::string> m;
  if (input == "menu") {
    // Redirect to menu if input match
    return menuController("/menu", m, "", resolver);
  }

  m["author_name_1"] = "michaellee8";
  m["author_name_2"] = "Lee Chun Kok Michael";
  m["version_code"] = "v0.0.1";
  return ControllerResult("/welcome",
                          std::map<std::string, std::string>(),
                          "", resolver.renderTemplate("welcome", m));
}