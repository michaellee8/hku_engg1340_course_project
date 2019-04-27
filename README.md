# HKU ENGG1340 Course Project

Welcome to this course project repo, here you will see the source code of this project.  
Licensed under GNU Public License v3.0

In this project, we assumes the terminal to be a xterm of size 80x24. Alternative size are temporarily not supported. 

## Problem statement
Companies, especially those in big scale, usually contain numbers of employees. Those employees hold different types of information and data. For example, their first name and family name, age, role, salary, entry time and more. Without a proper data storing and manipulating system, it is hard for the employers to check or edit the data of the employees. 

## Problem setting
All attributes should be well-input when adding new employees. Therefore, data managing and editting works can be done without errors. Also for ordinary people, we assume that the name of the employees will not be longer than 20 characters. For a extremely long employee name, our 'List' function will not be able to show the whole spelling of the employee name. However, the whole spelling of the employee name can still be showed in the 'Profile page'.

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

## Some tips
1. Never write `using namespace std;` please, it is harmful.
2. This application only support linux officially, there are no guarantee to work on Windows or Mac. Mac may have better probability on working since it is Unix-based.
3. You are highly suggest to use CLion to develop this thing, it just works.

## Additional funcion
Maybe we can make a Python-like query system that allow users to do complex query on specifying `id|name|age|role|salary|cattr`, with logic operator `or|and` and comparison operator `<|<=|>|>=|=`.This is basically SQL. 

## Execution instruction
For ssh user, run `./prep.sh` before using the app in current working directory.

The first page of the program is the welcome template. User should input 'menu' to get into the menu page. User can choose different function by inputtung the respective command. 

For `create` function, the program will require user to input the `name`, `age`, `role`, `salary`, `fired`(whether the employee is fired or not) and `custom`. Note that user should input 'yes' or 'no' for the `fired` attribute.  After inputting all attributes of the new employee, the data of the employee will be saved. User should then input 'meun' to get back to the menu page.

For `search` function, user can search for employees according to different attributes by inputting the corresponding command. Note that for searching by name, user should input the full name of the employee, otherwise the employee cannot be showed. By inputting the command `'all'`, the program will reqiure user to input a random non-empty value, all the employees will then be listed. After getting the results of the search, user can input `'prev'` or `'next`' to switch the page of the list, or input `'menu'` to go back to the menu page. User can also input the `id` of a specified employee to manage the employee.
