# ReplaceRespectCase
A simple Command Line Utility useful to replace patterns in code.
Useful in Vim.

# Example
When writing code where classname and global have the same name.
````
echo "class Classname { ... } varname;" | rrc Users Groups
`````
produces
````
class Users { ... } users;
class Groups { ... } groups;
````

