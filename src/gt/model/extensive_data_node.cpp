#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

//class ExtensiveDataNode {
// public:

ExtensiveDataNode::ExtensiveDataNode() :
    player(NullFactory::getInstance().createPlayer()),
    payoff(new Numbers()),
    nodes(new ExtensiveDataNodes()),
    depthValue(1),
    depthName(createIdentifier(1))
    {}

ExtensiveDataNode::ExtensiveDataNode(
    unsigned int currentDepth
) :
    player(NullFactory::getInstance().createPlayer()),
    payoff(new Numbers()),
    nodes(new ExtensiveDataNodes()),
    depthValue(currentDepth),
    depthName(createIdentifier(currentDepth))
    {}

ExtensiveDataNode::ExtensiveDataNode(
    NumbersPtr values
) :
    player(NullFactory::getInstance().createPlayer()),
    payoff(values),
    nodes(new ExtensiveDataNodes()),
    depthValue(0),
    depthName("")
    {}

PlayerPtr ExtensiveDataNode::getPlayer() {
    return player;
}

PlayerPtr ExtensiveDataNode::getPlayer(
    Positions& positions
) {
    if (isPositionOfCurrentNodePlayer(positions))
        return player;

    if (!checkPlayerPositions(positions))
        throw ExceptionFactory::getInstance().invalidCoordinateFormat(positions);

    Identifier& strategy = positions[depthName];

    if (nodes->count(strategy))
        return (*nodes)[strategy]->getPlayer(positions);
    return NullFactory::getInstance().createPlayer();
}

ExtensiveDataNode& ExtensiveDataNode::setPlayer(
    PlayerPtr newPlayer
) {
    player = newPlayer;
    return *this;
}

ExtensiveDataNode& ExtensiveDataNode::setPlayer(
    Positions& positions,
    PlayerPtr  newPlayer
) {
    if (isPositionOfCurrentNodePlayer(positions)) {
        if (player->isNotNull() && player != newPlayer)
            throw ExceptionFactory::getInstance().coordinatesAlreadySet(positions);
        setPlayer(newPlayer);
    }

    else if (!checkPlayerPositions(positions))
        throw ExceptionFactory::getInstance().invalidCoordinateFormat(positions);

    else {
        Identifier& strategy = positions[depthName];

        if (!nodes->count(strategy)) {
            ExtensiveDataNodePtr node(new ExtensiveDataNode(depthValue+1));
            nodes->insert( ExtensiveDataNodes::value_type(strategy, node) );
        }

        (*nodes)[strategy]->setPlayer(positions, newPlayer);
    }

    return *this;
}

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
    else {
        IdentifierPtr playerName  = createIdentifierPtr("Player");
        MessagePtr    playerValue = createMessagePtr(player->toString());
        resultBuilder->addResult(playerName, playerValue);

        for (ExtensiveDataNodes::value_type& node : (*nodes)) {
            IdentifierPtr nodeName = createIdentifierPtr(node.first);
            MessagePtr    result   = createMessagePtr(node.second->toString());
            resultBuilder->addResult(nodeName, result);
        }
    }

    return resultBuilder->build()->getResult();
}

// private:

bool ExtensiveDataNode::isPositionOfCurrentNodePlayer(
    Positions& positions
) {
    return depthValue == positions.size()+1;
}

bool ExtensiveDataNode::checkPositions(
    Positions& positions
) {
    return positions.count(depthName) && nodes->count(positions[depthName]);
}

bool ExtensiveDataNode::checkPlayerPositions(
    Positions& positions
) {
    return positions.empty() || positions.count(depthName);
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
