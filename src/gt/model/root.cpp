#include "gt/model/common.hpp"

namespace GT {
namespace Model {
    
////////////////////////////////////////////////////////////////////////////////

// class Root {

static bool Root::debugMode = false;

static unsigned int Root::allocations = 0;

static OutputStream& outputStream = std::cout;

// public:

static bool getDebugMode() {
    return debugMode;
}

static void setDebugMode(
    bool newDebugMode
) {
    debugMode = newDebugMode;
}

static void setOutputStream(
    OutputStream& newOutputStream
) {
    outputStream = newOutputStream;
}

Root::Root() :
    rootID(++allocations)
{
    if (debugMode)
        outputStream << "Allocated id:" << rootID << std::endl;
}

Root::~Root() {
    if (debugMode)
        outputStream << "Freed id:" << rootID << std::endl;
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
    return stream << root.toStream();
}

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
