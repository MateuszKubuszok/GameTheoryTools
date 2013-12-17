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
    isInteractiveInput(true),
    shouldFreeInputStream(false),
    shouldFreeOutputStream(false),
    shouldFreeErrorStream(false),
    resultBuilderMode(Model::ResultBuilderMode::PLAIN),
    resultIndentationMode(Model::ResultIndentationMode::TABS)
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
    return setInputStream(&std::cin, false, true);
}

ProgramController& ProgramController::setInputStream(
    const std::string filename
) {
    std::ifstream* newInputStream = new std::ifstream();
    newInputStream->open(filename);
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
    return setOutputStream(&std::cout, false);
}

ProgramController& ProgramController::setOutputStream(
    const std::string filename
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
    const std::string filename
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

ProgramController& ProgramController::setResultBuilderMode(
    const Model::ResultBuilderMode newResultBuilderMode
) {
    resultBuilderMode = newResultBuilderMode;
    return *this;
}

ProgramController& ProgramController::setResultIndentationMode(
    const Model::ResultIndentationMode newResultIndentationMode
) {
    resultIndentationMode = newResultIndentationMode;
    return *this;
}

int ProgramController::run() const {
    Model::ResultFactory::getInstance()
        .setBuilderMode(resultBuilderMode)
        .setIndentationMode(resultIndentationMode);

    GTL::DriverPtr driver(
        shouldExecute ?
        GTL::DriverFactory::getInstance().createExecutionDriver(outputStream, errorStream) :
        GTL::DriverFactory::getInstance().createCheckingDriver(errorStream)
    );
    GTL::Scanner scanner(inputStream);
    scanner.setInteractive(isInteractiveInput);
    GTL::Parser  parser(scanner, *driver);
    parser.set_debug_level(debugLevel);

    return parser.parse();
}

// }; /* END class ProgramController */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Program */
} /* END namespace GT */
