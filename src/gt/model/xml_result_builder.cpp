/**
 * @file      gt/model/xml_result_builder.cpp
 * @brief     Defines GT::Model::XMLResultBuilder methods.
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class XMLResultBuilder final : public AbstractResultBuilder {
// public:

XMLResultBuilder::XMLResultBuilder(
    Message indentation
) :
    AbstractResultBuilder(indentation)
    {}

ResultPtr XMLResultBuilder::build() const {
    return buildRaw();
}

ResultPtr XMLResultBuilder::buildRaw() const {
    checkPropertyToResultMatching();

    int propertiesSize = propertiesNames->size();
    stringstream result;

    if (propertiesSize > 0)
        for (const PartialResult& partialResult : partialResults) {
            Identifier recordName = *partialResult.first;
            Messages   properties = *partialResult.second;

            result << '<' << recordName << '>' << endl;
            for (int property = 0; property < propertiesSize; property++) {
                Identifier propertyName  = *(*propertiesNames)[property];
                Message    propertyValue = *(*partialResult.second)[property];

                result << indent
                        << "<result"
                        << ' '
                        << "property=\"" << propertyName << '"'
                        << ' '
                        << "value=\"" << propertyValue << '"'
                        << " />" << endl;
            }
            result << '<' << '/' << recordName << '>' << endl;
        }

    if (subResults.size() > 0)
        for (const SubResult& subResult : subResults) {
            Identifier resultName  = *subResult.first;
            Message    resultValue = *subResult.second;

            result << '<' << resultName << '>' << endl
                   << addIndent( resultValue )
                   << '<' << '/' << resultName << '>'
                   << endl;
        }

    return ResultFactory::getInstance().constResult(Message(result.str()));
}

// }; /* END class XMLResultBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
