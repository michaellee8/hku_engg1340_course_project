//
// Created by michaellee8 on 3/17/19.
//

#include "create_controller.h"
#include "../util.h"
#include "../models/employee.h"
#include "./special_controller.h"
#include "./menu_controller.h"

ControllerResult createController(std::string route,
                                  std::map<std::string, std::string> params,
                                  std::string input,
                                  TemplateResolver resolver) {

  if (keyExists(params, "status") && params["status"] == "success") {
    return menuController("/menu", params, "", resolver);
  }
  if (params.empty()) {
    // Came from other page, let's initialize
    std::map<std::string, std::string> m;
    m["field"] = "name";
    m["status"] = "not saved";
    return createController(route, m, "", resolver);
  }
  if (!input.empty()) {
    // A field is filled, let's add it to respective field, and change the current editing field
    params["input_" + params["field"]] = input;
    if (!keyExists(params, "input_name")) {
      params["field"] = "name";
    } else if (!keyExists(params, "input_age")) {
      params["field"] = "age";
    } else if (!keyExists(params, "input_role")) {
      params["field"] = "role";
    } else if (!keyExists(params, "input_salary")) {
      params["field"] = "salary";
    } else if (!keyExists(params, "input_fired")) {
      params["field"] = "fired";
    } else if (!keyExists(params, "input_custom")) {
      params["field"] = "custom";
    } else {
      // All fields are filled in already, save to disk, return error page if encountered any errors
      Employee e;
      e.name = params["input_name"];
      e.role = params["input_role"];
      e.age = std::stoi(params["input_age"]);
      e.salary = std::stof(params["input_salary"]);
      e.fired = params["input_fired"] == "true" || params["input_fired"] == "yes";
      e.customAttr = params["input_custom"];
      if (!e.upsert()) {
        return specialController("/error", params, "", resolver);
      }
      params["status"] = "success";
      params["field"] = "menu to go back";

    }

  }
  std::map<std::string, std::string> renderParams(params);
  if (!keyExists(renderParams, "input_name")) {
    renderParams["input_name"] = "______________";
  }
  if (!keyExists(renderParams, "input_age")) {
    renderParams["input_age"] = "______________";
  }
  if (!keyExists(renderParams, "input_role")) {
    renderParams["input_role"] = "______________";
  }
  if (!keyExists(renderParams, "input_salary")) {
    renderParams["input_salary"] = "______________";
  }
  if (!keyExists(renderParams, "input_fired")) {
    renderParams["input_fired"] = "______________";
  }
  if (!keyExists(renderParams, "input_custom")) {
    renderParams["input_custom"] = "______________";
  }
  return ControllerResult("/create", params, "", resolver.renderTemplate("create", renderParams));
  // Handle creation process
}
