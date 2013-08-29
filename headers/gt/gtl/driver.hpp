#ifndef __GT_GTL_DRIVER_HPP__
#define __GT_GTL_DRIVER_HPP__ 1

#include "gt/gtl/common.hpp"

namespace GT {
namespace GTL {

class Driver {
public:
    Driver() :
        context();

    virtual ~Driver();

    virtual void storeDefinedObject(
        const Definition& definition
    );

    virtual void executeQuery(
        const Query& query
    );

    virtual Definition createDefinition(
        const Object&     object,
        const Identifier& identifier
    );

    virtual Query createQuery(
        const Identifiers& identifiers,
        const Objects&     objects,
        const Conditions&  conditions
    );

    virtual Objects createObjectsCollection(
        const Object& object
    );

    virtual Objects addObjectToCollection(
        const Object&  object,
        const Objects& objects
    );

    virtual Object getValueForIdentifier(
        const Identifier& identifier
    );

    virtual Game createPureGameForDetails(
        const Details& details
    );

    virtual Game createMixedGameForDetails(
        const Details& details
    );

    virtual Game createTreeGameForDetails(
        const Details& details
    );

    virtual Details createDetailsForGame(
        const Objects& objects,
        const Data&    data
    );

    virtual Player createPlayerWithStrategies(
        const Identifier& identifier,
        const Objects&    objects
    );

    virtual Param getValueForIdentifier(
        const Identifier& identifier
    );

    virtual Param& getValueForNumber(
        const Number& number
    );

    virtual Params createParamsCollection(
        const Param& param
    );

    virtual Params addParamToCollection(
        const Param&  param,
        const Params& params
    );

    virtual Identifiers createIdentifiersCollection(
        const Identifier& identifier
    );

    virtual Identifiers addIdentifierToCollection(
        const Identifier&  identifier,
        const Identifiers& identifiers
    );

    virtual Condition createPlayerChoiceCondition(
        const Object& player,
        const Object& strategy
    );

    virtual Conditions createConditionsCollection(
        const Condition& condition
    );

    virtual Conditions emptyConditionsCollection();

    virtual Conditions addConditionToCollection(
        const Condition&  condition,
        const Conditions& conditions
    );

    virtual Data createData(
        const Coordinates& coordinates
    );

    virtual Coordinates addCoordinatesToCollection(
        const Coordinates& coordinates,
        const Coordinate&  coordinate
    );

    virtual Coordinates createCoordinatesCollection(
        const Coordinate& coordinate
    );

    virtual Coordinate fillCoordinateWithData(
        const Coordinate&  coordinate,
        const Coordinates& data
    );

    virtual Coordinate fillCoordinateWithData(
        const Coordinate&  coordinate,
        const Params& data
    );

    virtual Coordinate mergeCoordinates(
        const Coordinate& coordinate1
        const Coordinate& coordinate2
    );

    virtual Coordinate createCoordinate(
        const Identifier& player,
        const Identifier& strategy
    );

private:
    const Context context;
} /* END class Driver */

} /* END namespace GTL */
} /* END namespace GT */
#endif /* END __GT_GTL_DRIVER_HPP__ */
