Game Theory Tools
====

Project of a tool to finding Nash equilibria for given Games. Finding equilibria
is a an actual goal of my master thesis, so adding other functions will not be considered
until core functionality is implemented.

Requirements
----

Project is written with a C++ language, and so it require some C++ compiler to be present.
It also makes use of GNU Multiple Precision library, and several of Boost libraries.
These tools should be available in an user's environment for program to compile.

Compilations and dependencies are manged by a SCons tool. As such Python and SCons
installations are also required.

GTL parser uses Flex and Bison tools to build `.cpp` files.

On Debian dependencies can be installed by calling
`sudo apt-get install g++ bison flex libgmp-dev libboost-all-dev scons`.

During development program has been successfully building with:

* *g++* version *4.7.2*,
* *bison* version *2.5*,
* *flex* version *2.5.35*,
* *gmp* version *2.5.0.5+dfsg-2*,
* *boost* version *1.49*,
* *scons* version *2.1.0.r5357[MODIFIED]*,

on Debian 7.1 Stable (Wheezy).

Building process
----

To build program navigate in console to a root directory of a checked out project
and type `scons`. Program should be built automatically.

Object files will be placed in `objects/` directory.

Executables  will be placed in `bin/` directory.

Builder can also run specified tasks:

* `scons -Q buildModels` - builds Models' classes,
* `scons -Q buildModelsTests` - builds Models' test classes with dependancies,
* `scons -Q runModelsTests` - runs Models' test classes building theirs dependancies,
* `scons -Q buildPsrserClasses` - builds Parser and Scanner with yacc (bison) and lex (flex),
* `scons -Q buildGTL` - builds GTL classes,
* `scons -Q buildGTLTests` - builds GTL test classes with dependancies,
* `scons -Q runGTLTests` - runs GTL test classes building theirs dependancies,
* `scons -Q buildPrograms` - builds Program's Controllers classes,
* `scons -Q buildProgramsTests` - builds Program's Controllers test classes with dependancies,
* `scons -Q runProgramsTests` - runs Program's Controllers test classes building theirs dependancies,
* `scons -Q buildExecutables` - build actual executables.

To build project using Clang you can run builder like this: `CXX="scan-build clang++" scons`,
but it hasn't been actually tested yet. Obviously, it would require Clang installed.

Running tests
----

To run tests manually call `bin/ModelsTests && bin/GTLTests && bin/ProgramsTests`. Notice that they
will be run automatically during build as well.

For more information you can run each of them with `--log_level=test_suite` parameter.

Running program
----

To run program you need to execute `./gtl_program` command. If not set otherise it will read
from standard input and write to standard output and standard error. More information can be found
when run with `--help` argument: `./gtl_program --help`.

Some examples of correct GTL syntax can be found in `examples` directory.

TODO
----

* Implement actual logic of finding equilibria,
* test it,
* create main function that parses arguments and initiates parser.
* Improve singletons - instances and mutexes variables can probaby be replaced with statrc ones,
* same for strings inside toString() methods. It could help avoid continous reallocation of memory,
* add Sublime Text settings for displaying line at 120 signs and make sure that nowhere that limit
  is exceeded,
* add Condition to set calculations accuracy.
