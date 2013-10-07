#include "gt/model/test_common.hpp"

BOOST_AUTO_TEST_SUITE( NullFactory )

BOOST_AUTO_TEST_CASE( NullFactory_createIdentifier ) {
    // given
    // when
    GT::IdentifierPtr result = GT::Model::NullFactory::getInstance().createIdentifier();

    // then
    BOOST_CHECK(result);
}

BOOST_AUTO_TEST_CASE( NullFactory_createIdentifiers ) {
    // given
    // when
    GT::IdentifiersPtr result = GT::Model::NullFactory::getInstance().createIdentifiers();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->empty());
}

BOOST_AUTO_TEST_CASE( NullFactory_createMessage ) {
    // given
    // when
    GT::MessagePtr result = GT::Model::NullFactory::getInstance().createMessage();

    // then
    BOOST_CHECK(result);
}

BOOST_AUTO_TEST_CASE( NullFactory_createMessages ) {
    // given
    // when
    GT::MessagesPtr result = GT::Model::NullFactory::getInstance().createMessages();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->empty());
}

BOOST_AUTO_TEST_CASE( NullFactory_createNumber ) {
    // given
    // when
    GT::NumberPtr result = GT::Model::NullFactory::getInstance().createNumber();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK((*result) == 0);
}

BOOST_AUTO_TEST_CASE( NullFactory_createNumbers ) {
    // given
    // when
    GT::NumbersPtr result = GT::Model::NullFactory::getInstance().createNumbers();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->empty());
}

BOOST_AUTO_TEST_CASE( NullFactory_createPlayer ) {
    // given
    // when
    GT::Model::PlayerPtr result = GT::Model::NullFactory::getInstance().createPlayer();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->isNull());
    BOOST_CHECK(!result->isNotNull());
}

BOOST_AUTO_TEST_CASE( NullFactory_createPlayers ) {
    // given
    // when
    GT::Model::PlayersPtr result = GT::Model::NullFactory::getInstance().createPlayers();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->empty());
}

BOOST_AUTO_TEST_CASE( NullFactory_createData ) {
    // given
    // when
    GT::Model::DataPtr result = GT::Model::NullFactory::getInstance().createData();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->isNull());
    BOOST_CHECK(!result->isNotNull());
}

BOOST_AUTO_TEST_CASE( NullFactory_createDataAccessor ) {
    // given
    // when
    GT::Model::DataAccessorPtr result = GT::Model::NullFactory::getInstance().createDataAccessor();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->isNull());
    BOOST_CHECK(!result->isNotNull());
}

BOOST_AUTO_TEST_CASE( NullFactory_createDataPiece ) {
    // given
    // when
    GT::Model::DataPiecePtr result = GT::Model::NullFactory::getInstance().createDataPiece();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->isNull());
    BOOST_CHECK(!result->isNotNull());
}

BOOST_AUTO_TEST_CASE( NullFactory_createDataBuilder ) {
    // given
    // when
    GT::Model::DataBuilderPtr result = GT::Model::NullFactory::getInstance().createDataBuilder();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->isNull());
    BOOST_CHECK(!result->isNotNull());
}

BOOST_AUTO_TEST_CASE( NullFactory_createGame ) {
    // given
    // when
    GT::Model::GamePtr result = GT::Model::NullFactory::getInstance().createGame();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->isNull());
    BOOST_CHECK(!result->isNotNull());
}

BOOST_AUTO_TEST_CASE( NullFactory_createGameBuilder ) {
    // given
    // when
    GT::Model::GameBuilderPtr result = GT::Model::NullFactory::getInstance().createGameBuilder();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->isNull());
    BOOST_CHECK(!result->isNotNull());
}

BOOST_AUTO_TEST_CASE( NullFactory_createResult ) {
    // given
    // when
    GT::Model::ResultPtr result = GT::Model::NullFactory::getInstance().createResult();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->isNull());
    BOOST_CHECK(!result->isNotNull());
}

BOOST_AUTO_TEST_CASE( NullFactory_createResultBuilder ) {
    // given
    // when
    GT::Model::ResultBuilderPtr result = GT::Model::NullFactory::getInstance().createResultBuilder();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->isNull());
    BOOST_CHECK(!result->isNotNull());
}

BOOST_AUTO_TEST_SUITE_END()
