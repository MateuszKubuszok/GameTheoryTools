#ifndef __GTL_OBJECT_HPP__
#define __GTL_OBJECT_HPP__ 1

#include <boost/container/map.hpp>

#include "gtl/common.hpp"

namespace GTL {
class Object {
public:
    Object() :
        registeredProperties()
        {}

    virtual ~Object() {
    	delete registeredProperties;
    }

    virtual bool isValid() {
        return false;
    } 

    bool respondsTo(
    	Identifier &property
    ) {
    	return this->isFinderRegistered(property);
    }

    Result& findProperty(
        Identifier &property
    ) {
        return this->findPropertyWithConditions(property, noConditions);
    }

    Result& findPropertyWithConditions(
        Identifier &property,
        Conditions &conditions
    ) {
    	return this->getFinder(property)(conditions);
    }

protected:
	typedef Result& (Object::*ResultFinder)(Conditions&);

	bool isFinderRegistered(
		Identifier &property
	) {
		return this->registeredProperties.count(property) > 0;
	}

	ResultFinder* getFinder(
		Identifier &property
	) {
		return this->registeredProperties[property];
	}

    static Conditions &noConditions = new Conditions();

private:
    boost::containers::map<Identifier, ResultFinder> registeredProperties;
} /* END class Object */
} /* END namespace GTL */
#endif /* END ifndef __GTL_OBJECT_HPP__ */