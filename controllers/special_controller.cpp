//
// Created by michaellee8 on 3/17/19.
//

#include "special_controller.h"

ControllerResult specialController(std::string route,
                                   std::map<std::string, std::string> params,
                                   std::string input,
                                   TemplateResolver resolver) {
  if (route == "/error") {
    return ControllerResult("/error",
                            std::map<std::string, std::string>(),
                            "",
                            resolver.renderTemplate("error", std::map<std::string, std::string>()));
  }
  if (route == "/notimplemented") {
    return ControllerResult("/notimplemented",
                            std::map<std::string, std::string>(),
                            "", resolver.renderTemplate("notimplemented", std::map<std::string, std::string>()));
  }
  return ControllerResult("/notfound",
                          std::map<std::string, std::string>(),
                          "", resolver.renderTemplate("notfound", std::map<std::string, std::string>()));
}