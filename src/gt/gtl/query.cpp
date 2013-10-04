#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class Query {
// public:

ResultPtr Query::execute(
    Context& context
) {
    return Model::NullFactory::getInstance().createResult();
}

Message Query::getResult() {
    return Message("NullResult");
}

Message Query::toString() {
    return Message("NullResult");
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
