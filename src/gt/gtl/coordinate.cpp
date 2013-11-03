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

ParamsPtr Coordinate::getParams() {
    return params;
}

PositionsPtr Coordinate::getPositions() {
    return positions;
}

CoordinatesPtr Coordinate::getSubCoordinates() {
    return subCoordinates;
}

void Coordinate::fillDataBuilder(
    Context&               context,
    Model::DataBuilderPtr& dataBuilder
) {
    if (positions->size())
        dataBuilder->addNextPositions(positions);

    if (params->size()) {
        NumbersPtr values(new Numbers());
        for (ParamPtr& param : *params)
            values->push_back(param->getNumber(context));
        dataBuilder->setParams(values);
    }

    if (subCoordinates->size()){
        for (CoordinatePtr& coordinate : *subCoordinates) {
            Model::DataBuilderPtr passedBuilder = dataBuilder->clone();
            coordinate->fillDataBuilder(context, passedBuilder);
        }
    }
}

Message Coordinate::toString() {
    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();

    if (params->size()) {
        IdentifierPtr paramsName = createIdentifierPtr("Params");

        ResultBuilderPtr subResultBuilder = ResultFactory::getInstance().buildResult();
        IdentifierPtr name = createIdentifierPtr("Param");
        for (ParamPtr& param : *params) {
            MessagePtr value = createMessagePtr(param->toString());
            subResultBuilder->addResult(name, value);
        }
        MessagePtr paramsValue = createMessagePtr(subResultBuilder->build()->getResult());

        resultBuilder->addResult(paramsName, paramsValue);
    }

    if (positions->size()) {
        IdentifierPtr positionsName = createIdentifierPtr("Positions");

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
        IdentifierPtr subCoordinatesName = createIdentifierPtr("SubCoordinates");

        ResultBuilderPtr subResultBuilder = ResultFactory::getInstance().buildResult();
        IdentifierPtr name = createIdentifierPtr("Coordinate");
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
    Coordinate& coordinate1,
    Coordinate& coordinate2
) {
    Coordinate result;

    for (Positions::value_type& position : *coordinate1.getPositions())
        result.positions->insert(position);
    for (Positions::value_type& position : *coordinate2.getPositions())
        result.positions->insert(position);

    for (ParamPtr& param : *coordinate1.getParams())
        result.params->push_back(param);
    for (ParamPtr& param : *coordinate2.getParams())
        result.params->push_back(param);

    for (CoordinatePtr& subCoordinate : *coordinate1.getSubCoordinates())
        result.subCoordinates->push_back(subCoordinate);
    for (CoordinatePtr& subCoordinate : *coordinate2.getSubCoordinates())
        result.subCoordinates->push_back(subCoordinate);

    return result;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
