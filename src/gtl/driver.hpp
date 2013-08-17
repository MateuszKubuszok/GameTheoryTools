#ifndef __GTL_DRIVER_HPP__
#define __GTL_DRIVER_HPP__ 1

#include "gtl/common.hpp"

namespace GTL {
class Driver {
public:
    Driver();

    virtual ~Driver();

    virtual void storeDefinedObject(
    	Definition &definition
    );

    virtual void executeQuery(
    	Query &query
    );

    virtual Definition& createDefinition(
    	Object     &object,
    	Identifier &identifier
    );

    virtual Query& createQuery(
    	Identifiers &identifiers,
    	Objects     &objects,
    	Conditions  &conditions
    );

	virtual Objects& createObjectsCollection(
		Object &object
	);

	virtual Objects& addObjectToCollection(
		Object  &object,
		Objects &objects
	);

	virtual Object& getValueForIdentifier(
		Identifier &identifier
	);

	virtual Game& createPureGameForDetails(
		Details &details
	);

	virtual Game& createMixedGameForDetails(
		Details &details
	);

	virtual Game& createTreeGameForDetails(
		Details &details
	);

	virtual Details& createDetailsForGame(
		Objects &objects,
		Data    &data
	);

	virtual Player& createPlayerWithStrategies(
		Identifier &identifier,
		Objects    &objects
	);

	virtual Param& getValueForIdentifier(
		Identifier &identifier
	);

	virtual Param& getValueForNumber(
		double number
	);

	virtual Params& createParamsCollection(
		Param& param
	);

	virtual Params& addParamToCollection(
		Param&  param,
		Params& params
	);

	virtual Identifiers& createIdentifiersCollection(
		Identifier &identifier
	);

	virtual Identifiers& addIdentifierToCollection(
		Identifier  &identifier,
		Identifiers &identifiers
	);

	virtual Condition& createPlayerChoiceCondition(
		Object &player,
		Object &strategy
	);

	virtual Conditions& createConditionsCollection(
		Condition &condition
	);

	virtual Conditions& emptyConditionsCollection();

	virtual Conditions& addConditionToCollection(
		Condition   &condition,
		Conditions& conditions
	);

	virtual Data& createData(
		DataPiece &dataPiece
	);

	virtual Data& addDataPieceToData(
		DataPiece &dataPiece,
		Data      &data
	);

	virtual DataPiece& createOneDimensionData(
		Identifier &identifier,
		Param      &param
	);

	virtual DataPiece& createTwoDimensionData(
		Identifiers &identifiers,
		Identifier  &identifier,
		Params      &params
	);

	virtual DataPiece& createMultiDimensionalData(
		Identifiers &identifiers,
		Params      &params
	);
} /* END class Driver */
} /* END namespace GTL */
#endif /* END __GTL_DRIVER_HPP__ */