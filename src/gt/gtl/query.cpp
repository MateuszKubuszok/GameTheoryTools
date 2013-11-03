#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class Query : public virtual ValidableSymbol {
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
    MessagePtr objectPropertyNotFound = createMessagePtr("Property not found in Object");
    MessagePtr paramPropertyNotFound  = createMessagePtr("Property not found in Param nor referred Object");

    ResultBuilderPtr queryResult = ResultFactory::getInstance().buildResult();

    for (IdentifierPtr& propertyPtr : *propertiesNames) {
        Identifier& property = *propertyPtr;
        ResultBuilderPtr propertyResult = ResultFactory::getInstance().buildResult();

        Index objectNumber = 0;
        for (ObjectPtr& objectPtr : *objects) {
            Object&       object     = *objectPtr;
            IdentifierPtr objectName = createIdentifierPtr(++objectNumber);

            if (object.respondsTo(property)) {
                // Object has this property

                MessagePtr propertyValue = createMessagePtr(
                    object.findPropertyWithConditions(context, property, *conditions)->getResult()
                );
                propertyResult->addResult(objectName, propertyValue);
            } else {
                Param& param = object;
                if (param) {
                    // Object is a Param - property might belong to referred Object

                    try {
                        ObjectPtr referredObject = param.getObject(context);
                        if (referredObject->respondsTo(property)) {
                            // Param refers to Object (not a Number or cyclic reference or udefined Param)

                            MessagePtr propertyValue = createMessagePtr(
                                referredObject->findPropertyWithConditions(context, property, *conditions)
                                              ->getResult()
                            );
                            propertyResult->addResult(objectName, propertyValue);
                        } else {
                            // Referred Object has no sought property

                            propertyResult->addResult(objectName, paramPropertyNotFound);
                        }
                    } catch (const std::exception& e) {
                        MessagePtr errorMessage = createMessagePtr(e.what());
                        propertyResult->addResult(objectName, errorMessage);
                    }
                } else {
                    // Object has no sought property whatsoever

                    propertyResult->addResult(objectName, objectPropertyNotFound);
                }
            }
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

// }; /* END class Query */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
