#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <unistd.h>
#include "./template_resolver.h"
#include "./util.h"
#include "./controllers/controller.h"
#include "./controllers/menu_controller.h"
#include "./controllers/welcome_controller.h"
#include "./controllers/special_controller.h"
#include "./controllers/create_controller.h"
#include "./controllers/search_controller.h"
#include "./controllers/edit_controller.h"
#include "./controllers/query_controller.h"

void start();

unsigned long mix(unsigned long a, unsigned long b, unsigned long c);
int main() {

  unsigned long seed = mix(clock(), time(NULL), getpid());
  srand(seed);

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
    routes["/edit"] = editController;
    routes["/query"] = queryController;
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

// Took this from https://stackoverflow.com/questions/322938/recommended-way-to-initialize-srand
// http://www.concentric.net/~Ttwang/tech/inthash.htm
unsigned long mix(unsigned long a, unsigned long b, unsigned long c) {
  a = a - b;
  a = a - c;
  a = a ^ (c >> 13);
  b = b - c;
  b = b - a;
  b = b ^ (a << 8);
  c = c - a;
  c = c - b;
  c = c ^ (b >> 13);
  a = a - b;
  a = a - c;
  a = a ^ (c >> 12);
  b = b - c;
  b = b - a;
  b = b ^ (a << 16);
  c = c - a;
  c = c - b;
  c = c ^ (b >> 5);
  a = a - b;
  a = a - c;
  a = a ^ (c >> 3);
  b = b - c;
  b = b - a;
  b = b ^ (a << 10);
  c = c - a;
  c = c - b;
  c = c ^ (b >> 15);
  return c;
}