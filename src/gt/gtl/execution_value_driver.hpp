#ifndef __GT_GTL_EXECUTION_VALUE_DRIVER_HPP__
#define __GT_GTL_EXECUTION_VALUE_DRIVER_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Implementation used for handling values via ExecutionDriver.
 *
 * <p>Performs actual execution of instructions for values.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see ExecutionDriver
 * @see ValueDriver
 */
class ExecutionValueDriver final : public ValueDriver {
    /**
     * @brief Driver for error handling.
     */
    CheckingValueDriver checkingValueDriver;
    /**
     * @brief Implementation of a main Driver.
     */
    Driver*             driver;

public:
    /**
     * @brief Initiates ExecutionValueDriver with its parent.
     *
     * @param parentDriver parent Driver
     */
    explicit ExecutionValueDriver(
        Driver* parentDriver
    );

    /**
     * @brief Creates Param by its name.
     *
     * @param inputLocation input location of created Param
     * @param identifier    Param's Identifier
     * @return              Param
     */
    virtual ParamPtr* get(
        const InputLocation& inputLocation,
        const IdentifierPtr* identifier
    ) const override;

    /**
     * @brief Creates Param by its value.
     *
     * @param inputLocation input location of created Param
     * @param identifier    Param's value
     * @return              Param
     */
    virtual ParamPtr* get(
        const InputLocation& inputLocation,
        const NumberPtr*     number
    ) const override;

    /**
     * @brief Converts passed Game to Object.
     *
     * @param game Game to convert
     * @return     Object
     */
    virtual ObjectPtr* toObject(
        const GamePtr* game
    ) const override;

    /**
     * @brief Converts passed Player to Object.
     *
     * @param player Player to convert
     * @return       Object
     */
    virtual ObjectPtr* toObject(
        const PlayerPtr* player
    ) const override;

    /**
     * @brief Converts passed Param to Object.
     *
     * @param param Param to convert
     * @return      Object
     */
    virtual ObjectPtr* toObject(
        const ParamPtr* param
    ) const override;

    /**
     * @brief ExecutionValueDriver message.
     *
     * @return message
     */
    virtual Message toString() const override;
}; /* END class ExecutionValueDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_EXECUTION_VALUE_DRIVER_HPP__ */
