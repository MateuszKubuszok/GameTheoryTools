#include "gt/program/inner_common.hpp"

namespace std {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

GT::OutputStream& operator<<(
    GT::OutputStream&                  outputStream,
    const GT::Model::ResultBuilderMode resultBuilderMode
) {
    switch(resultBuilderMode) {
        default:
        case GT::Model::ResultBuilderMode::PLAIN:
            outputStream << "PLAIN";
            break;
        case GT::Model::ResultBuilderMode::JSON:
            outputStream << "JSON";
            break;
        case GT::Model::ResultBuilderMode::XML:
            outputStream << "XML";
            break;
    }

    return outputStream;
}

GT::InputStream& operator>>(
    GT::InputStream&              inputStream,
    GT::Model::ResultBuilderMode& resultBuilderMode
) {
    std::string plain = "PLAIN";
    std::string json  = "JSON";
    std::string xml   = "XML";

    std::string token;
    inputStream >> token;

    if (boost::iequals(token, plain))
        resultBuilderMode = GT::Model::ResultBuilderMode::PLAIN;
    else if (boost::iequals(token, json))
        resultBuilderMode = GT::Model::ResultBuilderMode::JSON;
    else if (boost::iequals(token, xml))
        resultBuilderMode = GT::Model::ResultBuilderMode::XML;
    else
        throw boost::program_options::validation_error(
            boost::program_options::validation_error::invalid_option_value,
            "Result Mode",
            token
        );

    return inputStream;
}

GT::OutputStream& operator<<(
    GT::OutputStream&                      outputStream,
    const GT::Model::ResultIndentationMode resultIndentationMode
) {
    switch(resultIndentationMode) {
        default:
        case GT::Model::ResultIndentationMode::TABS:
            outputStream << "TABS";
            break;
        case GT::Model::ResultIndentationMode::SPACES:
            outputStream << "SPACES";
            break;
        case GT::Model::ResultIndentationMode::NONE:
            outputStream << "NONE";
            break;
    }

    return outputStream;
}

GT::InputStream& operator>>(
    GT::InputStream&                  inputStream,
    GT::Model::ResultIndentationMode& resultIndentationMode
) {
    std::string tabs   = "TABS";
    std::string spaces = "SPACES";
    std::string none   = "NONE";

    std::string token;
    inputStream >> token;

    if (boost::iequals(token, tabs))
        resultIndentationMode = GT::Model::ResultIndentationMode::TABS;
    else if (boost::iequals(token, spaces))
        resultIndentationMode = GT::Model::ResultIndentationMode::SPACES;
    else if (boost::iequals(token, none))
        resultIndentationMode = GT::Model::ResultIndentationMode::NONE;
    else
        throw boost::program_options::validation_error(
            boost::program_options::validation_error::invalid_option_value,
            "Result Indentation",
            token
        );

    return inputStream;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace std */
