//
// Created by michaellee8 on 3/17/19.
//
#include "./controller.h"
#include <map>
ControllerResult::ControllerResult(std::string route,
                                   std::map<std::string, std::string> params,
                                   std::string input,
                                   std::string output) {
  this->route = route;
  this->params = params;
  this->input = input;
  this->output = output;
}