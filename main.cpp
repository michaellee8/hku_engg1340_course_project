#include <iostream>
#include <string>
#include <map>
#include "./template_resolver.h"
#include "./util.h"
#include "./controllers/controller.h"
#include "./controllers/menu_controller.h"
#include "./controllers/welcome_controller.h"
#include "./controllers/special_controller.h"
#include "./controllers/create_controller.h"
#include "./controllers/search_controller.h"

void start();

int main() {

  start();
  return 0;
}

void clear() {
  std::cout << "\033c" << std::flush;
}

void start() {
  try {
    // Start the digest loop
    std::map<std::string, controller> routes;
    routes["/welcome"] = welcomeController;
    routes["/menu"] = menuController;
    routes["/error"] = specialController;
    routes["/notimplemented"] = specialController;
    routes["/notfound"] = specialController;
    routes["/create"] = createController;
    routes["/search"] = searchController;
    TemplateResolver resolver;

    std::string nextInput = "";
    ControllerResult currentResult = ControllerResult("/welcome", std::map<std::string, std::string>(), "", "");
    for (;;) {
      clear();
      if (nextInput == ".exit") {
        return;
      }
      // Try to get controller to current route
      if (routes.find(currentResult.route) == routes.end()) {
        currentResult = routes["/notfound"]("/notfound", currentResult.params, nextInput, resolver);
      } else {
        currentResult = routes[currentResult.route](currentResult.route, currentResult.params, nextInput, resolver);
      }
      std::cout << currentResult.output;
      std::getline(std::cin, nextInput);
    }
  } catch (...) {
    clear();
    std::map<std::string, std::string> m;
    m["reason"] = "UNEXPECTED ERROR";
    std::cout << TemplateResolver().renderTemplate("/error", m) << std::endl;
  }
}