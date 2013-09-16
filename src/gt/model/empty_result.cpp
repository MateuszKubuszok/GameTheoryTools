#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class EmptyResult {
// public:

EmptyResult::EmptyResult() {}

Message EmptyResult::getResult() {
    return Message("");
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
