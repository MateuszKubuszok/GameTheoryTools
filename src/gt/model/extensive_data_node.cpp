#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

//class ExtensiveDataNode {
// public:

ExtensiveDataNode::ExtensiveDataNode() :
    payoff(new Numbers()),
    nodes(new ExtensiveDataNodes()),
    depthValue(1),
    depthName(createIdentifier(1))
    {}

ExtensiveDataNode::ExtensiveDataNode(
    unsigned int currentDepth
) :
    payoff(new Numbers()),
    nodes(new ExtensiveDataNodes()),
    depthValue(currentDepth),
    depthName(createIdentifier(currentDepth))
    {}

ExtensiveDataNode::ExtensiveDataNode(
    NumbersPtr values
) :
    payoff(values),
    nodes(new ExtensiveDataNodes()),
    depthValue(0),
    depthName("")
    {}

NumbersPtr ExtensiveDataNode::getValues(
    Positions& positions
) {
    if (depthValue == 0)
        return payoff;

    if (!checkPositions(positions))
        throw ExceptionFactory::getInstance().invalidCoordinateFormat(positions);

    Identifier& strategy = positions[depthName];
    return (*nodes)[strategy]->getValues(positions);
}

ExtensiveDataNode& ExtensiveDataNode::setValues(
    Positions& positions,
    NumbersPtr values
) {
    if (!positions.count(depthName))
        throw ExceptionFactory::getInstance().invalidCoordinateFormat(positions);

    Identifier& strategy = positions[depthName];

    if (!nodes->count(strategy)) {
        ExtensiveDataNodePtr node;
        if (depthValue == positions.size())
            node = ExtensiveDataNodePtr(new ExtensiveDataNode(values));
        else {
            node = ExtensiveDataNodePtr(new ExtensiveDataNode(depthValue+1));
            node->setValues(positions, values);
        }
        nodes->insert( ExtensiveDataNodes::value_type(strategy, node) );
    } else if (depthValue != positions.size())
        (*nodes)[strategy]->setValues(positions, values);
    else
        throw ExceptionFactory::getInstance().coordinatesAlreadySet(positions);

    return *this;
}

Message ExtensiveDataNode::toString() {
    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();
    IdentifierPtr    valueName     = createIdentifierPtr("Value");

    if (depthValue == 0)
        for (NumberPtr& number : (*payoff)) {
            MessagePtr result = createMessagePtr(number);
            resultBuilder->addResult(valueName, result);
        }
    else
        for (ExtensiveDataNodes::value_type& node : (*nodes)) {
            IdentifierPtr nodeName = createIdentifierPtr(node.first);
            MessagePtr    result   = createMessagePtr(node.second->toString());
            resultBuilder->addResult(nodeName, result);
        }

    return resultBuilder->build()->getResult();
}

// private:

bool ExtensiveDataNode::checkPositions(
    Positions& positions
) {
    return positions.count(depthName) && nodes->count(positions[depthName]);
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
