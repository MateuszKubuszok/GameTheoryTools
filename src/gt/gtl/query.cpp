#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class Query : public virtual ValidableSymbol {
// public:

Query::Query(
    const IdentifiersPtr definedPropertiesNames,
    const ObjectsPtr     definedObjects,
    const ConditionsPtr  definedConditions
) :
    propertiesNames(definedPropertiesNames),
    objects(definedObjects),
    conditions(definedConditions)
    {}

ResultPtr Query::execute(
    const Context& context
) const {
    static const MessagePtr objectPropertyNotFound =
        createMessagePtr("Property not found in Object");
    static const MessagePtr paramPropertyNotFound  =
        createMessagePtr("Property not found in Param nor referred Object");

    ResultBuilderPtr queryResult = ResultFactory::getInstance().buildResult();

    for (const IdentifierPtr& propertyPtr : *propertiesNames) {
        Identifier& property = *propertyPtr;
        ResultBuilderPtr propertyResult = ResultFactory::getInstance().buildResult();

        Index objectNumber = 0;
        for (ObjectPtr& objectPtr : *objects) {
            const Object&       object     = *objectPtr;
            const IdentifierPtr objectName = createIdentifierPtr(++objectNumber);

            if (object.respondsTo(property)) {
                // Object has this property

                try {
                    MessagePtr propertyValue = createMessagePtr(
                        object.findPropertyWithConditions(context, property, *conditions)->getResult()
                    );
                    propertyResult->addResult(objectName, propertyValue);
                } catch (const std::exception& e) {
                    MessagePtr errorMessage = createMessagePtr(e.what());
                    propertyResult->addResult(objectName, errorMessage);
                }
            } else {
                const Param& param = object;
                if (param) {
                    // Object is a Param - property might belong to referred Object

                    try {
                        const ObjectPtr referredObject = param.getObject(context);
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

Message Query::toString() const {
    static const IdentifierPtr  propertiesName = createIdentifierPtr("Properties");
    static const Identifiers    properties     = boost::assign::list_of( propertiesName );
    static const IdentifiersPtr propertiesPtr(new Identifiers(properties));

    static const IdentifierPtr  name = createIdentifierPtr("Property Name");

    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();
    resultBuilder->setHeaders(propertiesPtr);

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
