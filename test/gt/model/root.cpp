#include "gt/model/test_common.hpp"

BOOST_AUTO_TEST_SUITE( Root )

class RootTestImpl : public virtual GT::Model::Root {
public:
    RootTestImpl() :
        Root()
        {}

    virtual GT::Message toString() {
        return GT::Message("RootTestImpl");
    }
}; /* END class RootTestImpl */

BOOST_AUTO_TEST_CASE( Root_isEqual ) {
    // given

    // when
    RootTestImpl root;
    RootTestImpl root2;

    // then
    BOOST_CHECK(root.isEqual(root));
    BOOST_CHECK(!root.isEqual(root2));
}

BOOST_AUTO_TEST_CASE( Root_isNotNull ) {
    // given

    // when
    RootTestImpl root;

    // then
    BOOST_CHECK(root.isNotNull());
}

BOOST_AUTO_TEST_CASE( Root_isNull ) {
    // given

    // when
    RootTestImpl root;

    // then
    BOOST_CHECK(!root.isNull());
}

BOOST_AUTO_TEST_CASE( Root_toString ) {
    // given

    // when
    RootTestImpl root;

    // then
    BOOST_CHECK_EQUAL(
        root.toString(),
        GT::Message("RootTestImpl")
    );
}

BOOST_AUTO_TEST_SUITE_END()
