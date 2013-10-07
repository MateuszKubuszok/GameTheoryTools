#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

bool operator==(
    Conditions& conditions1,
    Conditions& conditions2
) {
    if (&conditions1 == &conditions2)
        return true;
    if (conditions1.size() != conditions2.size())
        return false;
    for (Index i = conditions1.size()-1; i >= 0; i--)
        if (conditions1[i] !=conditions2[i])
            return false;
    return true;
}
bool operator!=(
    Conditions& conditions1,
    Conditions& conditions2
) {
    return !(conditions1 == conditions2);
}

bool operator==(
    Coordinates& coordinates1,
    Coordinates& coordinates2
) {
    if (&coordinates1 == &coordinates2)
        return true;
    if (coordinates1.size() != coordinates2.size())
        return false;
    for (Index i = coordinates1.size()-1; i >= 0; i--)
        if (coordinates1[i] !=coordinates2[i])
            return false;
    return true;
}
bool operator!=(
    Coordinates& coordinates1,
    Coordinates& coordinates2
) {
    return !(coordinates1 == coordinates2);
}

bool operator==(
    Objects& objects1,
    Objects& objects2
) {
    if (&objects1 == &objects2)
        return true;
    if (objects1.size() != objects2.size())
        return false;
    for (Index i = objects1.size()-1; i >= 0; i--)
        if (objects1[i] !=objects2[i])
            return false;
    return true;
}
bool operator!=(
    Objects& objects1,
    Objects& objects2
) {
    return !(objects1 == objects2);
}

bool operator==(
    Params& params1,
    Params& params2
) {
    if (&params1 == &params2)
        return true;
    if (params1.size() != params2.size())
        return false;
    for (Index i = params1.size()-1; i >= 0; i--)
        if (params1[i] !=params2[i])
            return false;
    return true;
}
bool operator!=(
    Params& params1,
    Params& params2
) {
    return !(params1 == params2);
}

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
