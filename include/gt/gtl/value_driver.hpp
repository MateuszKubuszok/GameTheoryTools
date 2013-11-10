#ifndef __GT_GTL_VALUE_DRIVER_HPP__
#define __GT_GTL_VALUE_DRIVER_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
     * @param inputLocation input location of created Param
     * @param identifier    Param's Identifier
     * @return              Param
     */
    virtual ParamPtr* get(
        const InputLocation& inputLocation,
        const IdentifierPtr* identifier
    ) const = 0;

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
    ) const = 0;

    /**
     * @brief Converts passed Game to Object.
     *
     * @param game Game to convert
     * @return     Object
     */
    virtual ObjectPtr* toObject(
        const GamePtr* game
    ) const = 0;

    /**
     * @brief Converts passed Player to Object.
     *
     * @param player Player to convert
     * @return       Object
     */
    virtual ObjectPtr* toObject(
        const PlayerPtr* player
    ) const = 0;

    /**
     * @brief Converts passed Param to Object.
     *
     * @param param Param to convert
     * @return      Object
     */
    virtual ObjectPtr* toObject(
        const ParamPtr* param
    ) const = 0;

    /**
     * @brief ValueDriver message.
     *
     * @return message
     */
    virtual Message toString() const override = 0;
}; /* END class ValueDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
        const InputLocation& inputLocation,
        const IdentifierPtr*
    ) const override {
        return new ParamPtr(
            setupLocation<Param>(
                NullFactory::getInstance().createParam(),
                inputLocation
            )
        );
    }

    virtual ParamPtr* get(
        const GT::GTL::InputLocation& inputLocation,
        const NumberPtr*
    ) const override {
        return new ParamPtr(
            setupLocation<Param>(
                NullFactory::getInstance().createParam(),
                inputLocation
            )
        );
    }

    virtual ObjectPtr* toObject(
        const GamePtr*
    ) const override {
        return new ObjectPtr(NullFactory::getInstance().createObject());
    }

    virtual ObjectPtr* toObject(
        const PlayerPtr*
    ) const override {
        return new ObjectPtr(NullFactory::getInstance().createObject());
    }

    virtual ObjectPtr* toObject(
        const ParamPtr*
    ) const override {
        return new ObjectPtr(NullFactory::getInstance().createObject());
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullValueDriver");
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_VALUE_DRIVER_HPP__ */
