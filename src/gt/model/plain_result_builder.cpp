/**
 * @file      gt/model/plain_result_builder.cpp
 * @brief     Defines GT::Model::PlainResultBuilder methods.
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

// class PlainResultBuilder final : public AbstractResultBuilder {
// public:

PlainResultBuilder::PlainResultBuilder(
    const Message indentation
) :
    AbstractResultBuilder(indentation)
    {}

ResultPtr PlainResultBuilder::build() const {
    return buildRaw();
}

ResultPtr PlainResultBuilder::buildRaw() const {
    checkPropertyToResultMatching();

    stringstream result;

    if (!propertiesNames->empty()) {
        bool firstProperty = true;
        for (IdentifierPtr& propertyName : (*propertiesNames)) {
            if (firstProperty)
                result << indent;
            else
                result << ',';
            result << indent << (*propertyName);

            firstProperty = false;
        }
        result << endl;

        for (const PartialResult& partialResult : partialResults) {
            Identifier recordName = *partialResult.first;
            Messages   properties = *partialResult.second;

            result << recordName << ':' << endl;
            firstProperty = true;
            for (MessagePtr& propertyValue : properties) {
                if (firstProperty)
                    result << indent;
                else
                    result << ',';
                result << indent << (*propertyValue);

                firstProperty = false;
            }
            result << endl;
        }
    }

    if (!subResults.empty()) {
        for (const SubResult& subResult : subResults) {
            Identifier resultName  = *subResult.first;
            Message    resultValue = *subResult.second;

            result << resultName << ':' << endl << addIndent(resultValue);
        }
    }

    return ResultFactory::getInstance().constResult(Message(result.str()));
}

// }; /* END class PlainResultBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
