//
// Created by michaellee8 on 4/27/19.
//


#include <string>
#include <map>
#include "../template_resolver.h"
#include "./controller.h"

#include "search_controller.h"
#include "../util.h"
#include "../models/employee.h"
#include "cmath"
#include "menu_controller.h"

const std::vector<std::string> criterias{
    "id",
    "name",
    "age",
    "role",
    "salary higher",
    "salary lower"
};

ControllerResult searchController(std::string route,
                                  std::map<std::string, std::string> params,
                                  std::string input,
                                  TemplateResolver resolver) {

  // Input searching parameters
  if (!keyExists(params, "criteria")
      || std::find(std::begin(criterias), std::end(criterias), params["criteria"]) == std::end(criterias)) {
    // No criteria is selected yet or an incorrect one is selected

    if (input != "") {
      // Take input as criteria
      params["criteria"] = input;
      return searchController(route, params, "", resolver);
    }

    // Return criteria selection page
    return ControllerResult("/search",
                            params,
                            "",
                            resolver.renderTemplate("search-criteria", std::map<std::string, std::string>()));
  }
  if (!keyExists(params, "value")) {
    // No value yet

    if (input != "") {
      // Take input as value if it is reasonable
      if (params["criteria"] == "name" ||
          params["criteria"] == "role" ||
          ((params["criteria"] == "age" || params["criteria"] == "salary higher"
              || params["criteria"] == "salary lower") && isNumber(input)) ||
          (params["criteria"] == "id" && isInt(input))
          ) {
        params["value"] = input;
        return searchController(route, params, "", resolver);
      }
    }


    // Return value input page
    std::map<std::string, std::string> renderParams;
    renderParams["criteria"] = params["criteria"];
    return ControllerResult("/search", params, "", resolver.renderTemplate("search-value", renderParams));
  }


  // Process navigation commands
  if (keyExists(params, "page") && keyExists(params, "total_pages") && (input == "prev" || input == "next")) {
    if (input == "prev") {
      params["page"] = std::to_string(std::stoi(params["page"]) - 1);
    } else if (input == "next") {
      params["page"] = std::to_string(std::stoi(params["page"]) + 1);
    }
    return searchController(route, params, "", resolver);
  }

  // Process return command
  if (input == "menu") {
    return menuController("/menu", std::map<std::string, std::string>(), "", resolver);
  }

  // Process editing command
  if (isInt(input)) {

  }


  // We have both criteria and value now, let's do the real search
  std::vector<Employee> queryResult;
  if (params["criteria"] == "id") {
    auto id = std::stoi(params["value"]);
    queryResult = Employee::select([id](Employee e) -> bool { return e.id == id; });
  } else if (params["criteria"] == "name") {
    auto name = params["value"];
    queryResult = Employee::select([name](Employee e) -> bool { return e.name == name; });
  } else if (params["criteria"] == "role") {
    auto role = params["value"];
    queryResult = Employee::select([role](Employee e) -> bool { return e.role == role; });
  } else if (params["criteria"] == "age") {
    auto age = std::stof(params["value"]);
    queryResult =
        Employee::select([age](Employee e) -> bool { return (int) std::round(e.age) == (int) std::round(age); });
  } else if (params["criteria"] == "salary higher") {
    auto salary = std::stof(params["value"]);
    queryResult =
        Employee::select([salary](Employee e) -> bool { return e.salary >= salary; });
  } else if (params["criteria"] == "salary lower") {
    auto salary = std::stof(params["value"]);
    queryResult =
        Employee::select([salary](Employee e) -> bool { return e.salary <= salary; });
  }

  if (!keyExists(params, "page") || !keyExists(params, "total_pages")
      || std::stoul(params["page"]) > queryResult.size() / 10 + 1
      || std::stoul(params["page"]) <= 0) {
    params["total_pages"] = std::to_string(queryResult.size() / 10 + 1);
    params["page"] = std::to_string(1);
  }

  std::map<std::string, std::string> renderParams;
  renderParams["criteria"] = params["criteria"];
  renderParams["value"] = params["value"];
  renderParams["n"] = std::to_string(queryResult.size());
  renderParams["cp"] = params["page"];
  renderParams["tp"] = params["total_pages"];

  for (int i = (std::stoi(params["page"]) - 1) * 10; i < queryResult.size(); i++) {
    auto entry = i % 10;
    renderParams["i" + std::to_string(entry)] = std::to_string(queryResult[i].id);
    renderParams["n" + std::to_string(entry)] = queryResult[i].name;
    renderParams["a" + std::to_string(entry)] = std::to_string((long long int) queryResult[i].age);
    renderParams["r" + std::to_string(entry)] = queryResult[i].role;
    renderParams["s" + std::to_string(entry)] = std::to_string((long long int) queryResult[i].salary);
    renderParams["f" + std::to_string(entry)] = queryResult[i].fired ? "Y" : "N";
    renderParams["c" + std::to_string(entry)] = queryResult[i].customAttr;
  }

  for (int i = queryResult.size(); i < (std::stoi(params["total_pages"])) * 10; i++) {
    auto entry = i % 10;
    renderParams["i" + std::to_string(entry)] = "";
    renderParams["n" + std::to_string(entry)] = "";
    renderParams["a" + std::to_string(entry)] = "";
    renderParams["r" + std::to_string(entry)] = "";
    renderParams["s" + std::to_string(entry)] = "";
    renderParams["f" + std::to_string(entry)] = "";
    renderParams["c" + std::to_string(entry)] = "";
  }
  auto tmp = resolver.renderTemplate("search", renderParams);
  return ControllerResult("/search", params, "", resolver.renderTemplate("search", renderParams));
}