#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class Query {
// public:

Query::Query(
    IdentifiersPtr definedPropertiesNames,
    ObjectsPtr     definedObjects,
    ConditionsPtr  definedConditions
) :
    propertiesNames(definedPropertiesNames),
    objects(definedObjects),
    conditions(definedConditions)
    {}

ResultPtr Query::execute(
    Context& context
) {
    MessagePtr propertyNotFound = createMessagePtr("Property not found");

    ResultBuilderPtr queryResult = ResultFactory::getInstance().buildResult();

    for (IdentifierPtr& propertyPtr : *propertiesNames) {
        Identifier& property = *propertyPtr;
        ResultBuilderPtr propertyResult = ResultFactory::getInstance().buildResult();

        Index objectNumber = 0;
        for (ObjectPtr& objectPtr : *objects) {
            Object&       object     = *objectPtr;
            IdentifierPtr objectName = createIdentifierPtr(++objectNumber);

            if (object.respondsTo(property)) {
                MessagePtr propertyValue = createMessagePtr( object.findPropertyWithConditions(context, property, *conditions)->getResult() );
                propertyResult->addResult(objectName, propertyValue);
            } else
                propertyResult->addResult(objectName, propertyNotFound);
        }

        MessagePtr identifierValue = createMessagePtr(propertyResult->build()->getResult());
        queryResult->addResult(propertyPtr, identifierValue);
    }

    return queryResult->build();
}

Message Query::toString() {
    IdentifiersPtr properties(new Identifiers());
    properties->push_back( createIdentifierPtr("Properties") );

    IdentifierPtr  name = createIdentifierPtr("Property Name");

    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();
    resultBuilder->setHeaders(properties);

    for (IdentifierPtr& value : *propertiesNames) {
        MessagesPtr results(new Messages());
        results->push_back( value );

        resultBuilder->addRecord(name, results);
    }

    return resultBuilder->build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
