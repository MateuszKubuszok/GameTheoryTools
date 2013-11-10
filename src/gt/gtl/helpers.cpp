#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

Message suberrorMessage(
    const Message&         parentMessage,
    const ValidableSymbol& invalidSymbol
) {
    std::stringstream result;
    result << parentMessage << ":" << std::endl;

    Message content = invalidSymbol.toString();
    std::vector<Message> lines;
    boost::split(lines, content, boost::is_any_of("\n"));

    for (Message& line : lines)
        if (!line.empty() && line != "\n")
            result << '\t' << line << std::endl;
    result <<  '\t' << "at line " << invalidSymbol.getInputLocation() << std::endl;

    return result.str();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
