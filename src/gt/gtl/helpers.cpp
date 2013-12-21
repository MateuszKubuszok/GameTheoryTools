/**
 * @file      gt/gtl/helpers.cpp
 * @brief     Defines GT::GTL helpers.
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

#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using std::endl;
using std::stringstream;
using std::vector;

using boost::is_any_of;
using boost::split;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

Message suberrorMessage(
    const Message&         parentMessage,
    const ValidableSymbol& invalidSymbol
) {
    stringstream result;
    result << parentMessage << ":" << endl;

    Message content = invalidSymbol.toString();
    vector<Message> lines;
    split(lines, content, is_any_of("\n"));

    for (Message& line : lines)
        if (!line.empty() && line != "\n")
            result << '\t' << line << endl;
    result <<  '\t' << "at line " << invalidSymbol.getInputLocation() << endl;

    return result.str();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
