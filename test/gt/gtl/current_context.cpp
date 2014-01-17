#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( CurrentContext )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( CurrentContext_respondsTo ) {
    // given
    GT::GTL::ContextPtr context = GT::GTL::NullFactory::getInstance().createContext();

    GT::Identifier properties = GT::createIdentifier("properties");
    GT::Identifier type       = GT::createIdentifier("type");
    GT::Identifier values     = GT::createIdentifier("values");
    GT::Identifier error      = GT::createIdentifier("error");

    // when
    GT::GTL::CurrentContext currentContext(context.get());

    // then
    BOOST_CHECK(  currentContext.respondsTo(properties) );
    BOOST_CHECK(  currentContext.respondsTo(type) );
    BOOST_CHECK(  currentContext.respondsTo(values) );
    BOOST_CHECK( !currentContext.respondsTo(error) );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
