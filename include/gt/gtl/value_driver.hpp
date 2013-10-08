#ifndef __GT_GTL_VALUE_DRIVER_HPP__
#define __GT_GTL_VALUE_DRIVER_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Used for handling values via Driver.
 *
 * @author Mateusz Kubuszok
 */
class ValueDriver : public virtual Root {
public:
    /**
     * @brief Creates Param by its name.
     *
     * @param identifier Param's Identifier
     * @return           Param
     */
    virtual ParamPtr* get(
        IdentifierPtr* identifier
    ) = 0;

    /**
     * @brief Creates Param by its value.
     *
     * @param identifier Param's value
     * @return           Param
     */
    virtual ParamPtr* get(
        NumberPtr* number
    ) = 0;

    /**
     * @brief Converts passed Game to Object.
     *
     * @param game Game to convert
     * @return     Object
     */
    virtual ObjectPtr* toObject(
        GamePtr* game
    ) = 0;
    
    /**
     * @brief Converts passed Player to Object.
     *
     * @param player Player to convert
     * @return       Object
     */
    virtual ObjectPtr* toObject(
        PlayerPtr* player
    ) = 0;

    /**
     * @brief Converts passed Param to Object.
     *
     * @param param Param to convert
     * @return      Object
     */
    virtual ObjectPtr* toObject(
        ParamPtr* param
    ) = 0;

    /**
     * @brief ValueDriver message.
     *
     * @return message
     */
    virtual Message toString() = 0;
}; /* END class ValueDriver */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null ValueDriver for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullValueDriver : public ValueDriver {
public:
    NullValueDriver() :
        ValueDriver()
        {}

    virtual ParamPtr* get(
        IdentifierPtr* identifier
    ) {
        return new ParamPtr(NullFactory::getInstance().createParam());
    }

    virtual ParamPtr* get(
        NumberPtr* number
    ) {
        return new ParamPtr(NullFactory::getInstance().createParam());
    }

    virtual ObjectPtr* toObject(
        GamePtr* game
    ) {
        return new ObjectPtr(NullFactory::getInstance().createObject());
    }
    
    virtual ObjectPtr* toObject(
        PlayerPtr* player
    ) {
        return new ObjectPtr(NullFactory::getInstance().createObject());
    }

    virtual ObjectPtr* toObject(
        ParamPtr* param
    ) {
        return new ObjectPtr(NullFactory::getInstance().createObject());
    }

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullValueDriver");
    }
};

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_VALUE_DRIVER_HPP__ */
