#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "gt/model/inner_common.hpp"

BOOST_AUTO_TEST_SUITE( InnerNullFactory )


BOOST_AUTO_TEST_CASE( InnerNullFactory_createStrategicData ) {
    // given
    // when
    GT::Model::StrategicDataPtr result = GT::Model::InnerNullFactory::getInstance().createStrategicData();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->isNull());
    BOOST_CHECK(!result->isNotNull());
}

BOOST_AUTO_TEST_SUITE_END()
