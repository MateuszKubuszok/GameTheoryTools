#include "gt/program/inner_common.hpp"

namespace GT {
namespace Program {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ProgramController {
// public:

ProgramController::ProgramController() {}

ProgramController& ProgramController::setCheckingOnly() {
    return *this;
}

ProgramController& ProgramController::setCheckingAndExecution() {
    return *this;
}

ProgramController& ProgramController::setDefaultInputStream() {
    return *this;
}

ProgramController& ProgramController::setFileInputStream(
    std::string filename
) {
    return *this;
}

ProgramController& ProgramController::setInputStream(
    std::istream* inputStream
) {
    return *this;
}

ProgramController& ProgramController::setDefaultOutputStream() {
    return *this;
}

ProgramController& ProgramController::setFileOutputStream(
    std::string filename
) {
    return *this;
}

ProgramController& ProgramController::setOutputStream(
    std::ostream* inputStream
) {
    return *this;
}

ProgramController& ProgramController::setDefaultErrorStream() {
    return *this;
}

ProgramController& ProgramController::setFileErrorStream(
    std::string filename
) {
    return *this;
}

ProgramController& ProgramController::setErrorStream(
    std::ostream* errorStream
) {
    return *this;
}

void ProgramController::runAsProgram() {}

// }; /* END class ProgramController */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Program */
} /* END namespace GT */
