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
