/**
 * @file      gt/program/program_controller.cpp
 * @brief     Defines GT::Program::ProgramController methods.
 * @copyright (C) 2013-2014
 * @author    Mateusz Kubuszok
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero
 * General Public License as published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this program. If not,
 * see [http://www.gnu.org/licenses/].
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "gt/program/inner_common.hpp"

namespace GT {
namespace Program {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using std::cin;
using std::cout;
using std::cerr;
using std::string;
using std::ifstream;
using std::ofstream;

using Model::ResultBuilderMode;
using Model::ResultIndentationMode;
using Model::ResultFactory;

using GTL::DriverFactory;
using GTL::DriverPtr;
using GTL::Scanner;
using GTL::Parser;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ProgramController final {
// public:

ProgramController::ProgramController() :
    debugLevel(0),
    shouldExecute(true),
    inputStream(&cin),
    outputStream(&cout),
    errorStream(&cerr),
    isInteractiveInput(true),
    shouldFreeInputStream(false),
    shouldFreeOutputStream(false),
    shouldFreeErrorStream(false),
    resultBuilderMode(ResultBuilderMode::PLAIN),
    resultIndentationMode(ResultIndentationMode::TABS)
    {}

ProgramController::~ProgramController() {
    if (inputStream != nullptr && shouldFreeInputStream)
        delete inputStream;

    if (outputStream != nullptr && shouldFreeOutputStream)
        delete outputStream;

    if (errorStream != nullptr && shouldFreeErrorStream)
        delete errorStream;
}

ProgramController& ProgramController::setCheckingOnly() {
    shouldExecute = false;
    return *this;
}

ProgramController& ProgramController::setCheckingAndExecution() {
    shouldExecute = true;
    return *this;
}

ProgramController& ProgramController::setDebugLevel(
    int newDebugLevel
) {
    debugLevel = newDebugLevel;
    return *this;
}

ProgramController& ProgramController::setDefaultInputStream() {
    return setInputStream(&cin, false, true);
}

ProgramController& ProgramController::setInputStream(
    const string filename
) {
    ifstream* newInputStream = new ifstream();
    newInputStream->open(filename); // TODO error checking
    return setInputStream(newInputStream, true, false);
}

ProgramController& ProgramController::setInputStream(
    InputStream* newInputStream,
    bool         shouldFreeStream,
    bool         isInteractive
) {
    if (inputStream != nullptr && shouldFreeInputStream)
        delete inputStream;

    inputStream           = newInputStream;
    shouldFreeInputStream = shouldFreeStream;
    isInteractiveInput    = isInteractive;

    return *this;
}

ProgramController& ProgramController::setDefaultOutputStream() {
    return setOutputStream(&cout, false);
}

ProgramController& ProgramController::setOutputStream(
    const string filename
) {
    ofstream* newOutputStream = new ofstream();
    newOutputStream->open(filename); // TODO error checking
    return setOutputStream(newOutputStream, true);
}

ProgramController& ProgramController::setOutputStream(
    OutputStream* newOutputStream,
    bool          shouldFreeStream
) {
    if (outputStream != nullptr && shouldFreeOutputStream)
        delete outputStream;

    outputStream           = newOutputStream;
    shouldFreeOutputStream = shouldFreeStream;

    return *this;
}

ProgramController& ProgramController::setDefaultErrorStream() {
    return setErrorStream(&cerr, false);
}

ProgramController& ProgramController::setErrorStream(
    const string filename
) {
    ofstream* newErrorStream = new ofstream();
    newErrorStream->open(filename); // TODO error checking
    return setErrorStream(newErrorStream, true);
}

ProgramController& ProgramController::setErrorStream(
    OutputStream* newErrorStream,
    bool          shouldFreeStream
) {
    if (errorStream != nullptr && shouldFreeErrorStream)
        delete errorStream;

    errorStream           = newErrorStream;
    shouldFreeErrorStream = shouldFreeStream;

    return *this;
}

ProgramController& ProgramController::setResultBuilderMode(
    const ResultBuilderMode newResultBuilderMode
) {
    resultBuilderMode = newResultBuilderMode;
    return *this;
}

ProgramController& ProgramController::setResultIndentationMode(
    const ResultIndentationMode newResultIndentationMode
) {
    resultIndentationMode = newResultIndentationMode;
    return *this;
}

int ProgramController::run() const {
    ResultFactory::getInstance()
        .setBuilderMode(resultBuilderMode)
        .setIndentationMode(resultIndentationMode);

    DriverPtr driver(
        shouldExecute ?
        DriverFactory::getInstance().createExecutionDriver(outputStream, errorStream) :
        DriverFactory::getInstance().createCheckingDriver(errorStream)
    );
    Scanner scanner(inputStream);
    scanner.setInteractive(isInteractiveInput);
    Parser  parser(scanner, *driver);
    parser.set_debug_level(debugLevel);

    return parser.parse();
}

// }; /* END class ProgramController */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Program */
} /* END namespace GT */
