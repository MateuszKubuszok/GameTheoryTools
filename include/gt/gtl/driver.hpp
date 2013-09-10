#ifndef __GT_GTL_DRIVER_HPP__
#define __GT_GTL_DRIVER_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

class Driver : public virtual Root {
    CoordinateDriver              coordinate;
    CollectionsDriver<Coordinate> coordinates;
    CollectionsDriver<Condition>  conditions;
    CollectionsDriver<Identifier> identifiers;
    CollectionsDriver<Object>     objects;
    CollectionsDriver<Param>      params;

public:
    Driver();

    virtual ~Driver();

    virtual CoordinateDriver& forCoordinate();

    virtual CollectionsDriver<Coordinate>& forCoordinates();
    
    virtual CollectionsDriver<Condition>& forConditions();
    
    virtual CollectionsDriver<Identifier>& forIdentifiers();
    
    virtual CollectionsDriver<Object>& forObjects();
    
    virtual CollectionsDriver<Param>& forParams();

    virtual void storeDefinedObject(
        const DefinitionPtr* definition
    );

    virtual void executeQuery(
        const QueryPtr* query
    );

    virtual DefinitionPtr* createDefinition(
        const IdentifierPtr* identifier,
        const ObjectPtr*     object
    );

    virtual QueryPtr* createQuery(
        const IdentifiersPtr* identifiers,
        const ObjectsPtr*     objects,
        const ConditionsPtr*  conditions
    );

    virtual ObjectPtr* convert(
        GamePtr* game
    );
    
    virtual ObjectPtr* convert(
        PlayerPtr* player
    );

    virtual ObjectPtr* convert(
        ParamPtr* param
    );

    virtual ObjectPtr* getValueForIdentifier(
        const IdentifierPtr* identifier
    );

    virtual GamePtr* createPureGameForDetails(
        const DetailsPtr* details
    );

    virtual GamePtr* createMixedGameForDetails(
        const DetailsPtr* details
    );

    virtual GamePtr* createTreeGameForDetails(
        const DetailsPtr* details
    );

    virtual DetailsPtr* createDetailsForGame(
        const ObjectsPtr*     players,
        const CoordinatesPtr* data
    );

    virtual PlayerPtr* createPlayerWithStrategies(
        const IdentifierPtr*  player,
        const IdentifiersPtr* strategies
    );

    virtual ParamPtr* getValue(
        const IdentifierPtr* identifier
    );

    virtual ParamPtr* getValue(
        const NumberPtr* number
    );

    virtual ConditionPtr* createPlayerChoiceCondition(
        const ObjectPtr* player,
        const ObjectPtr* strategy
    );

    virtual void errorInformation(
        const std::string& message
    );

    virtual Message toString();
}; /* END class Driver */

////////////////////////////////////////////////////////////////////////////////

class NullDriver : public Driver {
    NullCoordinateDriver              coordinate;
    NullCollectionsDriver<Coordinate> coordinates;
    NullCollectionsDriver<Condition>  conditions;
    NullCollectionsDriver<Identifier> identifiers;
    NullCollectionsDriver<Object>     objects;
    NullCollectionsDriver<Param>      params;

public:
    NullDriver() :
        Driver()
        {}

    virtual CoordinateDriver& forCoordinate() {
        return coordinate;
    }

    virtual CollectionsDriver<Coordinate>& forCoordinates() {
        return coordinates;
    }
    
    virtual CollectionsDriver<Condition>& forConditions() {
        return conditions;
    }
    
    virtual CollectionsDriver<Identifier>& forIdentifiers() {
        return identifiers;
    }
    
    virtual CollectionsDriver<Object>& forObjects() {
        return objects;
    }
    
    virtual CollectionsDriver<Param>& forParams() {
        return params;
    }

    virtual void storeDefinedObject(
        const DefinitionPtr* definition
    ) {}

    virtual void executeQuery(
        const QueryPtr* query
    ) {}

    virtual DefinitionPtr* createDefinition(
        const IdentifierPtr* identifier,
        const ObjectPtr*     object
    ) {
        return new DefinitionPtr(NullFactory::getInstance().createDefinition());
    }

    virtual QueryPtr* createQuery(
        const IdentifiersPtr* identifiers,
        const ObjectsPtr*     objects,
        const ConditionsPtr*  conditions
    ) {
        return new QueryPtr(NullFactory::getInstance().createQuery());
    }

    virtual ObjectPtr* convert(
        GamePtr* game
    ) {
        return new ObjectPtr(NullFactory::getInstance().createObject());
    }
    
    virtual ObjectPtr* convert(
        PlayerPtr* player
    ) {
        return new ObjectPtr(NullFactory::getInstance().createObject());
    }

    virtual ObjectPtr* convert(
        ParamPtr* param
    ) {
        return new ObjectPtr(NullFactory::getInstance().createObject());
    }

    virtual ObjectPtr* getValueForIdentifier(
        const IdentifierPtr* identifier
    ) {
        return new ObjectPtr(NullFactory::getInstance().createObject());
    }

    virtual GamePtr* createPureGameForDetails(
        const DetailsPtr* details
    ) {
        return new GamePtr(NullFactory::getInstance().createGame());
    }

    virtual GamePtr* createMixedGameForDetails(
        const DetailsPtr* details
    ) {
        return new GamePtr(NullFactory::getInstance().createGame());
    }

    virtual GamePtr* createTreeGameForDetails(
        const DetailsPtr* details
    ) {
        return new GamePtr(NullFactory::getInstance().createGame());
    }

    virtual DetailsPtr* createDetailsForGame(
        const ObjectsPtr*     players,
        const CoordinatesPtr* data
    ) {
        return new DetailsPtr(NullFactory::getInstance().createDetails());
    }

    virtual PlayerPtr* createPlayerWithStrategies(
        const IdentifierPtr*  player,
        const IdentifiersPtr* strategies
    ) {
        return new PlayerPtr(NullFactory::getInstance().createPlayer());
    }

    virtual ParamPtr* getValue(
        const IdentifierPtr* identifier
    ) {
        return new ParamPtr(NullFactory::getInstance().createParam());
    }

    virtual ParamPtr* getValue(
        const NumberPtr* number
    ) {
        return new ParamPtr(NullFactory::getInstance().createParam());
    }

    virtual ConditionPtr* createPlayerChoiceCondition(
        const ObjectPtr* player,
        const ObjectPtr* strategy
    ) {
        return new ConditionPtr(NullFactory::getInstance().createCondition());
    }

    virtual void errorInformation(
        const std::string& message
    ) {}

    virtual Message toString() {
        return Message("NullDriver");
    }
}; /* END class NullDriver */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END __GT_GTL_DRIVER_HPP__ */
