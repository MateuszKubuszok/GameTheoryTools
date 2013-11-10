#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class Root {

bool Root::debugMode = false;

unsigned long Root::allocations = 0;

unsigned long Root::deallocations = 0;

OutputStream* Root::outputStream = &std::cout;

// public:

bool Root::getDebugMode() {
    return debugMode;
}

void Root::setDebugMode(
    bool newDebugMode
) {
    debugMode = newDebugMode;
}

void Root::setOutputStream(
    OutputStream& newOutputStream
) {
    outputStream = &newOutputStream;
}

unsigned long Root::notFreed() {
    return (allocations - deallocations);
}

Root::Root() :
    rootID(++allocations)
{
    if (debugMode)
        *outputStream << "Allocated id:" << rootID << std::endl;
}

Root::~Root() {
    --deallocations;
    if (debugMode)
        *outputStream << "Freed id:" << rootID << std::endl;
}

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
