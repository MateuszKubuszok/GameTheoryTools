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

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END __GT_GTL_DRIVER_HPP__ */
