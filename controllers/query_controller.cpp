//
// Created by michaellee8 on 4/27/19.
//


#include <string>
#include <map>
#include "../template_resolver.h"
#include "./controller.h"

#include "query_controller.h"
#include "../util.h"
#include "../models/employee.h"
#include "cmath"
#include "menu_controller.h"
#include "edit_controller.h"
#include "querysys/build.h"
#include "querysys/tokenizer.h"

ControllerResult queryController(std::string route,
                                 std::map<std::string, std::string> params,
                                 std::string input,
                                 TemplateResolver resolver) {

  // Input query
  if (!keyExists(params, "query")) {
    // No query input

    if (input != "") {
      // Take input as query
      if (buildQuery(tokenizeQuery(input)) != nullptr) {
        params["query"] = input;
      }
      return queryController(route, params, "", resolver);
    }

  }



  // Process navigation commands
  if (keyExists(params, "page") && keyExists(params, "total_pages") && (input == "prev" || input == "next")) {
    if (input == "prev") {
      params["page"] = std::to_string(std::stoi(params["page"]) - 1);
    } else if (input == "next") {
      params["page"] = std::to_string(std::stoi(params["page"]) + 1);
    }
    return queryController(route, params, "", resolver);
  }

  // Process return command
  if (input == "menu") {
    return menuController("/menu", std::map<std::string, std::string>(), "", resolver);
  }

  // Process editing command
  if (isInt(input) && Employee::select([input](Employee e) -> bool { return std::stoi(input) == e.id; }).size() > 0) {
    params["from_route"] = "/query";
    params["id"] = input;
    return editController("/edit", params, "", resolver);
  }


  // We have query now, let's do the real query
  std::vector<Employee> queryResult;
  if (keyExists(params, "query")) {
    queryResult = Employee::select(buildQuery(tokenizeQuery(params["query"])));
  }

  // Sort query results by id
  std::sort(queryResult.begin(), queryResult.end(), [](Employee e1, Employee e2) { return e1.id < e2.id; });

  if (!keyExists(params, "page") || !keyExists(params, "total_pages")
      || std::stoul(params["page"]) > queryResult.size() / 10 + 1
      || std::stoul(params["page"]) <= 0) {
    params["total_pages"] = std::to_string(queryResult.size() / 10 + 1);
    params["page"] = std::to_string(1);
  }

  std::map<std::string, std::string> renderParams;
  renderParams["query"] = keyExists(params, "query") ? params["query"] : "please input query";
  renderParams["n"] = std::to_string(queryResult.size());
  renderParams["cp"] = params["page"];
  renderParams["tp"] = params["total_pages"];

  for (int i = (std::stoi(params["page"]) - 1) * 10; i < queryResult.size() && i < (std::stoi(params["page"])) * 10;
       i++) {
    auto entry = i % 10;
    renderParams["i" + std::to_string(entry)] = std::to_string(queryResult[i].id);
    renderParams["n" + std::to_string(entry)] = queryResult[i].name;
    renderParams["a" + std::to_string(entry)] = std::to_string(queryResult[i].age);
    renderParams["r" + std::to_string(entry)] = queryResult[i].role;
    renderParams["s" + std::to_string(entry)] = std::to_string(queryResult[i].salary);
    renderParams["f" + std::to_string(entry)] = queryResult[i].fired ? "Y" : "N";
    renderParams["c" + std::to_string(entry)] = queryResult[i].customAttr;
  }

  for (int i = queryResult.size(); i < (std::stoi(params["page"])) * 10; i++) {
    auto entry = i % 10;
    renderParams["i" + std::to_string(entry)] = "";
    renderParams["n" + std::to_string(entry)] = "";
    renderParams["a" + std::to_string(entry)] = "";
    renderParams["r" + std::to_string(entry)] = "";
    renderParams["s" + std::to_string(entry)] = "";
    renderParams["f" + std::to_string(entry)] = "";
    renderParams["c" + std::to_string(entry)] = "";
  }\
  return ControllerResult("/query", params, "", resolver.renderTemplate("querysys", renderParams));
}