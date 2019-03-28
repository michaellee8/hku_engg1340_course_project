# HKU ENGG1340 Course Project

Welcome to this course project repo, here you will see the source code of this project.  
Licensed under GNU Public License v3.0

In this project, we assumes the terminal to be a xterm of size 80x24. Alternative size are temporarily not supported. 

## Problem statement
Companies, especially those in big scale, usually contain numbers of employees. Those employees hold different types of information and data. For example, their first name and family name, age, role, salary, entry time and more. Without a proper data storing and manipulating system, it is hard for the employers to check or edit the data of the employees. 

## Problem setting
To esaily access to and make changes on the data of employees, a complete data manipulating system is required. In this project, several functions will be included in our employee mamagement system. 'Create' function to add new employees into the data base system (employee ID will be automatically generated). 'Search' function allowing employers or managers to search for employees by employee ID, name, age or salary. 'List' function to show all current employees working in the company. 'Delete' function to fire current employees. 'Edit' function to make changes on the data of employees and also 'Query' function. 

## Template system
In this project, we use a modular template system that allow us to work easier. All templates are resolved against `res/templates`. Templates are strings with a specific markers are place holders, e.g. `{{ text}}`. Each time a template is resolved, placeholders will be replaced with strings provided padded or cut into length of the placeholder. For example, given `{{_text___}}`, which have 12 characters, and text `abc`, it will be replaced into `abc_________`. Note that `_` represent spaces. Now the version requires you to put `c|l|r` to represent alignment of the text inserted.

## Some tips
1. Never write `using namespace std;` please, it is harmful.
2. This application only support linux officially, there are no guarantee to work on Windows or Mac. Mac may have better probability on working since it is Unix-based.
3. You are highly suggest to use CLion to develop this thing, it just works.

## Additional funcion
Maybe we can make a Python-like query system that allow users to do complex query on specifying `id|name|age|role|salary|cattr`, with logic operator `or|and` and comparison operator `<|<=|>|>=|=`.This is basically SQL. 
