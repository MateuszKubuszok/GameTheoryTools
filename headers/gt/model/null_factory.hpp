#ifndef __GT_MODEL_NULL_FACTORY_HPP__
#define __GT_MODEL_NULL_FACTORY_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Used for creation of Null instances for GTL classes.
 *
 * @author Mateusz Kubuszok
 */
class NullFactory {
    /**
     * @brief Contains pointer to a NullFactory instance.
     */
    static NullFactory volatile *instance;

public:
    /**
     * @brief Returns the instance of a NullFactory.
     *
     * @return ConditionFactory instance
     */
    static NullFactory& getInstance();

    /**
     * @brief Creates null Identifier.
     *
     * @result null Identifier
     */
    IdentifierPtr createIdentifier();

    /**
     * @brief Creates null Message.
     *
     * @result null Message
     */
    MessagePtr createMessage();

    /**
     * @brief Creates NullNumber.
     *
     * @result NullNumber
     */
    NumberPtr createNumber();
    
    /**
     * @brief Creates NullPlayer.
     *
     * @result NullPlayer
     */
    PlayerPtr createPlayer();

    /**
     * @brief Creates NullResult.
     *
     * @result NullNumber
     */
    ResultPtr createResult();

private:
    /**
     * @brief Default constructor hidden from programmers.
     */
    NullFactory();

    /**
     * @brief Default copy constructor hidden from programmers.
     *
     * @param object to copy
     */
    NullFactory(
        const NullFactory& nullFactory
    );

    /**
     * @brief Default destructor hidden from programmers.
     */
    ~NullFactory();
}; /* END class NullFactory */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* END #ifndef __GT_MODEL_NULL_FACTORY_HPP__ */
