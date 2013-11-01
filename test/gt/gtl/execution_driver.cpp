#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ExecutionDriver )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ExecutionDriver_showResult ) {
    // given
    std::ostringstream outputStream;
    GT::GTL::ResultPtr result = GT::GTL::ResultFactory::getInstance().constResult(GT::Message("Result"));

    // when
    GT::GTL::ExecutionDriver driver(&outputStream, &outputStream);
    driver.showResult(result);

    // then
    BOOST_CHECK_EQUAL(
        outputStream.str(),
        GT::Message() +
        "Result"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
