#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "gt/model/inner_common.hpp"

BOOST_AUTO_TEST_SUITE( Result )

class ResultTestImpl : public GT::Model::Result {
public:
    virtual GT::Message getResult() {
        return GT::Message("TestResult");
    }
}; /* END class ResultTestImpl */

BOOST_AUTO_TEST_CASE( Result_getResult ) {
    // given

    // when
    ResultTestImpl result;

    // then
    BOOST_CHECK_EQUAL(
        result.getResult(),
        GT::Message("TestResult")
    );
    BOOST_CHECK_EQUAL(
        result.getResult(),
        result.toString()
    );
}

BOOST_AUTO_TEST_CASE( Result_toString ) {
    // given

    // when
    ResultTestImpl result;

    // then
    BOOST_CHECK_EQUAL(
        result.toString(),
        GT::Message("TestResult")
    );
}

BOOST_AUTO_TEST_SUITE_END()
