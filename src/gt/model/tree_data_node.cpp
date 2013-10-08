#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

//class TreeDataNode {
// public:

TreeDataNode::TreeDataNode() :
    depthValue(1),
    depthName(createIdentifier(1)),
    payoff(new Numbers()),
    nodes(new TreeDataNodes())
    {}

TreeDataNode::TreeDataNode(
    unsigned int currentDepth
) :
    depthValue(currentDepth),
    depthName(createIdentifier(currentDepth)),
    payoff(new Numbers()),
    nodes(new TreeDataNodes())
    {}

TreeDataNode::TreeDataNode(
    NumbersPtr values
) :
    depthValue(0),
    depthName(""),
    payoff(values),
    nodes(new TreeDataNodes())
    {}

NumbersPtr TreeDataNode::getValues(
    Positions& positions
) {
    if (depthValue == 0)
        return payoff;

    if (!checkPositions(positions))
        throw ExceptionFactory::getInstance().invalidCoordinateFormat(positions);

    Identifier& strategy = positions[depthName];
    return (*nodes)[strategy]->getValues(positions);
}

TreeDataNode& TreeDataNode::setValues(
    Positions& positions,
    NumbersPtr values
) {
    if (!positions.count(depthName))
        throw ExceptionFactory::getInstance().invalidCoordinateFormat(positions);

    Identifier& strategy = positions[depthName];

    if (!nodes->count(strategy)) {
        TreeDataNodePtr node;
        if (depthValue == positions.size())
            node = TreeDataNodePtr(new TreeDataNode(values));
        else {
            node = TreeDataNodePtr(new TreeDataNode(depthValue+1));
            node->setValues(positions, values);
        }
        nodes->insert( TreeDataNodes::value_type(strategy, node) );
    } else if (depthValue != positions.size())
        (*nodes)[strategy]->setValues(positions, values);
    else
        throw ExceptionFactory::getInstance().coordinatesAlreadySet(positions);

    return *this;
}

Message TreeDataNode::toString() {
    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();
    IdentifierPtr    valueName     = createIdentifierPtr("Value");

    if (depthValue == 0)
        for (NumberPtr& number : (*payoff)) {
            MessagePtr result = createMessagePtr(number);
            resultBuilder->addResult(valueName, result);
        }
    else
        for (TreeDataNodes::value_type& node : (*nodes)) {
            IdentifierPtr nodeName = createIdentifierPtr(node.first);
            MessagePtr    result   = createMessagePtr(node.second->toString());
            resultBuilder->addResult(nodeName, result);
        }

    return resultBuilder->build()->getResult();
}

// private:

bool TreeDataNode::checkPositions(
    Positions& positions
) {
    return positions.count(depthName) && nodes->count(positions[depthName]);
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
