#include <boost/bimap/bimap.hpp>
#include <boost/thread/mutex.hpp>

#include "gt/model/common.hpp"

namespace GT {
namespace Model {
    
////////////////////////////////////////////////////////////////////////////////

boost::mutex gameFactoryMutex;

////////////////////////////////////////////////////////////////////////////////

class PlainData : public Data {
    PlayersPtr players;

    boost::bimaps::bimap<Identifier, int> playerHelper;

    boost::bimaps::bimap<Identifier, int> positionsHelper;

    boost::container::vector<NumbersPtr> paramsStorage;

    boost::container::vector<bool> paramsStorageAllocation;
    
public:
    virtual NumberPtr getValue(
        PositionsPtr  positions,
        IdentifierPtr playerName
    ) {
        // TODO: retrive value from map
        NumbersPtr params = getValues(calculatePosition(positions));
        return (*params)[calculatePlayer(playerName)];
    }

    virtual NumbersPtr getValues(
        int positionInStorage
    ) {
        if (!paramsStorageAllocation[positionInStorage])
            throw InvalidCoordinate("No params under such position");
        return paramsStorage[positionInStorage];
    }

    virtual NumbersPtr getValues(
        PositionsPtr positions
    ) {
        return getValues(
            calculatePosition(positions)
        );
    }

    virtual PlainData& setValues(
        int        positionInStorage,
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
        return setValues(
            calculatePosition(positions),
            numbers
        );
    }

    virtual Message toString() {
        // TODO: print data as table: | positions | values |
        return *NullFactory::getInstance().createMessage();
    }

private:
    int calculatePlayer(
        IdentifierPtr identifier
    ) {
        // TODO: positions -> int
        // throw std::runtime_exception if positions do not match players
        return 0;
    }

    int calculatePosition(
        PositionsPtr positions
    ) {
        // TODO: positions -> int
        // throw std::runtime_exception if positions do not match players
        return 0;
    }

    bool checkPlayer(
        IdentifierPtr playerName
    ) {
        // TODO:
        return true;
    }

    bool checkPositions(
        PositionsPtr positions
    ) {
        // TODO:
        return true;
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
