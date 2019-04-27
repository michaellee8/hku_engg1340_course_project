//ri
// Created by michaellee8 on 4/27/19.
//

#include "edit_controller.h"
#include "../util.h"
#include "special_controller.h"
#include "../models/employee.h"
#include "search_controller.h"
#include "menu_controller.h"

const std::vector<std::string> fields{
    "name", "age", "role", "salary", "fired", "custom"
};

ControllerResult editController(std::string route,
                                std::map<std::string, std::string> params,
                                std::string input,
                                TemplateResolver resolver) {
  if (!keyExists(params, "id")) {
    // NO ID !!!
    return specialController("/error", std::map<std::string, std::string>(), "", resolver);
  }
  auto id = std::stoi(params["id"]);
  auto empl = Employee::select([id](Employee e) -> bool { return e.id == id; })[0];

  // Handle db actions
  if (input == "delete") {
    empl.remove();
    return searchController(params["from_route"], params, "", resolver);
  }

  // Handle navigation commands
  if (input == "back") {
    return searchController(params["from_route"], params, "", resolver);
  }
  if (input == "menu") {
    return menuController("/menu", std::map<std::string, std::string>(), "", resolver);
  }

  // Handle editing commands
  if (std::find(std::begin(fields), std::end(fields), input) != std::end(fields)) {
    // Enter editing mode
    params["field"] = input;
    std::map<std::string, std::string> renderParams;
    renderParams["fid"] = empl.fileId;
    renderParams["id"] = std::to_string(empl.id);
    renderParams["name"] = empl.name;
    renderParams["age"] = std::to_string(empl.age);
    renderParams["role"] = empl.role;
    renderParams["salary"] = std::to_string(empl.salary);
    renderParams["fired"] = empl.fired ? "Yes" : "No";
    renderParams["custom"] = empl.customAttr;
    renderParams["old"] = empl.getField(params["field"]);

    renderParams["field"] = input;
    return ControllerResult("/edit", params, "", resolver.renderTemplate("profile-editing", renderParams));
  }

  // Handle editing
  if (params.count("field") > 0 && !input.empty()) { // We are in editing mode
    if (empl.setField(params["field"], input)) {
      empl.upsert();
      params.erase("field");
      return editController("/edit", params, "", resolver);
    }


    // Invalid or empty input, continue show editing page
    std::map<std::string, std::string> renderParams;
    renderParams["fid"] = empl.fileId;
    renderParams["id"] = std::to_string(empl.id);
    renderParams["name"] = empl.name;
    renderParams["age"] = std::to_string(empl.age);
    renderParams["role"] = empl.role;
    renderParams["salary"] = std::to_string(empl.salary);
    renderParams["fired"] = empl.fired ? "Yes" : "No";
    renderParams["custom"] = empl.customAttr;
    renderParams["old"] = empl.getField(params["field"]);
    renderParams["field"] = params["field"];
    return ControllerResult("/edit", params, "", resolver.renderTemplate("profile-editing", renderParams));
  }


  // Render profile
  std::map<std::string, std::string> renderParams;
  renderParams["fid"] = empl.fileId;
  renderParams["id"] = std::to_string(empl.id);
  renderParams["name"] = empl.name;
  renderParams["age"] = std::to_string(empl.age);
  renderParams["role"] = empl.role;
  renderParams["salary"] = std::to_string(empl.salary);
  renderParams["fired"] = empl.fired ? "Yes" : "No";
  renderParams["custom"] = empl.customAttr;
  return ControllerResult("/edit", params, "", resolver.renderTemplate("profile", renderParams));
}