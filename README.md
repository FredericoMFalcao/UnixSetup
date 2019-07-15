# X11 Setup

# .vimrc
My vim initial configuration file.


# Vim Bin Utilities - Filters

### ReplaceRespectCase
A simple Command Line Utility useful to replace patterns in code.
Useful in Vim.

### Example
When writing code where classname and global have the same name.
````
echo "class Classname { ... } varname;" | rrc varname Users Groups
`````
produces
````
class Users { ... } users;
class Groups { ... } groups;
````

