#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {
    
////////////////////////////////////////////////////////////////////////////////

// class Result {
// public:

bool Result::isEqual(
    Root& root
) {
    Result* result = dynamic_cast<Result*>(&root);
    if (!result)
        return false;
    if (result == this)
        return true;
    return getResult() == result->getResult();
}

Message Result::toString() {
    return getResult();
}

// } 

////////////////////////////////////////////////////////////////////////////////

bool operator==(
    ResultPtr& result1,
    ResultPtr& result2
) {
    return (*result1) == (*result2);
}

bool operator!=(
    ResultPtr& result1,
    ResultPtr& result2
) {
    return (*result1) != (*result2);
}

OutputStream& operator<<(
    OutputStream& stream,
    ResultPtr&    result
) {
    return stream << result->toString();
}

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
