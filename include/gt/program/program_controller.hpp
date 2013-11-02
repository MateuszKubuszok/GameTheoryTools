#ifndef __GT_MAIN_PROGRAM_CONTROLLER_HPP__
#define __GT_MAIN_PROGRAM_CONTROLLER_HPP__

namespace GT {
namespace Program {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ProgramController {
    std::istream*  inputStream;
    std::ostream*  outputStream;
    std::ostream*  errorStream;

    GTL::DriverPtr driver;

public:
    ProgramController();

    ProgramController& setCheckingOnly();

    ProgramController& setCheckingAndExecution();

    ProgramController& setDefaultInputStream();

    ProgramController& setFileInputStream(
        std::string filename
    );

    ProgramController& setInputStream(
        std::istream* inputStream
    );

    ProgramController& setDefaultOutputStream();

    ProgramController& setFileOutputStream(
        std::string filename
    );

    ProgramController& setOutputStream(
        std::ostream* inputStream
    );


    ProgramController& setDefaultErrorStream();

    ProgramController& setFileErrorStream(
        std::string filename
    );

    ProgramController& setErrorStream(
        std::ostream* errorStream
    );

    void runAsProgram();
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Program */
} /* END namespace GT */

#endif /* #ifndef __GT_MAIN_PROGRAM_CONTROLLER_HPP__ */
