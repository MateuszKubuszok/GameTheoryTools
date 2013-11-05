#include "gt/program/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ProgramController )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ProgramController_functional ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    std::string content =
        "FIND type\n"
        "FOR\n"
        "  10,\n"
        "  20.0,\n"
        "  3e1,\n"
        "  4.0e1,\n"
        "  identifier,\n"
        "  PLAYER p { s1, s2 },\n"
        "  STRATEGIC GAME\n"
        "  WITH\n"
        "    PLAYER p1 { s },\n"
        "    PLAYER p2 { s }\n"
        "  SUCH AS\n"
        "    { p1=s, p2=s : 10, 20 }\n"
        "  END,\n"
        "  EXTENSIVE GAME\n"
        "  WITH\n"
        "    PLAYER p1 { s },\n"
        "    PLAYER p2 { s }\n"
        "  SUCH AS\n"
        "    { p1=s :\n"
        "      { p2=s : 10, 20 }\n"
        "    }\n"
        "  END;\n"
    ;
    std::istringstream inputStream(content);
    std::stringstream  outputStream;
    std::stringstream  errorStream;

    // when
    GT::Program::ProgramController controller;
    controller.setCheckingAndExecution();
    controller.setInputStream(&inputStream, false);
    controller.setOutputStream(&outputStream, false);
    controller.setErrorStream(&errorStream, false);

    // then
    BOOST_REQUIRE_EQUAL( controller.run(), 0 );
    BOOST_CHECK_EQUAL(
        outputStream.str(),
        std::string() +
        "type:\n"
        "\t1:\n"
        "\t\tType:\n"
        "\t\t\tParam\n"
        "\t2:\n"
        "\t\tType:\n"
        "\t\t\tParam\n"
        "\t3:\n"
        "\t\tType:\n"
        "\t\t\tParam\n"
        "\t4:\n"
        "\t\tType:\n"
        "\t\t\tParam\n"
        "\t5:\n"
        "\t\tType:\n"
        "\t\t\tParam\n"
        "\t6:\n"
        "\t\tType:\n"
        "\t\t\tPlayer\n"
        "\t7:\n"
        "\t\tType:\n"
        "\t\t\tGame\n"
        "\t8:\n"
        "\t\tType:\n"
        "\t\t\tGame\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
