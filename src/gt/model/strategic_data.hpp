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
        const PlayersPtr playersDefinitions
    );

    /**
     * @brief Returns Players' definitions.
     *
     * @return Players' definitions
     */
    virtual const PlayersPtr getPlayers() const override;

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positionInStorage Index of positon in payoff storage
     *                          according to PositionsHelper
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual const DataPiecePtr getValues(
        const Index positionInStorage
    ) const;

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positions         Positions in payoff storage
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual const DataPiecePtr getValues(
        const PositionsPtr positions
    ) const override;

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positions         Positions in payoff storage
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual const DataPiecePtr getValues(
        const Positions& positions
    ) const override;

    /**
     * @brief Sets Positions to contains given payoffs.
     *
     * @param positionInStorage Index of position in payoff storage
     * @param numbers           payoffs values
     * @return                  reference to itself for chaining
     * @throw InvalidCoordinate thrown when Index in not in allowed range
     */
    virtual Data& setValues(
        const Index      positionInStorage,
        const NumbersPtr numbers
    );

    /**
     * @brief Sets Positions to contains given payoffs.
     *
     * @param positions         Positions to set
     * @param numbers           payoffs values
     * @return                  reference to itself for chaining
     */
    virtual Data& setValues(
        const Positions& positions,
        const NumbersPtr numbers
    ) override;

    /**
     * @brief Sets Positions to contains given payoffs.
     *
     * @param positions         Positions to set
     * @param numbers           payoffs values
     * @return                  reference to itself for chaining
     */
    virtual Data& setValues(
        const PositionsPtr positions,
        const NumbersPtr   numbers
    ) override;

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positionInStorage Index of positon in payoff storage
     *                          according to PositionsHelper
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual const DataPiecePtr operator[](
        const Index positionInStorage
    ) const;

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positions         Positions in payoff storage
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual const DataPiecePtr operator[](
        const Positions& positions
    ) const override;

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positions         Positions in payoff storage
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual const DataPiecePtr operator[](
        const PositionsPtr positions
    ) const override;

    /**
     * @brief Returns StrategicData Message.
     *
     * @return Message
     */
    virtual Message toString() const override;
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

    virtual const PlayersPtr getPlayers() const override {
        return NullFactory::getInstance().createPlayers();
    }

    virtual const DataPiecePtr getValues(
        const Index
    ) const override {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual const DataPiecePtr getValues(
        const Positions&
    ) const override {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual const DataPiecePtr getValues(
        const PositionsPtr
    ) const override {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual Data& setValues(
        const Index,
        const NumbersPtr
    ) override {
        return *this;
    }

    virtual Data& setValues(
        const Positions&,
        const NumbersPtr
    ) override {
        return *this;
    }

    virtual Data& setValues(
        const PositionsPtr,
        const NumbersPtr
    ) override {
        return *this;
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullStrategicData");
    }

    virtual const DataPiecePtr operator[](
        const Index
    ) const override {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual const DataPiecePtr operator[](
        const Positions&
    ) const override {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual const DataPiecePtr operator[](
        const PositionsPtr
    ) const override {
        return NullFactory::getInstance().createDataPiece();
    }
}; /* END class NullStrategicData */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_STRATEGIC_DATA_HPP__ */
