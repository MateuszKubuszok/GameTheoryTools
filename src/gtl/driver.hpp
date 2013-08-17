#ifndef __GTL_DRIVER_HPP__
#define __GTL_DRIVER_HPP__ 1

#include <boost/container/slist.hpp>

#include "gtl/condition.hpp"
#include "gtl/data.hpp"
#include "gtl/definition.hpp"
#include "gtl/details.hpp"
#include "gtl/game.hpp"
#include "gtl/query.hpp"
#include "gtl/object.hpp"

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
    	Object &object,
    	std::string &identifier
    );

    virtual Query& createQuery(
    	boost::containers::slist<std::string> &identifiers,
    	boost::containers::slist<Object> &objects,
    	boost::containers::slist<Condition> &conditions
    );

	virtual boost::containers::slist<Object>& createObjectsCollection(
		Object &object
	);

	virtual boost::containers::slist<Object>& addObjectToCollection(
		Object &object,
		boost::containers::slist<Object> &objects
	);

	virtual Object& getValueForIdentifier(
		std::string &identifier
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
		boost::containers::slist<Object> &objects,
		Data &data
	);

	virtual Player& createPlayerWithStrategies(
		std::string &identifier,
		boost::containers::slist<Object> &objects
	);

	virtual Param& getValueForIdentifier(
		std::string &identifier
	);

	virtual Param& getValueForNumber(
		double number
	);

	virtual boost::containers::slist<Param> createParamsCollection(
		Param& param
	);

	virtual boost::containers::slist<Param> addParamToCollection(
		Param& param,
		boost::containers::slist<Param> params
	);

	virtual boost::containers::slist<std::string> createIdentifiersCollection(
		std::string &identifier
	);

	virtual boost::containers::slist<std::string> addIdentifierToCollection(
		std::string &identifier,
		boost::containers::slist<std::string> &identifiers
	);

	virtual Condition& createPlayerChoiceCondition(
		Object &object,
		Object &object
	);

	virtual boost::containers::slist<Condition> createConditionsCollection(
		Condition &condition
	);

	virtual boost::containes::slist<Condition> emptyConditionsCollection();

	virtual boost::containers::slist<Condition> addConditionToCollection(
		Condition &condition,
		boost::containers::slist<Condition> conditions
	);
} /* END class Driver */
} /* END namespace GTL */
#endif /* END __GTL_DRIVER_HPP__ */