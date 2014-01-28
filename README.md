# Game Theory Tools

Project of a tool to finding Nash equilibria for given Games. Finding equilibria is a an actual goal of my
master thesis, so adding other functions will not be considered until core functionality is implemented.


## Requirements

Project is written with a C++ language, and so it require some C++ compiler to be present. It also makes use
of GNU Multiple Precision library, and several of Boost libraries. These tools should be available in an
user's environment for program to compile.

Compilations and dependencies are manged by a SCons tool. As such Python and SCons installations are also
required.

GTL parser uses Flex and Bison tools to build `.cpp` files.

### Linux pre-requirements installation

On Debian (and Debian-based distributions) dependencies can be installed by calling
`sudo apt-get install g++ bison flex libgmp-dev libboost-all-dev scons`.

During development program has been successfully building with:

 * **g++** version *4.7.2*,
 * **bison** version *2.5*,
 * **flex** version *2.5.35*,
 * **gmp** version *2.5.0.5+dfsg-2*,
 * **boost** version *1.49*,
 * **scons** version *2.1.0.r5357[MODIFIED]*,

on *Debian 7.2 Stable* (*Wheezy*).

### Windows pre-requirements installation

On *Windows 7* the project was successfully built with *Cygwin* and following items installed:

 * Devel:
    * **gcc-core** version *4.8.2*,
    * **gcc-c++** version *4.8.2*,
    * **bison** version *2.7.1-1*,
    * **flex** version *2.5.35-3*,
    * **scons** version *2.3.0-5*,
 * Math:
    * **gmp** version *5.1.3-1*,
    * **libgmp-devel** version *5.1.3-1*,
    * **libgmp10** version *5.1.3-1*,
    * **libgmpxx4** version *5.1.3-1*

as well as their required dependencies.

Boost libraries need to be build manually separately since version provided with Cygwin doesn't contain e.g.
*Boost Unit Test Framework* - version *1.54* is known to work well. After extracting source to directory of
choice call commands under Cygwin terminal:

    cd [boost directory]
    ./bootstrap.sh
    ./b2 install --prefix=[cygwin directory]                                   # for x86 (32-bit)
    ./b2 install --prefix=[cygwin directory] architecture=x86 address-model=64 # for x86_64 (64-bit)

making sure that choosen architecture matches Cygwin's one. Alternatively you might try any other tutorial
explaining how to install Boost on Windows and make it visible to Cygwin environment.


## Building process

To build program navigate in console to a root directory of a checked out project and type `scons`. Program
should be built automatically.

Object files will be placed in `objects/` directory.

Executables  will be placed in `bin/` directory.

Builder can also run specified tasks:

 * `scons -Q buildModels` - builds Models' classes,
 * `scons -Q buildModelsTests` - builds Models' test classes with dependancies,
 * `scons -Q runModelsTests` - runs Models' test classes building theirs dependancies,
 * `scons -Q buildRoutines` - builds Routines' classes,
 * `scons -Q buildRoutinesTests` - builds Routines' test classes with dependancies,
 * `scons -Q runRoutinesTests` - runs Routines' test classes building theirs dependancies,
 * `scons -Q buildParserClasses` - builds Parser and Scanner with yacc (bison) and lex (flex),
 * `scons -Q buildGTL` - builds GTL classes,
 * `scons -Q buildGTLTests` - builds GTL test classes with dependancies,
 * `scons -Q runGTLTests` - runs GTL test classes building theirs dependancies,
 * `scons -Q buildPrograms` - builds Program's Controllers classes,
 * `scons -Q buildProgramsTests` - builds Program's Controllers test classes with dependancies,
 * `scons -Q runProgramsTests` - runs Program's Controllers test classes building theirs dependancies,
 * `scons -Q buildExecutables` - builds actual executables,
 * `scons -Q buildLibraries` - builds static and shared library with Models and Routines.

To build project using Clang you might try run builder like this: `CXX="scan-build clang++" scons`. As of now
some files would not compile with Clang (*1:3.0-6.2*), but that might change in the future. Obviously it would
require Clang installed.


## Running tests

To run tests manually call
`bin/ModelsTests && bin/RoutinesTests && bin/GTLTests && bin/ProgramsTests`.
Notice that they will be run automatically during build as well.

For more information you can run each of them with `--log_level=test_suite` parameter.


## Running program

To run program you need to execute `./gtl_program` command. If not set otherise it will read from standard
input and write to standard output and standard error. More information can be found when run with `--help`
argument: `./gtl_program --help`.

Some examples of correct GTL syntax can be found in `examples` directory.


## Generating documentation

To generate documentation `Doxygen` version `1.8.5` is recommended. Versions prior to `1.8.2` did not have
C++11 support, and will generate invalid documentation due to e.g. `final` specifier usage.

Before running Doxygen execute `scone -Q buildParserClasses` task to make sure that flex-and-bison generated
files are present during the generation of documentation.

To generate public API - the one actually intended to use by a programmer - run command
`doxygen doxygen/public_api`from main dicrectory.

To generate full documentation - the one documenting all classes, including those intended to be hidden from
programmer - run command `doxygen doxygen/private_api` from main dicrectory.


## Documentation

Documentation itself can also be found [here](https://github.com/MateuszKubuszok/MasterThesis/wiki).


## To do

 * Implement 2-player matrix and 0-sum routines for strategic-from games,
 * add Condition to set calculations accuracy.


## License

Game Theory Tools - tools for calculating Nash equilibria.
Copyright (C) 2013-2014  Mateusz Kubuszok

This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero
General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public
License for more details.

Full license can be found [here](LICENSE.md) or on [gnu.org](http://www.gnu.org/licenses/).
