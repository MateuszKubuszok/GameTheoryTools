#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( DriverFactory )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( DriverFactory_createCheckingDriver ) {
    // given
    // when
    GT::GTL::DriverPtr result = GT::GTL::DriverFactory::getInstance().createCheckingDriver(&std::cerr);

    // then
    BOOST_REQUIRE(result);
    BOOST_CHECK(result->isNotNull());
    BOOST_CHECK_EQUAL(
        result->toString(),
        "CheckingDriver"
    );
}

BOOST_AUTO_TEST_CASE( DriverFactory_createExecutionDriver ) {
    // given
    // when
    GT::GTL::DriverPtr result = GT::GTL::DriverFactory::getInstance()
                                       .createExecutionDriver(&std::cout, &std::cerr);

    // then
    BOOST_REQUIRE(result);
    BOOST_CHECK(result->isNotNull());
    BOOST_CHECK_EQUAL(
        result->toString(),
        "ExecutionDriver"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
