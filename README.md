![Logo of the project](https://raw.githubusercontent.com/jehna/readme-best-practices/master/sample-logo.png)

# CCGAI
> The framework for artificial intelligence for customizable card games

The CCGAI project provides a framework to display CCGs and add AI functionality
via the use of the scripting language. The framework itself should
provide general information to run and analyze a card game, while all
game-specific parts like rules and special abilities of cards should be
implemented in scripts.

## Installing / Getting started

At the current early stage you can only run the unit tests of the project within the
Qt creator.

The framework itself is written in C++11 within the QT framework. Development
is done with the QT Creator 4.5.1 (using the Qt libraries 5.9.2) and the 
MSVC2015 32Bit compiler.

In addition Python 3.6 is used as the script language.

## Developing

Check out the project. You can open it using the Qt Creator.

The project requires two environment variables to find the Python includes and libs:
PYTHONINCLUDE - pointing to the directory with the Python include files
PYTHONLIBS - pointing to the libs directory of Python
After that the project should compile.

I refrain from setting the standard Python environment variables, since that
caused trouble with other applications allowing Python scripts.

You will have to copy the content of the Libs directory from Python to the
PythonLibs directory testdata/pythonlib to run the unit tests, or Python will fail
to initialize.

The plugin format describing card games is taken from the freeware LackeyCCG, which
allows online card games between human players.
The goal of this project is to extend these plugin directories with AI functionality.

## Links

Even though this information can be found inside the project on machine-readable
format like in a .json file, it's good to include a summary of most useful
links to humans using your project. You can include links like:

- Repository: https://www.github.com/Hamiller78/CCGAI/
- Related projects:
  - Qt homepage: https://www.qt.io/
  - Python homepage: https://www.python.org/
  - LackeyCCG  homepage: http://lackeyccg.com/


## Licensing

The code in this project is licensed under GNU General Public License Version 3
as described in the file LICENSE.
