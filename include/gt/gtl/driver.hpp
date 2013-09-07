#ifndef __GT_GTL_DRIVER_HPP__
#define __GT_GTL_DRIVER_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

class Driver : public virtual Root {
public:
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

    virtual ObjectsPtr* createObjectsCollection(
        const ObjectPtr* object
    );

    virtual ObjectsPtr* addObjectToCollection(
        const ObjectPtr*  object,
        const ObjectsPtr* objects
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

    virtual ParamsPtr* createParamsCollection(
        const ParamPtr* param
    );

    virtual ParamsPtr* addParamToCollection(
        const ParamPtr*  param,
        const ParamsPtr* params
    );

    virtual IdentifiersPtr* createIdentifiersCollection(
        const IdentifierPtr* identifier
    );

    virtual IdentifiersPtr* addIdentifierToCollection(
        const IdentifierPtr*  identifier,
        const IdentifiersPtr* identifiers
    );

    virtual ConditionPtr* createPlayerChoiceCondition(
        const ObjectPtr* player,
        const ObjectPtr* strategy
    );

    virtual ConditionsPtr* createConditionsCollection(
        const ConditionPtr* condition
    );

    virtual ConditionsPtr* emptyConditionsCollection();

    virtual ConditionsPtr* addConditionToCollection(
        const ConditionPtr*  condition,
        const ConditionsPtr* conditions
    );

    virtual CoordinatesPtr* addCoordinatesToCollection(
        const CoordinatesPtr* coordinates,
        const CoordinatePtr*  coordinate
    );

    virtual CoordinatesPtr* createCoordinatesCollection(
        const CoordinatePtr* coordinate
    );

    virtual CoordinatePtr* fillCoordinateWithData(
        const CoordinatePtr*  coordinate,
        const CoordinatesPtr* data
    );

    virtual CoordinatePtr* fillCoordinateWithData(
        const CoordinatePtr* coordinate,
        const ParamsPtr*     data
    );

    virtual CoordinatePtr* mergeCoordinates(
        const CoordinatePtr* coordinate1,
        const CoordinatePtr* coordinate2
    );

    virtual CoordinatePtr* createCoordinate(
        const IdentifierPtr* player,
        const IdentifierPtr* strategy
    );

    virtual void errorInformation(
        const std::string& message
    );

    virtual Message toString();
}; /* END class Driver */

////////////////////////////////////////////////////////////////////////////////

class NullDriver : public Driver {
public:
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

    virtual ObjectsPtr* createObjectsCollection(
        const ObjectPtr* object
    ) {
        return new ObjectsPtr(NullFactory::getInstance().createObjects());
    }

    virtual ObjectsPtr* addObjectToCollection(
        const ObjectPtr*  object,
        const ObjectsPtr* objects
    ) {
        return new ObjectsPtr(NullFactory::getInstance().createObjects());
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

    virtual ParamsPtr* createParamsCollection(
        const ParamPtr* param
    ) {
        return new ParamsPtr(NullFactory::getInstance().createParams());
    }

    virtual ParamsPtr* addParamToCollection(
        const ParamPtr*  param,
        const ParamsPtr* params
    ) {
        return new ParamsPtr(NullFactory::getInstance().createParams());
    }

    virtual IdentifiersPtr* createIdentifiersCollection(
        const IdentifierPtr* identifier
    ) {
        return new IdentifiersPtr(Model::NullFactory::getInstance().createIdentifiers());
    }

    virtual IdentifiersPtr* addIdentifierToCollection(
        const IdentifierPtr*  identifier,
        const IdentifiersPtr* identifiers
    ) {
        return new IdentifiersPtr(Model::NullFactory::getInstance().createIdentifiers());
    }

    virtual ConditionPtr* createPlayerChoiceCondition(
        const ObjectPtr* player,
        const ObjectPtr* strategy
    ) {
        return new ConditionPtr(NullFactory::getInstance().createCondition());
    }

    virtual ConditionsPtr* createConditionsCollection(
        const ConditionPtr* condition
    ) {
        return new ConditionsPtr(NullFactory::getInstance().createConditions());
    }

    virtual ConditionsPtr* emptyConditionsCollection() {
        return new ConditionsPtr(NullFactory::getInstance().createConditions());
    }

    virtual ConditionsPtr* addConditionToCollection(
        const ConditionPtr*  condition,
        const ConditionsPtr* conditions
    ) {
        return new ConditionsPtr(NullFactory::getInstance().createConditions());
    }

    virtual CoordinatesPtr* addCoordinatesToCollection(
        const CoordinatesPtr* coordinates,
        const CoordinatePtr*  coordinate
    ) {
        return new CoordinatesPtr(NullFactory::getInstance().createCoordinates());
    }

    virtual CoordinatesPtr* createCoordinatesCollection(
        const CoordinatePtr* coordinate
    ) {
        return new CoordinatesPtr(NullFactory::getInstance().createCoordinates());
    }

    virtual CoordinatePtr* fillCoordinateWithData(
        const CoordinatePtr*  coordinate,
        const CoordinatesPtr* data
    ) {
        return new CoordinatePtr(NullFactory::getInstance().createCoordinate());
    }

    virtual CoordinatePtr* fillCoordinateWithData(
        const CoordinatePtr* coordinate,
        const ParamsPtr*     data
    ) {
        return new CoordinatePtr(NullFactory::getInstance().createCoordinate());
    }

    virtual CoordinatePtr* mergeCoordinates(
        const CoordinatePtr* coordinate1,
        const CoordinatePtr* coordinate2
    ) {
        return new CoordinatePtr(NullFactory::getInstance().createCoordinate());
    }

    virtual CoordinatePtr* createCoordinate(
        const IdentifierPtr* player,
        const IdentifierPtr* strategy
    ) {
        return new CoordinatePtr(NullFactory::getInstance().createCoordinate());
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
