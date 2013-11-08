#ifndef __GT_MODEL_STRATEGIC_DATA_HPP__
#define __GT_MODEL_STRATEGIC_DATA_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Contins data specific for Game in a strategic form.
 *
 * <p>Games in this form should have all coordinates filled with payoffs. Since all Players and their
 * strategies are known beforehand, positions can also be hashed to Indexes with PositionsHelper.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see DataAccessor
 * @see Data
 * @see DataPiece
 * @see StrategicDataAccessor
 * @see StrategicDataPiece
 * @see StrategicDataBuilder
 * @see PositionsHelper
 */
class StrategicData : public Data {
    /**
     * @brief PositionsHelper used to calculate positions in storage vector.
     */
    PositionsHelper positionsHelper;

    /**
     * @brief Contains Payoff - indexes can be calculated with PostionsHelper.
     */
    boost::container::vector<NumbersPtr> payoffStorage;
    /**
     * @brief Contains information whether or not some storage poition is already used.
     */
    boost::container::vector<bool>       payoffStorageAllocation;

public:
    /**
     * @brief Initiates Data with Players' definitions.
     *
     * @param playersDefinitions Players' definitions
     */
    explicit StrategicData(
        PlayersPtr playersDefinitions
    );

    /**
     * @brief Returns Players' definitions.
     *
     * @return Players' definitions
     */
    virtual PlayersPtr getPlayers() override;

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positionInStorage Index of positon in payoff storage
     *                          according to PositionsHelper
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual DataPiecePtr getValues(
        Index positionInStorage
    );

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positions         Positions in payoff storage
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual DataPiecePtr getValues(
        PositionsPtr positions
    ) override;

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positions         Positions in payoff storage
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual DataPiecePtr getValues(
        Positions& positions
    );

    /**
     * @brief Sets Positions to contains given payoffs.
     *
     * @param positionInStorage Index of position in payoff storage
     * @param numbers           payoffs values
     * @return                  reference to itself for chaining
     * @throw InvalidCoordinate thrown when Index in not in allowed range
     */
    virtual Data& setValues(
        Index      positionInStorage,
        NumbersPtr numbers
    );

    /**
     * @brief Sets Positions to contains given payoffs.
     *
     * @param positions         Positions to set
     * @param numbers           payoffs values
     * @return                  reference to itself for chaining
     */
    virtual Data& setValues(
        Positions& positions,
        NumbersPtr numbers
    ) override;

    /**
     * @brief Sets Positions to contains given payoffs.
     *
     * @param positions         Positions to set
     * @param numbers           payoffs values
     * @return                  reference to itself for chaining
     */
    virtual Data& setValues(
        PositionsPtr positions,
        NumbersPtr   numbers
    ) override;

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positionInStorage Index of positon in payoff storage
     *                          according to PositionsHelper
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual DataPiecePtr operator[](
        Index positionInStorage
    );

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positions         Positions in payoff storage
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual DataPiecePtr operator[](
        Positions& positions
    ) override;

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positions         Positions in payoff storage
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual DataPiecePtr operator[](
        PositionsPtr positions
    ) override;

    /**
     * @brief Returns StrategicData Message.
     *
     * @return Message
     */
    virtual Message toString() override;
}; /* END class StrategicData */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null StrategicData for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullStrategicData : public StrategicData {
public:
    NullStrategicData() :
        StrategicData(NullFactory::getInstance().createPlayers())
        {}

    virtual PlayersPtr getPlayers() override {
        return NullFactory::getInstance().createPlayers();
    }

    virtual DataPiecePtr getValues(
        Index
    ) override {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual DataPiecePtr getValues(
        Positions&
    ) override {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual DataPiecePtr getValues(
        PositionsPtr
    ) override {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual Data& setValues(
        Index,
        NumbersPtr
    ) override {
        return *this;
    }

    virtual Data& setValues(
        Positions&,
        NumbersPtr
    ) override {
        return *this;
    }

    virtual Data& setValues(
        PositionsPtr,
        NumbersPtr
    ) override {
        return *this;
    }

    virtual DataPiecePtr operator[](
        Index
    ) override {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual DataPiecePtr operator[](
        Positions&
    ) override {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual DataPiecePtr operator[](
        PositionsPtr
    ) override {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual bool isNotNull() override {
        return false;
    }

    virtual Message toString() override {
        return Message("NullStrategicData");
    }
}; /* END class NullStrategicData */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_STRATEGIC_DATA_HPP__ */
