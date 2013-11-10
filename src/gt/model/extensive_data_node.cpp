#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//class ExtensiveDataNode : public virtual Root {
// public:

ExtensiveDataNode::ExtensiveDataNode() :
    parent(new NullExtensiveDataNode()),
    player(NullFactory::getInstance().createPlayer()),
    payoff(new Numbers()),
    nodes(new ExtensiveDataNodes()),
    depthValue(1),
    depthName(createIdentifier(1))
    {}

ExtensiveDataNode::~ExtensiveDataNode() {
    if (parent && parent->isNull()) {
        // 1) ExtensiveDataNode implementation has parent set to nullptr - need to null check first
        // 2) root's "Parent" is set to ExtensiveDataNode - it needs to be freed manually since no one owns it
        delete parent;
        parent = nullptr;
    }
}

const ExtensiveDataNode& ExtensiveDataNode::getParent() const {
    return *parent;
}

const PlayerPtr ExtensiveDataNode::getPlayer() const {
    return player;
}

const PlayerPtr ExtensiveDataNode::getPlayer(
    const Positions& positions
) const {
    if (isPositionOfCurrentNodePlayer(positions))
        return player;

    if (!checkPlayerPositions(positions))
        throw ExceptionFactory::getInstance().invalidCoordinateFormat(positions);

    const Identifier& strategy = positions.at(depthName);

    if (nodes->count(strategy))
        return (*nodes)[strategy]->getPlayer(positions);
    return NullFactory::getInstance().createPlayer();
}

ExtensiveDataNode& ExtensiveDataNode::setPlayer(
    const PlayerPtr newPlayer
) {
    player = newPlayer;
    return *this;
}

ExtensiveDataNode& ExtensiveDataNode::setPlayer(
    const Positions& positions,
    const PlayerPtr  newPlayer
) {
    if (isPositionOfCurrentNodePlayer(positions)) {
        if (player->isNotNull() && player != newPlayer)
            throw ExceptionFactory::getInstance().coordinatesAlreadySet(positions);
        setPlayer(newPlayer);
    }

    else if (!checkPlayerPositions(positions))
        throw ExceptionFactory::getInstance().invalidCoordinateFormat(positions);

    else {
        const Identifier& strategy = positions.at(depthName);

        if (!nodes->count(strategy)) {
            ExtensiveDataNodePtr node(new ExtensiveDataNode(this, depthValue+1));
            nodes->insert( ExtensiveDataNodes::value_type(strategy, node) );
        }

        (*nodes)[strategy]->setPlayer(positions, newPlayer);
    }

    return *this;
}

const NumbersPtr ExtensiveDataNode::getValues(
    const Positions& positions
) const {
    if (depthValue == 0)
        return payoff;

    if (!checkPositions(positions))
        throw ExceptionFactory::getInstance().invalidCoordinateFormat(positions);

    const Identifier& strategy = positions.at(depthName);
    return (*nodes)[strategy]->getValues(positions);
}

ExtensiveDataNode& ExtensiveDataNode::setValues(
    const Positions& positions,
    const NumbersPtr values
) {
    if (!positions.count(depthName))
        throw ExceptionFactory::getInstance().invalidCoordinateFormat(positions);

    const Identifier& strategy = positions.at(depthName);

    if (!nodes->count(strategy)) {
        ExtensiveDataNodePtr node;
        if (depthValue == positions.size())
            node = ExtensiveDataNodePtr(new ExtensiveDataNode(this, values));
        else {
            node = ExtensiveDataNodePtr(new ExtensiveDataNode(this, depthValue+1));
            node->setValues(positions, values);
        }
        nodes->insert( ExtensiveDataNodes::value_type(strategy, node) );
    } else if (depthValue != positions.size())
        (*nodes)[strategy]->setValues(positions, values);
    else
        throw ExceptionFactory::getInstance().coordinatesAlreadySet(positions);

    return *this;
}

Message ExtensiveDataNode::toString() const {
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

// protected:

ExtensiveDataNode::ExtensiveDataNode(
    ExtensiveDataNode* definedParent,
    Index              currentDepth
) :
    parent(definedParent),
    player(NullFactory::getInstance().createPlayer()),
    payoff(new Numbers()),
    nodes(new ExtensiveDataNodes()),
    depthValue(currentDepth),
    depthName(createIdentifier(currentDepth))
    {}

ExtensiveDataNode::ExtensiveDataNode(
    ExtensiveDataNode* definedParent,
    NumbersPtr         values
) :
    parent(definedParent),
    player(NullFactory::getInstance().createPlayer()),
    payoff(values),
    nodes(new ExtensiveDataNodes()),
    depthValue(0),
    depthName("")
    {}

// private:

bool ExtensiveDataNode::isPositionOfCurrentNodePlayer(
    const Positions& positions
) const {
    return depthValue == positions.size()+1;
}

bool ExtensiveDataNode::checkPositions(
    const Positions& positions
) const {
    return positions.count(depthName) && nodes->count(positions.at(depthName));
}

bool ExtensiveDataNode::checkPlayerPositions(
    const Positions& positions
) const {
    return positions.empty() || positions.count(depthName);
}

// }; /* END class ExtensiveDataNode */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
