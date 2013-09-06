#ifndef __GT_GTL_PARAM_HPP__
#define __GT_GTL_PARAM_HPP__

namespace GT {
namespace GTL {
 
////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Abstract class that defines interface for Params. 
 *
 * @author Mateusz Kubuszok
 */   
class Param : public virtual Object {
public:
    /**
     * @brief Default constructor.
     */
    Param();

    /**
     * @brief Returns value for Context.
     *
     * @param context Context with values
     */
    virtual ObjectPtr getObject(
        Context& context
    ) = 0;

    /**
     * @brief Returns value for context.
     *
     * @param context Context with values
     */
    virtual NumberPtr getValue(
        Context& context
    ) = 0;
}; /* END class Param */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Param for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullParam : public virtual Param {
public:
    virtual ObjectPtr getObject(
        Context& context
    ) {
        return NullFactory::getInstance().createObject();
    }

    virtual NumberPtr getValue(
        Context& context
    ) {
        return Model::NullFactory::getInstance().createNumber();
    }

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullParam");
    }
}; /* END class NullParam */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* __GT_GTL_PARAM_HPP__ */
