#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( CheckingDriver )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( CheckingDriver_showError ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    std::ostringstream errorStream;
    GT::GTL::InputLocationPtr location = GT::GTL::NullFactory::getInstance().createInputLocation();
    GT::Message               message  = GT::Message("Error Message");
    GT::GTL::ObjectPtr        object   = GT::GTL::ErrorFactory::getInstance().createObject("Invalid Object");

    // when
    GT::GTL::CheckingDriver driver(&errorStream);
    driver.showError(*location, message);
    driver.showError(*object);

    // then
    BOOST_CHECK_EQUAL(
        errorStream.str(),
        GT::Message() +
        "Error:\n"
        "\tError Message\n"
        "\t\tfrom line 1 (column 1)\n"
        "\t\tto line 1 (column 1)\n"
        "Error:\n"
        "\tInvalid Object\n"
        "\t\tfrom line 1 (column 1)\n"
        "\t\tto line 1 (column 1)\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
