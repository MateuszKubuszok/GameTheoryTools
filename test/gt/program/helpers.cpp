#include "gt/program/test_common.hpp"

BOOST_AUTO_TEST_SUITE( helpers )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( helpers_ResultBuilderModeOperatorOverload ) {
    // given
    std::string        smallPlain = "plain";
    std::istringstream smallPlainStream(smallPlain);
    std::string        largePlain = "PLAIN";
    std::istringstream largePlainStream(largePlain);
    std::string        smallJson  = "json";
    std::istringstream smallJsonStream(smallJson);
    std::string        largeJson  = "JSON";
    std::istringstream largeJsonStream(largeJson);
    std::string        smallXML   = "xml";
    std::istringstream smallXMLStream(smallXML);
    std::string        largeXML   = "XML";
    std::istringstream largeXMLStream(largeXML);
    std::string        invalid    = "invalid";
    std::istringstream invalidStream(invalid);

    // when
    GT::Model::ResultBuilderMode resultBuilderMode = GT::Model::ResultBuilderMode::PLAIN;

    // then
    BOOST_REQUIRE_NO_THROW( smallPlainStream >> resultBuilderMode );
    BOOST_CHECK( resultBuilderMode == GT::Model::ResultBuilderMode::PLAIN );
    BOOST_REQUIRE_NO_THROW( largePlainStream >> resultBuilderMode );
    BOOST_CHECK( resultBuilderMode == GT::Model::ResultBuilderMode::PLAIN );
    BOOST_REQUIRE_NO_THROW( smallJsonStream >> resultBuilderMode );
    BOOST_CHECK( resultBuilderMode == GT::Model::ResultBuilderMode::JSON );
    BOOST_REQUIRE_NO_THROW( largeJsonStream >> resultBuilderMode );
    BOOST_CHECK( resultBuilderMode == GT::Model::ResultBuilderMode::JSON );
    BOOST_REQUIRE_NO_THROW( smallXMLStream >> resultBuilderMode );
    BOOST_CHECK( resultBuilderMode == GT::Model::ResultBuilderMode::XML );
    BOOST_REQUIRE_NO_THROW( largeXMLStream >> resultBuilderMode );
    BOOST_CHECK( resultBuilderMode == GT::Model::ResultBuilderMode::XML );
    BOOST_REQUIRE_THROW(
        invalidStream >> resultBuilderMode,
        boost::program_options::validation_error
    );
}

BOOST_AUTO_TEST_CASE( helpers_ResultIndentationModeOperatorOverload ) {
    // given
    std::string        smallTabs   = "tabs";
    std::istringstream smallTabsStream(smallTabs);
    std::string        largeTabs   = "TABS";
    std::istringstream largeTabsStream(largeTabs);
    std::string        smallSpaces = "spaces";
    std::istringstream smallSpacesStream(smallSpaces);
    std::string        largeSpaces = "SPACES";
    std::istringstream largeSpacesStream(largeSpaces);
    std::string        smallNone   = "none";
    std::istringstream smallNoneStream(smallNone);
    std::string        largeNone   = "NONE";
    std::istringstream largeNoneStream(largeNone);
    std::string        invalid    = "invalid";
    std::istringstream invalidStream(invalid);

    // when
    GT::Model::ResultIndentationMode resultIndentationMode;

    // then
    BOOST_REQUIRE_NO_THROW( smallTabsStream >> resultIndentationMode );
    BOOST_CHECK( resultIndentationMode == GT::Model::ResultIndentationMode::TABS );
    BOOST_REQUIRE_NO_THROW( largeTabsStream >> resultIndentationMode );
    BOOST_CHECK( resultIndentationMode == GT::Model::ResultIndentationMode::TABS );
    BOOST_REQUIRE_NO_THROW( smallSpacesStream >> resultIndentationMode );
    BOOST_CHECK( resultIndentationMode == GT::Model::ResultIndentationMode::SPACES );
    BOOST_REQUIRE_NO_THROW( largeSpacesStream >> resultIndentationMode );
    BOOST_CHECK( resultIndentationMode == GT::Model::ResultIndentationMode::SPACES );
    BOOST_REQUIRE_NO_THROW( smallNoneStream >> resultIndentationMode );
    BOOST_CHECK( resultIndentationMode == GT::Model::ResultIndentationMode::NONE );
    BOOST_REQUIRE_NO_THROW( largeNoneStream >> resultIndentationMode );
    BOOST_CHECK( resultIndentationMode == GT::Model::ResultIndentationMode::NONE );
    BOOST_REQUIRE_THROW(
        invalidStream >> resultIndentationMode,
        boost::program_options::validation_error
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
