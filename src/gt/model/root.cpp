#include "gt/model/common.hpp"

namespace GT {
namespace Model {
    
////////////////////////////////////////////////////////////////////////////////

// class Root {

bool Root::debugMode = false;

unsigned int Root::allocations = 0;

OutputStream* outputStream = &std::cout;

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

Root::Root() :
    rootID(++allocations)
{
    if (debugMode)
        *outputStream << "Allocated id:" << rootID << std::endl;
}

Root::~Root() {
    if (debugMode)
        *outputStream << "Freed id:" << rootID << std::endl;
}

bool Root::isNull() {
    return !isNotNull();
}

// }

////////////////////////////////////////////////////////////////////////////////

bool operator==(
    Root& root1,
    Root& root2
) {
    return root1.isEqual(root2);
}

bool operator!=(
    Root& root1,
    Root& root2
) {
    return !root1.isEqual(root2);
}

OutputStream& operator<<(
    OutputStream& stream,
    Root&         root
) {
    return stream << root.toString();
}

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
