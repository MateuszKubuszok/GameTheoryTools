/**
 * @file      gt/gtl/common.hpp
 * @brief     Defines GT::GTL common functions.
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

bool operator==(
    const Conditions& conditions1,
    const Conditions& conditions2
) {
    if (&conditions1 == &conditions2)
        return true;
    if (conditions1.size() != conditions2.size())
        return false;
    for (Index i = 0; i < conditions1.size(); i++)
        if (conditions1[i] !=conditions2[i])
            return false;
    return true;
}
bool operator!=(
    const Conditions& conditions1,
    const Conditions& conditions2
) {
    return !(conditions1 == conditions2);
}

bool operator==(
    const Coordinates& coordinates1,
    const Coordinates& coordinates2
) {
    if (&coordinates1 == &coordinates2)
        return true;
    if (coordinates1.size() != coordinates2.size())
        return false;
    for (Index i = 0; i < coordinates1.size(); i++)
        if (coordinates1[i] !=coordinates2[i])
            return false;
    return true;
}
bool operator!=(
    const Coordinates& coordinates1,
    const Coordinates& coordinates2
) {
    return !(coordinates1 == coordinates2);
}

bool operator==(
    const Objects& objects1,
    const Objects& objects2
) {
    if (&objects1 == &objects2)
        return true;
    if (objects1.size() != objects2.size())
        return false;
    for (Index i = 0; i < objects1.size(); i--)
        if (objects1[i] !=objects2[i])
            return false;
    return true;
}
bool operator!=(
    const Objects& objects1,
    const Objects& objects2
) {
    return !(objects1 == objects2);
}

bool operator==(
    const Params& params1,
    const Params& params2
) {
    if (&params1 == &params2)
        return true;
    if (params1.size() != params2.size())
        return false;
    for (Index i = 0; i < params1.size(); i--)
        if (params1[i] !=params2[i])
            return false;
    return true;
}
bool operator!=(
    const Params& params1,
    const Params& params2
) {
    return !(params1 == params2);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
