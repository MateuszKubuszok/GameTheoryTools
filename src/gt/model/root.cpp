#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class Root {
// public:

Root::~Root() {}

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
