/**
 * @file      gt/model/result_factory.cpp
 * @brief     Defines GT::Model::ResultFactory methods.
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

using boost::make_shared;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ResultFactory {
// public:

ResultFactory& ResultFactory::getInstance() {
    static ResultFactory instance;
    return instance;
}

ResultBuilderPtr ResultFactory::buildResult() const {
    Message indent;
    switch (indentationMode) {
    case ResultIndentationMode::TABS:
        indent = Message("\t");
        break;
    case ResultIndentationMode::SPACES:
        indent = Message(" ");
    case ResultIndentationMode::NONE:
    default:
        break;
    }

    switch (builderMode) {
    case ResultBuilderMode::JSON:
        return make_shared<JSONResultBuilder>(indent);
    case ResultBuilderMode::XML:
        return make_shared<XMLResultBuilder>(indent);
    case ResultBuilderMode::PLAIN:
    default:
        return make_shared<PlainResultBuilder>(indent);
    }
}

ResultPtr ResultFactory::constResult(
    const Message& content
) const {
    return make_shared<ConstResult>(content);
}

ResultPtr ResultFactory::emptyResult() const {
    return make_shared<EmptyResult>();
}

ResultBuilderMode ResultFactory::getBuilderMode() const {
    return builderMode;
}

ResultFactory& ResultFactory::setBuilderMode(
    const ResultBuilderMode newBuilderMode
) {
    builderMode = newBuilderMode;
    return *this;
}

ResultIndentationMode ResultFactory::getIndentationMode() const {
    return indentationMode;
}

ResultFactory& ResultFactory::setIndentationMode(
    const ResultIndentationMode newIndentationMode
) {
    indentationMode = newIndentationMode;
    return *this;
}

// private:

ResultFactory::ResultFactory() {
    builderMode     = ResultBuilderMode::PLAIN;
    indentationMode = ResultIndentationMode::TABS;
}

// }; /* END class ResultFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
