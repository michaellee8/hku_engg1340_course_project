//
// Created by michaellee8 on 4/28/19.
//

#include <string>
#include <vector>
#include "tokenizer.h"

/*
std::vector<std::string> fieldNames{
    "id", "name", "age", "role", "salary", "custom"
};

std::vector<std::string> logicalOperators{
    "and", "or"
};

std::vector<std::string> comparisonOperators{
    "=", "!=", "<=", ">=", "<", ">"
};
*/


// Every comparison part of query should be in format of <fieldName> <comparisonOperator> <"stringValue"|intValue>
// stringValue must be double quoted, stringvalue itself must not have double quotes

// Every usage of logical and should be like <comparison> and <comparison> and <comparison>
// Every usage of logical or should be like <...and...> or <...and...> or <...and...>

// White space must exist between tokens!

// After tokenizing, the double quotes should stay
std::vector<std::string> tokenizeQuery(std::string s) {
  std::vector<std::string> result;
  bool inQuote = false;
  std::string current_str;
  for (char &c : s) {
    if (!inQuote && c == ' ') {
      // Encountered space, skip until next non-space
      if (!current_str.empty()) {
        result.push_back(current_str);
        current_str = "";
      }
      continue;
    }
    if (c == '"') {
      // Encountered quote!
      if (!inQuote) {
        current_str = "";
        inQuote = true;
        current_str += '"';
      } else {
        current_str += '"';
        inQuote = false;
      }
      continue;
    }
    current_str += c;
  }
  if (!current_str.empty()) {
    result.push_back(current_str);
  }

  return result;
}