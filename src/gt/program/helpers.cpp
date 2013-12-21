/**
 * @file      gt/program/helpers.cpp
 * @brief     Defines GT::Program helpers.
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

namespace std {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using std::string;

using boost::iequals;
using boost::program_options::validation_error;

using GT::InputStream;
using GT::OutputStream;

using GT::Model::ResultBuilderMode;
using GT::Model::ResultIndentationMode;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

OutputStream& operator<<(
    OutputStream&           outputStream,
    const ResultBuilderMode resultBuilderMode
) {
    switch(resultBuilderMode) {
        default:
        case ResultBuilderMode::PLAIN:
            outputStream << "PLAIN";
            break;
        case ResultBuilderMode::JSON:
            outputStream << "JSON";
            break;
        case ResultBuilderMode::XML:
            outputStream << "XML";
            break;
    }

    return outputStream;
}

InputStream& operator>>(
    InputStream&       inputStream,
    ResultBuilderMode& resultBuilderMode
) {
    string plain = "PLAIN";
    string json  = "JSON";
    string xml   = "XML";

    string token;
    inputStream >> token;

    if (iequals(token, plain))
        resultBuilderMode = ResultBuilderMode::PLAIN;
    else if (iequals(token, json))
        resultBuilderMode = ResultBuilderMode::JSON;
    else if (iequals(token, xml))
        resultBuilderMode = ResultBuilderMode::XML;
    else
        throw validation_error(
            validation_error::invalid_option_value,
            "Result Mode",
            token
        );

    return inputStream;
}

OutputStream& operator<<(
    OutputStream&               outputStream,
    const ResultIndentationMode resultIndentationMode
) {
    switch(resultIndentationMode) {
        default:
        case ResultIndentationMode::TABS:
            outputStream << "TABS";
            break;
        case ResultIndentationMode::SPACES:
            outputStream << "SPACES";
            break;
        case ResultIndentationMode::NONE:
            outputStream << "NONE";
            break;
    }

    return outputStream;
}

InputStream& operator>>(
    InputStream&           inputStream,
    ResultIndentationMode& resultIndentationMode
) {
    string tabs   = "TABS";
    string spaces = "SPACES";
    string none   = "NONE";

    string token;
    inputStream >> token;

    if (iequals(token, tabs))
        resultIndentationMode = ResultIndentationMode::TABS;
    else if (iequals(token, spaces))
        resultIndentationMode = ResultIndentationMode::SPACES;
    else if (iequals(token, none))
        resultIndentationMode = ResultIndentationMode::NONE;
    else
        throw validation_error(
            validation_error::invalid_option_value,
            "Result Indentation",
            token
        );

    return inputStream;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace std */
