#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ObjectKnownProperties : public ObjectProperty {
// public:

ObjectKnownProperties::ObjectKnownProperties(
    const Object* describedObject
) :
    object(describedObject)
    {}

ResultPtr ObjectKnownProperties::findForConditions(
    const Context&,
    const Conditions&
) const {
    static const IdentifierPtr knownProperties = createIdentifierPtr("Known Properties");
    static const IdentifierPtr property        = createIdentifierPtr("Property");

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

// }; /* END class ObjectKnownProperties */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
