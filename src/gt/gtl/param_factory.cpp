#include <boost/thread/mutex.hpp>

#include "gt/gtl/common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

boost::mutex paramFactoryMutex;

////////////////////////////////////////////////////////////////////////////////

class IdentifierParam : public virtual Param {
    Identifier identifier;

public:
    IdentifierParam(
        Identifier& id
    ) :
        identifier(id)
        {}

    virtual ObjectPtr getObject(
        Context& context
    ) {
        return (*context.getParam(identifier)).getObject(context);
    }

    virtual NumberPtr getValue(
        Context& context
    ) {
        return (*context.getParam(identifier)).getValue(context);
    }

    virtual Message toString() {
        return Message("Param:Identifier=") + identifier;
    }
}; /* END class IdentifierParam */

////////////////////////////////////////////////////////////////////////////////

class ValueParam : public virtual Param {
    NumberPtr value;

public:
    ValueParam(
        NumberPtr number
    ) :
        value(number)
        {}

    virtual ObjectPtr getObject(
        Context& context
    ) {
        throw std::invalid_argument("Cannot obatin object for value param");
    }

    virtual NumberPtr getValue(
        Context& context
    ) {
        return value;
    }

    virtual Message toString() {
        return Message("Param:Value=") + (*value).get_str(10);
    }
}; /* END class ValueParam */

////////////////////////////////////////////////////////////////////////////////

// class ParamFactory {
ParamFactory* volatile ParamFactory::instance = 0;

// public:
ParamFactory& ParamFactory::getInstance() {
    // Singleton implemented according to:
    // "C++ and the Perils of Double-Checked Locking"
    // but without executing constructor inside getInstance() method
    // since it's an eyesore. 
    if (!instance) {
        boost::mutex::scoped_lock lock(paramFactoryMutex);
        if (!instance) {
            ParamFactory* volatile tmp = new ParamFactory();
            instance = tmp;
        }
    }
    return *instance;
}

ParamFactory::ParamFactory() {}

ParamPtr ParamFactory::createParam(
    Identifier& identifier
) {
    return ParamPtr(new IdentifierParam(identifier));
}

ParamPtr ParamFactory::createParam(
    Number& number
) {
    NumberPtr value(new Number(number));
    return ParamPtr(new ValueParam(value));
}
// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
