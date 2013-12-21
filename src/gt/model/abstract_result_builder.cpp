/**
 * @file      gt/model/abstract_result_builder.cpp
 * @brief     Defines GT::Model::AbstractResultBuilder methods.
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

#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using std::endl;
using std::stringstream;
using std::vector;

using boost::is_any_of;
using boost::split;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class AbstractResultBuilder : public ResultBuilder {
// public:

AbstractResultBuilder::AbstractResultBuilder(
    const Message indentation
) :
    propertiesNames(new Identifiers()),
    partialResults(),
    subResults(),
    indent(indentation)
    {}

ResultBuilder& AbstractResultBuilder::setHeaders(
    const IdentifiersPtr& newPropertiesNames
) {
    propertiesNames = newPropertiesNames;
    return *this;
}

ResultBuilder& AbstractResultBuilder::addRecord(
    const IdentifierPtr& name,
    const MessagesPtr&   propertiesValues
) {
    partialResults.push_back( PartialResults::value_type(name, propertiesValues) );
    return *this;
}

ResultBuilder& AbstractResultBuilder::addResult(
    const IdentifierPtr& name,
    const MessagePtr&    result
) {
    subResults.push_back( SubResults::value_type(name, result) );
    return *this;
}

Message AbstractResultBuilder::toString() const {
    try {
        return build()->getResult();
    } catch (const IllegalInnerState& e) {
        return Message(e.what());
    }
}

// protected:

void AbstractResultBuilder::checkPropertyToResultMatching() const {
    Index propertiesSize = propertiesNames->size();
    for (const PartialResult& partialResult : partialResults) {
        MessagesPtr checkedProperties = partialResult.second;
        if (checkedProperties->size() != propertiesSize)
            throw ExceptionFactory::getInstance().propertiesAndResultsDontMatchInSize(
                propertiesSize,
                checkedProperties->size()
            );
    }
}

Message AbstractResultBuilder::addIndent(
    const Message content
) const {
    // do not use boost::container::vector here - it causes memory access violation with split function
    vector<Message> lines;
    split(lines, content, is_any_of("\n"));

    stringstream result;
    for (Message& line : lines)
        if (!line.empty() && line != "\n")
            result << indent << line << endl;

    return result.str();
}

// }; /* END class AbstractResultBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
