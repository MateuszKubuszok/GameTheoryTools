#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( CheckingDriver )

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( CheckingDriver_showError ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    std::ostringstream outputStream;
    GT::Message        message = GT::Message("Error Message");
    GT::GTL::ObjectPtr object  = GT::GTL::ErrorFactory::getInstance().createObject("Invalid Object");

    // when
    GT::GTL::CheckingDriver driver(&outputStream);
    driver.showError(message);
    driver.showError(*object);

    // then
    BOOST_CHECK_EQUAL(
        outputStream.str(),
        GT::Message() +
        "Error:\n"
        "\tError Message\n"
        "Error:\n"
        "\tInvalid Object\n"
    );
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
