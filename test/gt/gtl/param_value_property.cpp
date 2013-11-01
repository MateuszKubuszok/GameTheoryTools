#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ParamValueProperty )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ParamValueProperty_findForConditions ) {
    // given
    GT::GTL::ContextPtr    contextPtr    = GT::GTL::NullFactory::getInstance().createContext();
    GT::GTL::Context       context       = *contextPtr;
    GT::GTL::ConditionsPtr conditionsPtr = GT::GTL::NullFactory::getInstance().createConditions();
    GT::GTL::Conditions    conditions    = *conditionsPtr;

    GT::NumberPtr        number = GT::Model::NullFactory::getInstance().createNumber();
    GT::GTL::NumberParam numberParam(number);
    GT::GTL::ObjectPtr   object = GT::GTL::NullFactory::getInstance().createObject();
    GT::GTL::ObjectParam objectParam(object);

    // when
    GT::GTL::ParamValueProperty numberValueProperty(&numberParam);
    GT::GTL::ParamValueProperty objectValueProperty(&objectParam);

    // then
    BOOST_CHECK_EQUAL(
        numberValueProperty.findForConditions(context, conditions)->getResult(),
        numberParam.toString()
    );
    BOOST_CHECK_EQUAL(
        objectValueProperty.findForConditions(context, conditions)->getResult(),
        objectParam.toString()
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
