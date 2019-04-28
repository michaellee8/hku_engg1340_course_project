# HKU ENGG1340 Course Project

Welcome to this course project repo, here you will see the source code of this project.  
Licensed under GNU Public License v3.0

In this project, we assumes the terminal to be a xterm of size 80x24. Alternative size are temporarily not supported. 

## Problem statement
Companies, especially those in big scale, usually contain numbers of employees. Those employees hold different types of information and data. For example, their first name and family name, age, role, salary, entry time and more. Without a proper data storing and manipulating system, it is hard for the employers to check or edit the data of the employees. 

## Problem setting
All attributes should be well-input when adding new employees. Therefore, data managing and editing works can be done without errors. Also for ordinary people, we assume that the name of the employees will not be longer than 20 characters. For a extremely long employee name, our 'List' function will not be able to show the whole spelling of the employee name. However, the whole spelling of the employee name can still be showed in the 'Profile page'.

## Requirements

1. User can create new employees with employee ID automatically assigned with the input name, age, role, and salary.
2. User can search for the employees by their ID, name, age or role, all attributes of the employee will then be listed.
3. User can delete employees and all their attributes.
4. User can edit any of the attributes of employees. 
5. User can search for employees within a salary range.
6. User can add new attributes of employees according to their needs.
7. User can operate complex query with logic operators.

## Template system
In this project, we use a modular template system that allow us to work easier. All templates are resolved against `res/templates`. Templates are strings with a specific markers are place holders, e.g. `{{ text}}`. Each time a template is resolved, placeholders will be replaced with strings provided padded or cut into length of the placeholder. For example, given `{{_text___}}`, which have 12 characters, and text `abc`, it will be replaced into `abc_________`. Note that `_` represent spaces. Now the version requires you to put `c|l|r` to represent alignment of the text inserted.

## System archietecture
In this project, we adapt a highly modular, maintainable, reusbale and productive MVC architecture. The V (view) is inside `res/templates`, which is consumed by the template system in `template_resolver` as noted above. The M (model) is inside `models/employee`, which attempts to construct a ORM following the Active Record pattern. The C (controller) is inside `controllers`, which consumes user input, routing parameters, models and views to provide program output, which is consumed by the main digest loop located in `main.cpp`. The backend components of the query system is located in `controllers/querysys`, which provides reusable components for the query system.

## Some tips
1. Never write `using namespace std;` please, it is harmful.
2. This application only support linux officially, there are no guarantee to work on Windows or Mac. Mac may have better probability on working since it is Unix-based.
3. You are highly suggest to use CLion to develop this thing, it just works.

## Additional function
Maybe we can make a Python-like query system that allow users to do complex query on specifying `id|name|age|role|salary|custom`, with logic operator `or|and` and comparison operator `<|<=|>|>=|=`.This is basically less advanced version of SQL.

## Execution instruction
For ssh user, run `./prep.sh` before using the app in current working directory.

The first page of the program is the welcome template. User should input 'menu' to get into the menu page. User can choose different function by inputtung the respective command. 

For `create` function, the program will require user to input the `name`, `age`, `role`, `salary`, `fired`(whether the employee is fired or not) and `custom`. Note that user should input 'yes' or 'no' for the `fired` attribute.  After inputting all attributes of the new employee, the data of the employee will be saved. User should then input 'meun' to get back to the menu page.

For `search` function, user can search for employees according to different attributes by inputting the corresponding command. Note that for searching by name, user should input the __full name__ of the employee, otherwise the employee will not be shown. By inputting the command 'all', the program will reqiure user to input a random non-empty value, all the employees will then be listed. After getting the results of the search, user can input 'prev' or 'next' to switch the page of the list, or input 'menu' to go back to the menu page. User can also input the `id` of a specified employee to get into the managing page to manage the employee.

In the managing page, user can choose to input the attribute name to edit the corresponding value of the employee. For example, to edit `role` of the employee, type 'role' in the managing page, and input the new value of `role`. The new value of employee `role` will then be saved. User can also enter 'delete' to remove the whole employee from the employee list. To get back to the list , type 'list'. Type 'menu' to get back to the menu page. User can also type '.exit' to exit the program directly.

To exit the program, user can always input '.exit' to stop the entire program.

## Building instructions
Assuming you are using a linux user with sudo here.
1. `cd ~`
2. `sudo apt-get install g++ gcc cmake make git`
3. `git clone https://github.com/michaellee8/hku_engg1340_course_project.git`
4. `cd hku_engg1340_course_project`
5. `mkdir build`
6. `cd build`
7. `cmake ..`
8. `make`
9. `cd ../`
10. `./prep.sh`
11. `./build/hku_engg1340_course_project`
