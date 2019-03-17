//
// Created by michaellee8 on 3/17/19.
//

#include "menu_controller.h"
#include "./special_controller.h"
#include "./create_controller.h"
ControllerResult menuController(std::string route,
                                std::map<std::string, std::string> params,
                                std::string input,
                                TemplateResolver resolver) {
  if (!input.empty()) {
    if (input == "create") {
      return createController("/create", std::map<std::string, std::string>(), "", resolver);
    }
    return specialController("/notimplemented", std::map<std::string, std::string>(), "", resolver);
  }
  return ControllerResult("/menu",
                          std::map<std::string, std::string>(),
                          "", resolver.renderTemplate("menu", std::map<std::string, std::string>()));
}