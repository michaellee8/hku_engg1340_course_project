cmake_minimum_required(VERSION 3.13)
project(hku_engg1340_course_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hku_engg1340_course_project main.cpp template_resolver.cpp template_resolver.h models/employee.cpp models/employee.h util.cpp util.h)

target_link_libraries(${PROJECT_NAME} PRIVATE "stdc++fs")