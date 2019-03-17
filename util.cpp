//
// Created by michaellee8 on 3/17/19.
//

#include "util.h"
#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <map>

inline std::string randomHex() {
  // Took reference from here https://stackoverflow.com/questions/5100718/integer-to-hex-string-in-c
  int num = std::rand() % 256;
  std::stringstream stream;
  stream << std::setfill('0') << std::setw(2)
         << std::hex << num;
  return stream.str();
}

// This one actually is not conforming to standard, just something that seems to be.
std::string generateUuid() {
  return randomHex() + randomHex() + randomHex() + randomHex() +
      "-" + randomHex() + randomHex() +
      "-" + randomHex() + randomHex() +
      "-" + randomHex() + randomHex() +
      "-" + randomHex() + randomHex() + randomHex() + randomHex() + randomHex() + randomHex();
}

bool writeToFS(std::string path, std::string content) {
  std::ofstream out(path);
  if (!out.is_open()) {
    return false;
  }
  out << content;
  out.close();
  return true;
}

std::string readFromFS(std::string path) {
  std::ifstream t(path);
  std::stringstream buffer;
  buffer << t.rdbuf();
  t.close();
  return buffer.str();
}

bool keyExists(std::map<std::string, std::string> map, std::string key) {
  return map.find(key) != map.end();
}