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

Building process
----

To build program navigate in console to a root directory of a checked out project
and type `scons`. Program should be built automatically.

Object files will be placed in `objects/` directory.

Executables  will be placed in `bin/` directory.

Running tests
----

To run tests manually call `bin/ModelsTests`. Notice that they will be run
automatically during build as well.

TODO
----

* Finish Model implementation,
* write Models' tests,
* write GTL's tests,
* implement actual logic of finding equilibria,
* test it,
* create main function that parses arguments and initiates parser.
