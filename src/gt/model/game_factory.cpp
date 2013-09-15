#include <boost/foreach.hpp>
#include <boost/bimap/bimap.hpp>
#include <boost/range/adaptor/map.hpp>
#include <boost/thread/mutex.hpp>

#include "gt/model/common.hpp"

namespace GT {
namespace Model {
    
////////////////////////////////////////////////////////////////////////////////

boost::mutex gameFactoryMutex;

////////////////////////////////////////////////////////////////////////////////

class PlainData : public Data {
    typedef boost::bimaps::bimap<Identifier, Index>          IdentifierMap;
    typedef boost::container::map<Identifier, IdentifierMap> StrategyMap;

    PlayersPtr players;

    IdentifierMap playersHelper;
    StrategyMap   strategiesHelper;
    IdentifierMap positionsHelper;

    boost::container::vector<NumbersPtr> paramsStorage;
    boost::container::vector<bool>       paramsStorageAllocation;
    
public:
    PlainData(
        PlayersPtr playersDefinitions
    ) :
        players(playersDefinitions),
        playersHelper(),
        strategiesHelper(),
        positionsHelper(),
        paramsStorage(),
        paramsStorageAllocation()
    {
        Index playerIndex   = 0;
        Index positionIndex = 1;

        BOOST_FOREACH(Players::value_type playerPair, (*players)) {
            const Identifier& playerName = playerPair.first;
            Player& player = *playerPair.second;

            IdentifierMap strategiesMap;
            BOOST_FOREACH(IdentifierPtr strategy, (*player.getStrategies()))
                strategiesMap.insert( IdentifierMap::value_type(*strategy, player.getStrategyOrdinal(*strategy)) );
            playersHelper.insert( IdentifierMap::value_type(playerName, playerIndex) );
            positionsHelper.insert( IdentifierMap::value_type(playerName, positionIndex) );
            strategiesHelper.insert( StrategyMap::value_type(playerName, strategiesMap) );

            playerIndex++;
            positionIndex *= player.getStrategiesNumber();
        }
    }

    virtual NumberPtr getValue(
        PositionsPtr  positions,
        IdentifierPtr playerName
    ) {
        NumbersPtr params = getValues(calculatePosition(positions));
        return (*params)[calculatePlayer(playerName)];
    }

    virtual NumbersPtr getValues(
        Index positionInStorage
    ) {
        if (!paramsStorageAllocation[positionInStorage])
            throw InvalidCoordinate("No params under such position");
        return paramsStorage[positionInStorage];
    }

    virtual NumbersPtr getValues(
        PositionsPtr positions
    ) {
        return getValues(calculatePosition(positions));
    }

    virtual PlainData& setValues(
        Index      positionInStorage,
        NumbersPtr numbers
    ) {
        paramsStorage[positionInStorage] = numbers;
        paramsStorageAllocation[positionInStorage] = true;
        return *this;
    }

    virtual PlainData& setValues(
        PositionsPtr positions,
        NumbersPtr   numbers
    ) {
        if (!checkPositions(positions))
            throw InvalidCoordinate("Invalid coordinates format");
        return setValues(
            calculatePosition(positions),
            numbers
        );
    }

    virtual Message toString() {
        return contentMessage()->getResult();
    }

private:
    Index calculatePlayer(
        Identifier& playerName
    ) {
        if (!checkPlayer(playerName))
            throw InvalidCoordinate("No such player");
        return playersHelper.left.at(playerName);
    }

    Index calculatePlayer(
        IdentifierPtr playerName
    ) {
        return checkPlayer(*playerName);
    }

    Index calculatePosition(
        Positions& positions
    ) {
        Index storagePosition = 0;
        BOOST_FOREACH(Positions::value_type position, positions) {
            storagePosition +=
                positionsHelper.left.at(position.first)
                *
                strategiesHelper[position.first].left.at(position.second);
        }
        return storagePosition;
    }

    Index calculatePosition(
        PositionsPtr positions
    ) {
        return calculatePosition(*positions);
    }

    bool checkPlayer(
        Identifier& playerName
    ) {
        return playersHelper.left.count(playerName);
    }

    bool checkPlayer(
        IdentifierPtr playerName
    ) {
        return checkPlayer(*playerName);
    }

    bool checkPositions(
        Positions& positions
    ) {
        BOOST_FOREACH(Identifier playerName, positions | boost::adaptors::map_keys) {
            if (!checkPlayer(playerName))
                return false;
            Identifier strategyName = positions[playerName];
            if (!strategiesHelper[playerName].left.count(strategyName))
                return false;
        }
        return true;
    }

    bool checkPositions(
        PositionsPtr positions
    ) {
        return checkPositions(*positions);
    }

    ResultPtr contentMessage() {
        // TODO: generate message with conetent using ResultBuilder
        return NullFactory::getInstance().createResult();
    }
}; /* END class PlainData */

////////////////////////////////////////////////////////////////////////////////

// class PlainDataBuilder : public DataBuilder {
//     PlayersPtr players;

//     boost::container::map<Identifier, bool> allocatedPositions;

//     PositionsPtr positions;


// }; 

////////////////////////////////////////////////////////////////////////////////

// class ResultFactory {
GameFactory* volatile GameFactory::instance = 0;

// public:
GameFactory& GameFactory::getInstance() {
    // Singleton implemented according to:
    // "C++ and the Perils of Double-Checked Locking"
    // but without executing constructor inside getInstance() method
    // since it's an eyesore. 
    if (!instance) {
        boost::mutex::scoped_lock lock(gameFactoryMutex);
        if (!instance) {
            GameFactory* volatile tmp = new GameFactory();
            instance = tmp;
        }
    }
    return *instance;
}

GameBuilderPtr GameFactory::buildPureGame() {
    // TODO
    return NullFactory::getInstance().createGameBuilder();
}

GameBuilderPtr GameFactory::buildMixedGame() {
    // TODO
    return NullFactory::getInstance().createGameBuilder();
}

GameBuilderPtr GameFactory::buildTreeGame() {
    // TODO
    return NullFactory::getInstance().createGameBuilder();
}

// private:
GameFactory::GameFactory() {}
// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
