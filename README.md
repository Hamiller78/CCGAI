# CCGAI
> The framework for artificial intelligence for customizable card games

The CCGAI project provides a framework to display CCGs and add AI functionality
via the use of the scripting language. The framework itself should
provide general information to run and analyze a card game, while all
game-specific parts like rules and special abilities of cards should be
implemented in scripts.

## Installing / Getting started

At the current early stage you can only run the unit tests of the project.

The framework itself is written in C++11 using the QT5 framework. Development
was started with the QT Creator 4.7.2, but the project is now migrated
to Visual Studio 2019.

The GoogleTest/GoogleMock framework is used for the unit tests.

In addition JavaScript as supported by the Qt libraries is used as the script
language.

## Developing

Check out the repository. You can open it using the Visual Studio.

Also checkout the GoogleTest project (link below).
The project requires the following environment variable to find GoogleTest files:
GOOGLETEST_DIR - pointing to the directory with the googletest and googlemock
				 folders

Download the Qt libraries (currently tested with V5.12.6). You will have to add
the bin directory to your path, or the unit tests will not run in the test explorer
(only directly run as executable in debug mode in VS, since a temporary environment
variable named QTDIR is used by Visual Studio).

The following extensions for Visual Studio should be installed:
- QT Visual Studio Tools
- Test Adapter for Google Test
- optionally License Header Manager, if you don't want to add license notes to new
  files manually
				 
After that the project should build.
ns allowing Python scripts.

The plugin format describing card games is taken from the freeware LackeyCCG, which
allows online card games between human players.
The goal of this project is to extend these plugin directories with AI functionality.

## Links

- Repository: https://www.github.com/Hamiller78/CCGAI/
- Related projects:
  - Qt homepage: https://www.qt.io/
  - GoogleTest repository: https://github.com/google/googletest
  - LackeyCCG  homepage: http://lackeyccg.com/


## Licensing

The code in this project is licensed under GNU General Public License Version 3
as described in the file LICENSE.
