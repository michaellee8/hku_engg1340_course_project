# HKU ENGG1340 Course Project

Welcome to this course project repo, here you will see the source code of this project.  
Licensed under GNU Public License v3.0

In this project, we assumes the terminal to be a xterm of size 80x24. Alternative size are temporarily not supported.  

## Template system
In this project, we use a modular template system that allow us to work easier. All templates are resolved against `res/templates`. Templates are strings with a specific markers are place holders, e.g. `{{ text}}`. Each time a template is resolved, placeholders will be replaced with strings provided padded or cut into length of the placeholder. For example, given `{{_text___}}`, which have 12 characters, and text `abc`, it will be replaced into `abc_________`. Note that `_` represent spaces.

## Some tips
1. Never write `using namespace std;` please, it is harmful.