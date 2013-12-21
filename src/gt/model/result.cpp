/**
 * @file      gt/model/result.cpp
 * @brief     Defines GT::Model::Result methods.
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

// class Result : public virtual Root {
// public:

Result::~Result() {}

bool Result::isEqual(
    const Root& root
) const {
    const Result* result = dynamic_cast<const Result*>(&root);
    if (!result)
        return false;
    if (result == this)
        return true;
    return getResult() == result->getResult();
}

Message Result::toString() const {
    return getResult();
}

// }; /* END class Result */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool operator==(
    const ResultPtr& result1,
    const ResultPtr& result2
) {
    return (*result1) == (*result2);
}

bool operator!=(
    const ResultPtr& result1,
    const ResultPtr& result2
) {
    return (*result1) != (*result2);
}

OutputStream& operator<<(
    OutputStream&    stream,
    const ResultPtr& result
) {
    return stream << result->toString();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
