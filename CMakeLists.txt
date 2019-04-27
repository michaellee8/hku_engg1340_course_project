cmake_minimum_required(VERSION 3.10)
project(hku_engg1340_course_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hku_engg1340_course_project main.cpp template_resolver.cpp template_resolver.h models/employee.cpp models/employee.h util.cpp util.h controllers/controller.h controllers/welcome_controller.cpp controllers/welcome_controller.h controllers/menu_controller.cpp controllers/menu_controller.h controllers/query_controller.cpp controllers/query_controller.h controllers/special_controller.cpp controllers/special_controller.h controllers/controller.cpp controllers/create_controller.cpp controllers/create_controller.h controllers/search_controller.cpp controllers/search_controller.h controllers/edit_controller.cpp controllers/edit_controller.h controllers/querysys/tokenizer.cpp controllers/querysys/tokenizer.h controllers/querysys/comparison.cpp controllers/querysys/comparison.h controllers/querysys/build.cpp controllers/querysys/build.h)

target_link_libraries(${PROJECT_NAME} PRIVATE "stdc++fs")