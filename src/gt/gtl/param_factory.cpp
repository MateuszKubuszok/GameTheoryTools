#include <boost/thread/mutex.hpp>

#include "gt/gtl/common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

boost::mutex paramFactoryMutex;

class ValueParam;
class IdentifierParam;

////////////////////////////////////////////////////////////////////////////////

// class ParamFactory {
// public:
static ParamFactory& ParamFactory::getInstance() {
    // Singleton implemented according to:
    // "C++ and the Perils of Double-Checked Locking"
    // but without executing constructor inside getInstance() method
    // since it's an eyesore. 
    if (!instance) {
        boost::mutex::scoped_lock lock;
        if (!instance) {
            ParamFactory* volatile tmp = new ParamFactory();
            instance = tmp;
        }
    }
    return *instance;
}

Param ParamFactory::createParam(
    Identifier& identifier
) {
    return IdentifierParam(identifier);
}

Param ParamFactory::createParam(
    Number& number
) {
    return ValueParam(identifier);
}
// }

////////////////////////////////////////////////////////////////////////////////

class IdentifierParam : Param {
public:
    IdentifierParam(
        Identifier& id
    ) :
        identifier(id)
        {}

    Number getValue(
        Context& context
    ) {
        return context.getParam(identifier).getValue(context);
    }
private:
    Identifier identifier;
} /* END class IdentifierParam */

////////////////////////////////////////////////////////////////////////////////

class ValueParam : Param {
public:
    ValueParam(
        Number& number
    ) :
        value(number)
        {}

    Number getValue(
        Context& context
    ) {
        return value;
    }
private:
    Number value;
} /* END class ValueParam */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
