#include "gt/program/inner_common.hpp"

namespace Options = boost::program_options;
namespace Program = GT::Program;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(
    const int   argumentsNumber,
    const char* arguments[]
) {
    // Options declaration section

    const char helpOption[]         = "help";
    const char helpDescription[]    = "produce this message";

    int  debugValue                 = 0;
    const int  debugDefault         = 0;
    const char debugOption[]        = "debug-level";
    const char debugDescription[]   = "0 if no parser debugging, non 0 for debug allowed";

    std::string inputValue          = "";
    const std::string inputDefault  = "";
    const char inputOption[]        = "input-file,I";
    const char inputDescription[]   = "input file to be parsed - if no one given reads from standard input";

    std::string outputValue         = "";
    const std::string outputDefault = "";
    const char outputOption[]       = "output-file,O";
    const char outputDescription[]  = "output target - if no one given reads from standard output";

    std::string errorValue          = "";
    const std::string errorDefault  = "";
    const char errorOption[]        = "error-file,E";
    const char errorDescription[]   = "error target - if no one given reads from standard error";

    // Options setup

    Options::options_description description("Available options");
    description.add_options()
    (helpOption,                                                                            helpDescription)
    (debugOption,  Options::value<int>(&debugValue)->default_value(debugDefault),           debugDescription)
    (inputOption,  Options::value<std::string>(&inputValue)->default_value(inputDefault),   inputDescription)
    (outputOption, Options::value<std::string>(&outputValue)->default_value(outputDefault), outputDescription)
    (errorOption,  Options::value<std::string>(&errorValue)->default_value(errorDefault),   errorDescription)
    ;

    // Parsing variables from arguments

    Options::variables_map variables;
    Options::store(
        Options::parse_command_line(argumentsNumber, arguments, description),
        variables
    );
    Options::notify(variables);

    // Display help if requested

    if (variables.count(helpOption)) {
        std::cout << description << std::endl;
        return 0;
    }

    // Execute program otherwise

    try {
        Program::ProgramController controller;

        if (variables.count(debugOption))
            controller.setDebugLevel(debugValue);

        if (!inputValue.empty())
            controller.setInputStream(inputValue);
        else
            controller.setDefaultInputStream();

        if (!outputValue.empty())
            controller.setOutputStream(outputValue);
        else
            controller.setDefaultOutputStream();

        if (!errorValue.empty())
            controller.setErrorStream(errorValue);
        else
            controller.setDefaultErrorStream();

        return controller.run();
    } catch (const std::exception& exception) {
        // last resort error handling
        std::cerr << exception.what() << std::endl;
        return -1;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
