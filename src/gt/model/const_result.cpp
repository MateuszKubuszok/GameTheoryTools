#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class ConstResult {
// public:

ConstResult::ConstResult(
    const Message& content
) :
    result(content)
    {}

Message ConstResult::getResult() {
    return result;
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
