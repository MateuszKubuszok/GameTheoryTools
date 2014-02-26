/**
 * @file      gt/model/root.cpp
 * @brief     Defines GT::Model::Root methods.
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

// class Root {
// public:

bool Root::isEqual(
    const Root& root
) const {
    return this == &root;
}

bool Root::isNotNull() const {
    return true;
}

bool Root::isNull() const {
    return !isNotNull();
}

// }; /* END class Root */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool operator==(
    const Root& root1,
    const Root& root2
) {
    return root1.isEqual(root2);
}

bool operator!=(
    const Root& root1,
    const Root& root2
) {
    return !root1.isEqual(root2);
}

OutputStream& operator<<(
    OutputStream& stream,
    const Root&   root
) {
    return stream << root.toString();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
