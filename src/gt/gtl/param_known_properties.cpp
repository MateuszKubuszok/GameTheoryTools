#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ParamKnownProperties : public ObjectProperty {
// public:

ParamKnownProperties::ParamKnownProperties(
    const Param* describedParam
) :
    param(describedParam)
    {}

ResultPtr ParamKnownProperties::findForConditions(
    const Context&    context,
    const Conditions& conditions
) const {
    try {
        static const Identifier propertyName = createIdentifier("properties");
        return param->getObject(context)->findPropertyWithConditions(context, propertyName, conditions);
    } catch (const CyclicIdentifiers&) {
    } catch (const InvalidContentRequest&) {
    } catch (const NotDefinedParam&) {}

    static const IdentifierPtr knownProperties = createIdentifierPtr("Known Properties");
    static const MessagePtr    message         = createMessagePtr("Param does not refer to an Object");
    return ResultFactory::getInstance().buildResult()->addResult(knownProperties, message).build();
}

// }; /* END class ParamKnownProperties */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
