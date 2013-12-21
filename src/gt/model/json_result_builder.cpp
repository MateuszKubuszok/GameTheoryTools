/**
 * @file      gt/model/json_result_builder.cpp
 * @brief     Defines GT::Model::JSONResultBuilder methods.
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

// class JSONResultBuilder final : public AbstractResultBuilder {
// public:

JSONResultBuilder::JSONResultBuilder(
    const Message indentation
) :
    AbstractResultBuilder(indentation)
    {}

ResultPtr JSONResultBuilder::build() const {
    stringstream result;

    result << '{' << endl;
    result << addIndent( buildRaw()->getResult() );
    result << '}' << endl;

    return ResultFactory::getInstance().constResult(Message(result.str()));
}

ResultPtr JSONResultBuilder::buildRaw() const {
    checkPropertyToResultMatching();

    Index propertiesSize = propertiesNames->size();
    stringstream result;

    if (propertiesSize > 0) {
        bool firstPartial = true;
        for (const PartialResult& partialResult : partialResults) {
            if (!firstPartial)
                result << ',' << endl;

            Identifier recordName = *partialResult.first;
            Messages   properties = *partialResult.second;

            result << '"' << recordName << '"' << " : [";
            bool firstProperty = true;
            for (Index property = 0; property < propertiesSize; property++) {
                if (firstProperty)
                    result << endl;
                else
                    result << ',' << endl;

                Identifier propertyName  = *(*propertiesNames)[property];
                Message    propertyValue = *(*partialResult.second)[property];

                result << indent
                       << '"' << propertyName << '"'
                       << " : "
                       << '"' << propertyValue << '"';

                firstProperty = false;
            }
            result << endl << ']';

            firstPartial = false;
        }

        if (!subResults.empty())
            result << ',';
    }

    if (!subResults.empty()) {
        bool firstSubResult = true;
        for (const SubResult& subResult : subResults) {
            if (firstSubResult)
                result << endl;
            else
                result << ',' << endl;

            Identifier resultName  = *subResult.first;
            Message    resultValue = *subResult.second;

            result << '"' << resultName << '"' << " : " << resultValue;

            firstSubResult = false;
        }
        result << endl;
    }

    return ResultFactory::getInstance().constResult(Message(result.str()));
}

// }; /* END class JSONResultBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
