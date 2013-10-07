#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( Param )

class ParamTestImpl : public GT::GTL::Param {
public:
    virtual GT::GTL::ObjectPtr getObject(
        GT::GTL::Context&                   context,
        GT::GTL::Param::VisitedIdentifiers& visitedIdentifiers
    ) {
        return GT::GTL::NullFactory::getInstance().createObject();
    }

    virtual GT::NumberPtr getNumber(
        GT::GTL::Context&                   context,
        GT::GTL::Param::VisitedIdentifiers& visitedIdentifiers
    ) {
        return GT::Model::NullFactory::getInstance().createNumber();
    }
};

BOOST_AUTO_TEST_CASE( Param_respondsTo ) {
    // given
    GT::Identifier properties = "properties";
    GT::Identifier type       = "type";
    GT::Identifier value      = "value";
    GT::Identifier error      = "error";

    // when
    ParamTestImpl param;

    // then
    BOOST_CHECK(  param.respondsTo(properties) );
    BOOST_CHECK(  param.respondsTo(type) );
    BOOST_CHECK(  param.respondsTo(value) );
    BOOST_CHECK( !param.respondsTo(error) );
}

BOOST_AUTO_TEST_SUITE_END()
