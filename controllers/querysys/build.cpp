//
// Created by michaellee8 on 4/28/19.
//

#include "build.h"

selectFunction buildQuery(std::vector<std::string> tks) {
  if (tks.size() < 3) {
    return nullptr;
  }
  return buildOrQuery(tks);
}
selectFunction buildOrQuery(std::vector<std::string> tks) {
  if (tks.size() < 3) {
    return nullptr;
  }

  std::vector<std::string> cv;
  std::vector<selectFunction> fns;

  for (auto const tk:tks) {
    if (tk == "or") {
      fns.push_back(buildAndQuery(cv));
      cv = std::vector<std::string>();
    } else {
      cv.push_back(tk);
    }
  }

  fns.push_back(buildAndQuery(cv));

  return logicalOrFunction(fns);
}
selectFunction buildAndQuery(std::vector<std::string> tks) {
  if (tks.size() < 3) {
    return nullptr;
  }

  std::vector<std::string> cv;
  std::vector<selectFunction> fns;

  for (auto const tk:tks) {
    if (tk == "and") {
      fns.push_back(buildSimpleQuery(cv));
      cv = std::vector<std::string>();
    } else {
      cv.push_back(tk);
    }
  }

  fns.push_back(buildSimpleQuery(cv));

  return logicalAndFunction(fns);
}
selectFunction buildSimpleQuery(std::vector<std::string> tks) {
  if (tks.size() != 3) {
    return nullptr;
  }
  return getComparisonFunction(tks[0], tks[1], tks[2]);
}