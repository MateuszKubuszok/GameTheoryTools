#include "gt/program/inner_common.hpp"

namespace GT {
namespace Program {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ProgramController {
// public:

ProgramController::ProgramController() :
    debugLevel(0),
    shouldExecute(true),
    inputStream(&std::cin),
    outputStream(&std::cout),
    errorStream(&std::cerr),
    shouldFreeInputStream(false),
    shouldFreeOutputStream(false),
    shouldFreeErrorStream(false)
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
    return setInputStream(&std::cin, false);
}

ProgramController& ProgramController::setInputStream(
    std::string filename
) {
    std::ifstream* newInputStream = new std::ifstream();
    newInputStream->open(filename);
    return setInputStream(newInputStream, true);
}

ProgramController& ProgramController::setInputStream(
    InputStream* newInputStream,
    bool         shouldFreeStream
) {
    if (inputStream != nullptr && shouldFreeInputStream)
        delete inputStream;

    inputStream           = newInputStream;
    shouldFreeInputStream = shouldFreeStream;

    return *this;
}

ProgramController& ProgramController::setDefaultOutputStream() {
    return setOutputStream(&std::cout, false);
}

ProgramController& ProgramController::setOutputStream(
    std::string filename
) {
    std::ofstream* newOutputStream = new std::ofstream();
    newOutputStream->open(filename);
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
    return setErrorStream(&std::cerr, false);
}

ProgramController& ProgramController::setErrorStream(
    std::string filename
) {
    std::ofstream* newErrorStream = new std::ofstream();
    newErrorStream->open(filename);
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

int ProgramController::run() {
    GTL::ScannerPtr scanner(new GTL::Scanner(inputStream));
    GTL::DriverPtr  driver(
        shouldExecute ?
        GTL::DriverFactory::getInstance().createExecutionDriver(outputStream, errorStream) :
        GTL::DriverFactory::getInstance().createCheckingDriver(errorStream)
    );
    GTL::Parser     parser(*scanner, *driver);
    parser.set_debug_level(debugLevel);

    return parser.parse();
}

// }; /* END class ProgramController */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Program */
} /* END namespace GT */
