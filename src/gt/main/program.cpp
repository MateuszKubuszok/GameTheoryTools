#include "gt/program/inner_common.hpp"

namespace Options = boost::program_options;
namespace Program = GT::Program;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(
    int   argumentsNumber,
    char* arguments[]
) {
    // Options declaration section

    char helpOption[]         = "help";
    char helpDescription[]    = "produce this message";

    int  debugValue           = 0;
    int  debugDefault         = 0;
    char debugOption[]        = "debug-level";
    char debugDescription[]   = "0 if no parser debugging, non 0 for debug allowed";

    std::string inputValue    = "";
    std::string inputDefault  = "";
    char inputOption[]        = "input-file,I";
    char inputDescription[]   = "input file to be parsed - if no one given reads from standard input";

    std::string outputValue   = "";
    std::string outputDefault = "";
    char outputOption[]       = "output-file,O";
    char outputDescription[]  = "output target - if no one given reads from standard output";

    std::string errorValue    = "";
    std::string errorDefault  = "";
    char errorOption[]        = "error-file,E";
    char errorDescription[]   = "error target - if no one given reads from standard error";

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
