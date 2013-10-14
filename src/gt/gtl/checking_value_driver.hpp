#ifndef __GT_GTL_CHECKING_VALUE_DRIVER_HPP__
#define __GT_GTL_CHECKING_VALUE_DRIVER_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Implementation used for handling values via CheckingDriver.
 *
 * @author Mateusz Kubuszok
 *
 * @see CheckingDriver
 * @see ValueDriver
 */
class CheckingValueDriver : public ValueDriver {
public:
    /**
     * @brief Creates Param by its name.
     *
     * @param identifier Param's Identifier
     * @return           Param
     */
    virtual ParamPtr* get(
        IdentifierPtr* identifier
    );

    /**
     * @brief Creates Param by its value.
     *
     * @param identifier Param's value
     * @return           Param
     */
    virtual ParamPtr* get(
        NumberPtr* number
    );

    /**
     * @brief Converts passed Game to Object.
     *
     * @param game Game to convert
     * @return     Object
     */
    virtual ObjectPtr* toObject(
        GamePtr* game
    );
    
    /**
     * @brief Converts passed Player to Object.
     *
     * @param player Player to convert
     * @return       Object
     */
    virtual ObjectPtr* toObject(
        PlayerPtr* player
    );

    /**
     * @brief Converts passed Param to Object.
     *
     * @param param Param to convert
     * @return      Object
     */
    virtual ObjectPtr* toObject(
        ParamPtr* param
    );

    /**
     * @brief CheckingValueDriver message.
     *
     * @return message
     */
    virtual Message toString();
}; /* END class CheckingValueDriver */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_CHECKING_VALUE_DRIVER_HPP__ */
