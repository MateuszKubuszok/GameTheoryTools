/**
 * @file      gt/gtl/coordinate.cpp
 * @brief     Defines GT::GTL::Coordinate methods.
 * @copyright (C) 2013-2014
 * @author    Mateusz Kubuszok
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero
 * General Public License as published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this program. If not,
 * see [http://www.gnu.org/licenses/].
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class Coordinate : public virtual ValidableSymbol {
// public:

Coordinate::Coordinate() :
    Root(),
    positions(new Positions()),
    params(new Params()),
    subCoordinates(new Coordinates())
    {}

Coordinate::Coordinate(
    const IdentifierPtr player,
    const IdentifierPtr strategy
) :
    Root(),
    positions(new Positions()),
    params(new Params()),
    subCoordinates(new Coordinates())
{
    positions->insert( Positions::value_type(*player, *strategy) );
}

Coordinate& Coordinate::addParam(
    const ParamPtr param
) {
    params->push_back(param);
    return *this;
}

Coordinate& Coordinate::addParams(
    const ParamsPtr newParams
) {
    params->reserve(params->size() + newParams->size());
    params->insert(params->end(), newParams->begin(), newParams->end());
    return *this;
}

Coordinate& Coordinate::addPosition(
    const IdentifierPtr player,
    const IdentifierPtr strategy
) {
    positions->insert( Positions::value_type(*player, *strategy) );
    return *this;
}

Coordinate& Coordinate::addSubCoordinate(
    const CoordinatePtr subCoordinate
) {
    subCoordinates->push_back(subCoordinate);
    return *this;
}

Coordinate& Coordinate::addSubCoordinates(
    const CoordinatesPtr newSubCoordinates
) {
    subCoordinates->reserve(subCoordinates->size() + newSubCoordinates->size());
    subCoordinates->insert(subCoordinates->end(), newSubCoordinates->begin(), newSubCoordinates->end());
    return *this;
}

const ParamsPtr Coordinate::getParams() const {
    return params;
}

const PositionsPtr Coordinate::getPositions() const {
    return positions;
}

const CoordinatesPtr Coordinate::getSubCoordinates() const {
    return subCoordinates;
}

void Coordinate::fillDataBuilder(
    const Context&         context,
    Model::DataBuilderPtr& dataBuilder
) const {
    if (positions->size())
        dataBuilder->addNextPositions(positions);

    if (params->size()) {
        NumbersPtr values(new Numbers());
        for (ParamPtr& param : *params)
            values->push_back(param->getNumber(context));
        dataBuilder->setPayoffs(values);
    }

    if (subCoordinates->size()){
        for (CoordinatePtr& coordinate : *subCoordinates) {
            Model::DataBuilderPtr passedBuilder = dataBuilder->clone();
            coordinate->fillDataBuilder(context, passedBuilder);
        }
    }
}

Message Coordinate::toString() const {
    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();

    if (params->size()) {
        static const IdentifierPtr paramsName = createIdentifierPtr("Params");

        ResultBuilderPtr subResultBuilder = ResultFactory::getInstance().buildResult();
        static const IdentifierPtr name = createIdentifierPtr("Param");
        for (ParamPtr& param : *params) {
            MessagePtr value = createMessagePtr(param->toString());
            subResultBuilder->addResult(name, value);
        }
        MessagePtr paramsValue = createMessagePtr(subResultBuilder->build()->getResult());

        resultBuilder->addResult(paramsName, paramsValue);
    }

    if (positions->size()) {
        static const IdentifierPtr positionsName = createIdentifierPtr("Positions");

        ResultBuilderPtr subResultBuilder = ResultFactory::getInstance().buildResult();
        for (Positions::value_type& position : *positions) {
            IdentifierPtr name  = createIdentifierPtr(position.first);
            MessagePtr    value = createMessagePtr(position.second);
            subResultBuilder->addResult(name, value);
        }
        MessagePtr positionsValue = createMessagePtr(subResultBuilder->build()->getResult());

        resultBuilder->addResult(positionsName, positionsValue);
    }

    if (subCoordinates->size()) {
        static const IdentifierPtr subCoordinatesName = createIdentifierPtr("SubCoordinates");
        static const IdentifierPtr name               = createIdentifierPtr("Coordinate");

        ResultBuilderPtr subResultBuilder = ResultFactory::getInstance().buildResult();
        for (CoordinatePtr& subCoordinate : *subCoordinates) {
            MessagePtr value = createMessagePtr(subCoordinate->toString());
            subResultBuilder->addResult(name, value);
        }
        MessagePtr subCoordinatesValue = createMessagePtr(subResultBuilder->build()->getResult());

        resultBuilder->addResult(subCoordinatesName, subCoordinatesValue);
    }

    return resultBuilder->build()->getResult();
}

// }; /* END class Coordinate */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

Coordinate operator+(
    const Coordinate& coordinate1,
    const Coordinate& coordinate2
) {
    Coordinate result;

    for (const Positions::value_type& position : *coordinate1.getPositions())
        result.positions->insert(position);
    for (const Positions::value_type& position : *coordinate2.getPositions())
        result.positions->insert(position);

    for (const ParamPtr& param : *coordinate1.getParams())
        result.params->push_back(param);
    for (const ParamPtr& param : *coordinate2.getParams())
        result.params->push_back(param);

    for (const CoordinatePtr& subCoordinate : *coordinate1.getSubCoordinates())
        result.subCoordinates->push_back(subCoordinate);
    for (const CoordinatePtr& subCoordinate : *coordinate2.getSubCoordinates())
        result.subCoordinates->push_back(subCoordinate);

    return result;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
