//ri
// Created by michaellee8 on 4/27/19.
//

#include "edit_controller.h"
#include "../util.h"
#include "special_controller.h"
#include "../models/employee.h"
#include "search_controller.h"
#include "menu_controller.h"

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
  if (input == "delete") {
    empl.remove();
    return searchController(params["from_route"], params, "", resolver);
  }
  if (input == "back") {
    return searchController(params["from_route"], params, "", resolver);
  }
  if (input == "menu") {
    return menuController("/menu", std::map<std::string, std::string>(), "", resolver);
  }


  // Render profile
  std::map<std::string, std::string> renderParams;
  renderParams["fid"] = empl.fileId;
  renderParams["id"] = std::to_string((int) empl.id);
  renderParams["name"] = empl.name;
  renderParams["age"] = std::to_string(empl.age);
  renderParams["role"] = empl.role;
  renderParams["salary"] = std::to_string(empl.salary);
  renderParams["fired"] = empl.fired ? "Yes" : "No";
  renderParams["custom"] = empl.customAttr;
  return ControllerResult("/edit", params, "", resolver.renderTemplate("profile", renderParams));
}