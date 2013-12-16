#include "gt/program/inner_common.hpp"

namespace Options = boost::program_options;
namespace Program = GT::Program;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void validate(
    boost::any&                     value,
    const std::vector<std::string>& values,
    GT::Model::ResultBuilderMode*,
    int
) {
    // make sure no previous assignment to value was made
    Options::validators::check_first_occurrence(value);

    // Extract the first string from 'values'. If there is more than
    // one string, it's an error, and exception will be thrown.
    const std::string&           stringValue = Options::validators::get_single_string(values);
    std::istringstream           streamValue(stringValue);
    GT::Model::ResultBuilderMode parsedValue;
    streamValue >> parsedValue;

    value = boost::any( parsedValue );
}

void validate(
    boost::any&                     value,
    const std::vector<std::string>& values,
    GT::Model::ResultIndentationMode*,
    int
) {
    // make sure no previous assignment to value was made
    Options::validators::check_first_occurrence(value);

    // Extract the first string from 'values'. If there is more than
    // one string, it's an error, and exception will be thrown.
    const std::string&               stringValue = Options::validators::get_single_string(values);
    std::istringstream               streamValue(stringValue);
    GT::Model::ResultIndentationMode parsedValue;
    streamValue >> parsedValue;

    value = boost::any( parsedValue );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(
    const int   argumentsNumber,
    const char* arguments[]
) {
    // Options declaration section

    const char helpOption[]         = "help,H";
    const char helpDescription[]    = "produce this message";

    int  debugValue                 = 0;
    const int  debugDefault         = 0;
    const char debugOption[]        = "debug-level,D";
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

    GT::Model::ResultBuilderMode
               resultValue             = GT::Model::ResultBuilderMode::PLAIN;
    const GT::Model::ResultBuilderMode
               resultDefault           = GT::Model::ResultBuilderMode::PLAIN;
    const char resultOption[]          = "result,R";
    const char resultDescription[]     = "result type - PLAIN, JSON and XML allowed";

    GT::Model::ResultIndentationMode
               indentationValue            = GT::Model::ResultIndentationMode::TABS;
    const GT::Model::ResultIndentationMode
               indentationDefault          = GT::Model::ResultIndentationMode::TABS;
    const char indentationOption[]         = "indent,T";
    const char indentationDescription[]    = "indentation used - TABS, SPACES and NONE allowed";

    // Options setup

    Options::options_description description("Available options");
    description.add_options()
    (helpOption,                                                helpDescription)
    (debugOption,       Options::value<int>(
                            &debugValue
                        )->default_value(debugDefault),         debugDescription)
    (inputOption,       Options::value<std::string>(
                            &inputValue
                        )->default_value(inputDefault),         inputDescription)
    (outputOption,      Options::value<std::string>(
                            &outputValue
                        )->default_value(outputDefault),        outputDescription)
    (errorOption,      Options::value<std::string>(
                            &errorValue
                        )->default_value(errorDefault),         errorDescription)
    (resultOption,      Options::value<GT::Model::ResultBuilderMode>(
                            &resultValue
                        )->default_value(resultDefault),        resultDescription)
    (indentationOption, Options::value<GT::Model::ResultIndentationMode>(
                            &indentationValue
                        )->default_value(indentationDefault),   indentationDescription)
    ;

    try {
        // Parsing variables from arguments

        Options::variables_map variables;
        Options::store(
            Options::parse_command_line(argumentsNumber, arguments, description),
            variables
        );
        Options::notify(variables);

        // Display help if requested

        if (variables.count("help") || variables.count("H")) {
            std::cout << description << std::endl;
            return 0;
        }

        // Execute program otherwise

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

        return controller.setResultBuilderMode(resultValue)
                         .setResultIndentationMode(indentationValue)
                         .run();
    } catch (const boost::program_options::unknown_option& exception) {
        // uknown option error
        std::cerr << "Uknown option, use one of listed instead." << std::endl;
        std::cout << std::endl << description << std::endl;
        return -1;
    } catch (const std::exception& exception) {
        // last resort error handling
        std::cerr << exception.what() << std::endl;
        return -1;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
