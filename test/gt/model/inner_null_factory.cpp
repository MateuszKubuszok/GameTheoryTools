#include "gt/model/test_common.hpp"

BOOST_AUTO_TEST_SUITE( InnerNullFactory )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( InnerNullFactory_createStrategicData ) {
    // given
    // when
    GT::Model::StrategicDataPtr result = GT::Model::InnerNullFactory::getInstance().createStrategicData();

    // then
    BOOST_REQUIRE(result);
    BOOST_CHECK(result->isNull());
    BOOST_CHECK(!result->isNotNull());
}

BOOST_AUTO_TEST_CASE( InnerNullFactory_createExtensiveData ) {
    // given
    // when
    GT::Model::ExtensiveDataPtr result = GT::Model::InnerNullFactory::getInstance().createExtensiveData();

    // then
    BOOST_REQUIRE(result);
    BOOST_CHECK(result->isNull());
    BOOST_CHECK(!result->isNotNull());
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
