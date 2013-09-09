#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE RootTest
#include <boost/test/unit_test.hpp>

#include "gt/model/common.hpp"

class RootTestImpl : public virtual GT::Model::Root {
public:
    RootTestImpl() :
        Root()
        {}

    virtual GT::Message toString() {
        return GT::Message("RootTestImpl");
    }
};

BOOST_AUTO_TEST_CASE( testIsEqual ) {
    RootTestImpl root;
    RootTestImpl root2;

    BOOST_CHECK(root.isEqual(root));
    BOOST_CHECK(!root.isEqual(root2));
}

BOOST_AUTO_TEST_CASE( testIsNotNull ) {
    RootTestImpl root;

    BOOST_CHECK(root.isNotNull());
}

BOOST_AUTO_TEST_CASE( testIsNull ) {
    RootTestImpl root;

    BOOST_CHECK(!root.isNull());
}

BOOST_AUTO_TEST_CASE( testToString ) {
    RootTestImpl root;

    BOOST_CHECK_EQUAL(root.toString(), GT::Message("RootTestImpl"));
}
