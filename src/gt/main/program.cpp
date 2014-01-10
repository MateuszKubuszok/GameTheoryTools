/**
 * @file      gt/main/program.cpp
 * @brief     Defines main function for GTL program.
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

namespace Options = boost::program_options;
namespace Program = GT::Program;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using std::cout;
using std::cerr;
using std::endl;
using std::istringstream;
using std::string;
using std::vector;

using boost::any;

using Options::validators::check_first_occurrence;
using Options::validators::get_single_string;

using GT::Model::ResultBuilderMode;
using GT::Model::ResultIndentationMode;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Validator for boost::program_options to parse ResultBuilderMode.
 *
 * @param value  target value handler
 * @param values values all values that match validator
 */
void validate(
    any&                  value,
    const vector<string>& values,
    ResultBuilderMode*,
    int
) {
    // make sure no previous assignment to value was made
    check_first_occurrence(value);

    // Extract the first string from 'values'. If there is more than
    // one string, it's an error, and exception will be thrown.
    const string&     stringValue = get_single_string(values);
    istringstream     streamValue(stringValue);
    ResultBuilderMode parsedValue;
    streamValue >> parsedValue;

    value = any( parsedValue );
}

/**
 * @brief Validator for boost::program_options to parse ResultIndentationMode.
 *
 * @param value  target value handler
 * @param values values all values that match validator
 */
void validate(
    any&                  value,
    const vector<string>& values,
    ResultIndentationMode*,
    int
) {
    // make sure no previous assignment to value was made
    check_first_occurrence(value);

    // Extract the first string from 'values'. If there is more than
    // one string, it's an error, and exception will be thrown.
    const string&         stringValue = get_single_string(values);
    istringstream         streamValue(stringValue);
    ResultIndentationMode parsedValue;
    streamValue >> parsedValue;

    value = any( parsedValue );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Parses arguments and runs program accordingly.
 *
 * @param argumentsNumber number of arguments passed into program
 * @param arguments       actual arguments passed into program (arguments[0] being the executable's name)
 * @return                program exit code
 */
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

    string inputValue               = "";
    const string inputDefault       = "";
    const char inputOption[]        = "input-file,I";
    const char inputDescription[]   = "input file to be parsed - if no one given reads from standard input";

    string outputValue              = "";
    const string outputDefault      = "";
    const char outputOption[]       = "output-file,O";
    const char outputDescription[]  = "output target - if no one given reads from standard output";

    string errorValue               = "";
    const string errorDefault       = "";
    const char errorOption[]        = "error-file,E";
    const char errorDescription[]   = "error target - if no one given reads from standard error";

    ResultBuilderMode
               resultValue             = ResultBuilderMode::PLAIN;
    const ResultBuilderMode
               resultDefault           = ResultBuilderMode::PLAIN;
    const char resultOption[]          = "result,R";
    const char resultDescription[]     = "result type - PLAIN, JSON and XML allowed";

    ResultIndentationMode
               indentationValue            = ResultIndentationMode::TABS;
    const ResultIndentationMode
               indentationDefault          = ResultIndentationMode::TABS;
    const char indentationOption[]         = "indent,T";
    const char indentationDescription[]    = "indentation used - TABS, SPACES and NONE allowed";

    // Options setup

    Options::options_description description("Available options");
    description.add_options()
    (helpOption,                                                helpDescription)
    (debugOption,       Options::value<int>(
                            &debugValue
                        )->default_value(debugDefault),         debugDescription)
    (inputOption,       Options::value<string>(
                            &inputValue
                        )->default_value(inputDefault),         inputDescription)
    (outputOption,      Options::value<string>(
                            &outputValue
                        )->default_value(outputDefault),        outputDescription)
    (errorOption,      Options::value<string>(
                            &errorValue
                        )->default_value(errorDefault),         errorDescription)
    (resultOption,      Options::value<ResultBuilderMode>(
                            &resultValue
                        )->default_value(resultDefault),        resultDescription)
    (indentationOption, Options::value<ResultIndentationMode>(
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
            cout << description << endl;
            return EXIT_SUCCESS;
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
        cerr << "Uknown option, use one of listed instead." << endl;
        cout << endl << description << endl;
        return EXIT_FAILURE;
    } catch (const std::exception& exception) {
        // last resort error handling
        cerr << exception.what() << endl;
        return EXIT_FAILURE;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
