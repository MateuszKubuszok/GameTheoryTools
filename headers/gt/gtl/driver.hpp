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
        Definition& definition
    );

    virtual void executeQuery(
        Query& query
    );

    virtual Definition createDefinition(
        Object&     object,
        Identifier& identifier
    );

    virtual Query createQuery(
        Identifiers& identifiers,
        Objects&     objects,
        Conditions&  conditions
    );

    virtual Objects createObjectsCollection(
        Object& object
    );

    virtual Objects addObjectToCollection(
        Object&  object,
        Objects& objects
    );

    virtual Object getValueForIdentifier(
        Identifier& identifier
    );

    virtual Game createPureGameForDetails(
        Details& details
    );

    virtual Game createMixedGameForDetails(
        Details& details
    );

    virtual Game createTreeGameForDetails(
        Details& details
    );

    virtual Details createDetailsForGame(
        Objects& objects,
        Data&    data
    );

    virtual Player createPlayerWithStrategies(
        Identifier& identifier,
        Objects&    objects
    );

    virtual Param getValueForIdentifier(
        Identifier& identifier
    );

    virtual Param& getValueForNumber(
        Number& number
    );

    virtual Params createParamsCollection(
        Param& param
    );

    virtual Params addParamToCollection(
        Param&  param,
        Params& params
    );

    virtual Identifiers createIdentifiersCollection(
        Identifier& identifier
    );

    virtual Identifiers addIdentifierToCollection(
        Identifier&  identifier,
        Identifiers& identifiers
    );

    virtual Condition createPlayerChoiceCondition(
        Object& player,
        Object& strategy
    );

    virtual Conditions createConditionsCollection(
        Condition& condition
    );

    virtual Conditions emptyConditionsCollection();

    virtual Conditions addConditionToCollection(
        Condition&  condition,
        Conditions& conditions
    );

    virtual Data createData(
        DataPieces& dataPieces
    );

    virtual DataPieces createDataPieceCollection(
        DataPiece& dataPiece
    );

    virtual DataPieces addDataPieceToCollection(
        DataPiece&  dataPiece,
        DataPieces& dataPieces
    );

    virtual DataPiece createOneDimensionDataPieces(
        Identifiers& identifiers,
        Params&      params
    );

    virtual DataPiece createMultiDimensionalDataPiece(
        Identifiers& identifiers,
        DataPieces&  dataPieces
    );

private:
    Context context;
} /* END class Driver */

} /* END namespace GTL */
} /* END namespace GT */
#endif /* END __GT_GTL_DRIVER_HPP__ */
