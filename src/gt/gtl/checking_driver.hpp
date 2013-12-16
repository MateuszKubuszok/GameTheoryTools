#ifndef __GT_GTL_CHECKING_DRIVER_HPP__
#define __GT_GTL_CHECKING_DRIVER_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Implementation used for executing only checking actions.
 *
 * <p>Performs only syntax/type checking on input stream.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see Driver
 */
class CheckingDriver final : public Driver {
    /**
     * @brief Driver for Coordinates.
     */
    mutable CheckingCoordinateDriver               coordinate;
    /**
     * @brief Driver for Coordinates' collections.
     */
    mutable CollectionsDriver<GT::GTL::Coordinate> coordinates;
    /**
     * @brief Driver for Conditions.
     */
    mutable CheckingConditionDriver                condition;
    /**
     * @brief Driver for Conditions' collections.
     */
    mutable CollectionsDriver<GT::GTL::Condition>  conditions;
    /**
     * @brief Driver for Games.
     */
    mutable CheckingGameDriver                     game;
    /**
     * @brief Driver for Identifiers' collections.
     */
    mutable CollectionsDriver<GT::Identifier>      identifiers;
    /**
     * @brief Driver for Objects' collections.
     */
    mutable CollectionsDriver<GT::GTL::Object>     objects;
    /**
     * @brief Driver for Params' collections.
     */
    mutable CollectionsDriver<GT::GTL::Param>      params;
    /**
     * @brief Driver for values.
     */
    mutable CheckingValueDriver                    value;
    /**
     * @brief Driver for statements.
     */
    mutable CheckingStatementDriver                statement;

    /**
     * @brief Error stream for displaying informations about errors.
     */
    mutable OutputStream*                          errorStream;

public:
    /**
     * @brief Initiates CheckingDriver with a output stream.
     *
     * @param errorStream error stream
     */
    explicit CheckingDriver(
        OutputStream* errorStream
    );

    /**
     * @brief Destructor.
     */
    virtual ~CheckingDriver();

    /**
     * @brief Driver for Coordinate.
     *
     * @return CoordinateDriver
     */
    virtual CoordinateDriver& forCoordinate() const override;

    /**
     * @brief Driver for Coordinates.
     *
     * @return CollectionDriver for Coordinates
     */
    virtual CollectionsDriver<Coordinate>& forCoordinates() const override;

    /**
     * @brief Driver for Condition.
     *
     * @return ConditionDriver
     */
    virtual ConditionDriver& forCondition() const override;

    /**
     * @brief Driver for Conditions.
     *
     * @return CollectionDriver for Conditions
     */
    virtual CollectionsDriver<Condition>& forConditions() const override;

    /**
     * @brief Driver for Game.
     *
     * @return GameDriver
     */
    virtual GameDriver& forGame() const override;

    /**
     * @brief Driver for Identifiers.
     *
     * @return CollectionDriver for Identifiers
     */
    virtual CollectionsDriver<Identifier>& forIdentifiers() const override;

    /**
     * @brief Driver for Objects.
     *
     * @return CollectionDriver for Objects
     */
    virtual CollectionsDriver<Object>& forObjects() const override;

    /**
     * @brief Driver for Params.
     *
     * @return CollectionDriver for Params
     */
    virtual CollectionsDriver<Param>& forParams() const override;

    /**
     * @brief Driver for value.
     *
     * @return ValueDriver
     */
    virtual ValueDriver& forValue() const override;

    /**
     * @brief Driver for Statement.
     *
     * @return StatementDriver
     */
    virtual StatementDriver& forStatement() const override;

    /**
     * @brief Displays results.
     *
     * @param result Result to show
     */
    virtual void showResult(
        const ResultPtr result
    ) const override;

    /**
     * @brief Displays error.
     *
     * @param location error's location
     * @param message  Message to display
     */
    virtual void showError(
        const InputLocation& location,
        const Message&       message
    ) const override;

    /**
     * @brief Displays error.
     *
     * @param symbol invalid symbol to display
     */
    virtual void showError(
        const ValidableSymbol& symbol
    ) const override;

    /**
     * @brief Driver's Message.
     *
     * @return message
     */
    virtual Message toString() const override;
}; /* END class CheckingDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_CHECKING_DRIVER_HPP__ */
