#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ConstResult : public Result {
// public:

ConstResult::ConstResult(
    const Message& content
) :
    result(content)
    {}

Message ConstResult::getResult() const {
    return result;
}

// }; /* END class ConstResult */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
