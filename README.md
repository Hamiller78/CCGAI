![Logo of the project](https://raw.githubusercontent.com/jehna/readme-best-practices/master/sample-logo.png)

# CCGAI
> The framework for artificial intelligence for customizable card games

The CCGAI project provides a framework to display CCGs and add AI functionality
via the use of the scripting language. The framework itself should
provide general information to run and analyze a card game, while all
game-specific parts like rules and special abilities of cards should be
implemented in scripts.

## Installing / Getting started

The framework itself is written in C++11 within the QT framework. Development
is done with the QT Creator 4.5.1 (using the Qt libraries 5.9.2) and the 
MSVC2015 32Bit compiler.

In addition Python 3.6 is used as the script language. The project requires
two environment variables to find the Python includes and libs:
PYTHONINCLUDE - pointing to the directory with the Python include files
PYTHONLIBS - pointing to the libs directory of Python
After that the project should compile.

I refrain from setting the standard Python environment variables, since that
caused trouble with other applications allowing Python scripts.

You will have to copy the content of the Libs directory from Python to the
PythonLibs directory in Testdata to run the unit tests, or Python will fail
to initialize.

At the current stage you can run the unit tests of the project within the
Qt creator.

## Developing

Here's a brief intro about what a developer must do in order to start developing
the project further:

```shell
git clone https://github.com/Hamiller78/CCGAI
### Deploying / Publishing

In case there's some step you have to take that publishes this project to a
server, this is the right time to state it.

```shell
packagemanager deploy awesome-project -s server.com -u username -p password
```

And again you'd need to tell what the previous code actually does.

## Features

What's all the bells and whistles this project can perform?
* What's the main functionality
* You can also do another thing
* If you get really randy, you can even do this

## Configuration

Here you should write what are all of the configurations a user can enter when
using the project.

#### Argument 1
Type: `String`  
Default: `'default value'`

State what an argument does and how you can use it. If needed, you can provide
an example below.

Example:
```bash
awesome-project "Some other value"  # Prints "You're nailing this readme!"
```

#### Argument 2
Type: `Number|Boolean`  
Default: 100

Copy-paste as many of these as you need.

## Contributing

When you publish something open source, one of the greatest motivations is that
anyone can just jump in and start contributing to your project.

These paragraphs are meant to welcome those kind souls to feel that they are
needed. You should state something like:

"If you'd like to contribute, please fork the repository and use a feature
branch. Pull requests are warmly welcome."

If there's anything else the developer needs to know (e.g. the code style
guide), you should link it here. If there's a lot of things to take into
consideration, it is common to separate this section to its own file called
`CONTRIBUTING.md` (or similar). If so, you should say that it exists here.

## Links

Even though this information can be found inside the project on machine-readable
format like in a .json file, it's good to include a summary of most useful
links to humans using your project. You can include links like:

- Project homepage: https://your.github.com/awesome-project/
- Repository: https://github.com/your/awesome-project/
- Issue tracker: https://github.com/your/awesome-project/issues
  - In case of sensitive bugs like security vulnerabilities, please contact
    my@email.com directly instead of using issue tracker. We value your effort
    to improve the security and privacy of this project!
- Related projects:
  - Your other project: https://github.com/your/other-project/
  - Someone else's project: https://github.com/someones/awesome-project/


## Licensing

One really important part: Give your project a proper license. Here you should
state what the license is and how to find the text version of the license.
Something like:

"The code in this project is licensed under MIT license."
