#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class ObjectKnownProperties {
// public:

ObjectKnownProperties::ObjectKnownProperties(
    Object* describedObject
) :
    object(describedObject)
    {}

ResultPtr ObjectKnownProperties::findForConditions(
    const Context&    context,
    const Conditions& conditions
) {
    IdentifierPtr knownProperties  = createIdentifierPtr("Known Properties");
    IdentifierPtr property         = createIdentifierPtr("Property");

    IdentifiersPtr records = createIdentifiersPtr();
    records->push_back(knownProperties);

    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();
    resultBuilder->setHeaders(records);
    
    IdentifiersPtr propertiesList = object->listProperties();
    for (IdentifierPtr& propertyName : *propertiesList) {
        MessagesPtr content = createMessagesPtr();
        content->push_back( createMessagePtr(propertyName) );
        resultBuilder->addRecord(property, content);
    }

    return resultBuilder->build();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
