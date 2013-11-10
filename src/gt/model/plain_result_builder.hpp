#ifndef __GT_MODEL_PLAIN_RESULT_BUILDER_HPP__
#define __GT_MODEL_PLAIN_RESULT_BUILDER_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Builder used for creating Results displayed to user in plain user-friendly format.
 *
 * <p>Implements ResultBuilder interface via AbstractResultBuilder class.</p>
 *
 * <p>Used when ResultFactory's BuilderMode is set to PLAIN.</p>

 * <p>Indentation depends on ResultFactory's IndentationMode.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see ResultBuilder
 * @see AbstractResultBuilder
 * @see ResultFactory#buildResult()
 */
class PlainResultBuilder : public AbstractResultBuilder {
public:
    /**
     * @brief Constructor initiating class with indentation.
     *
     * @param indentation sequence used for indentation
     */
    explicit PlainResultBuilder(
        const Message indentation
    );

    /**
     * @brief Build Result.
     *
     * @return                  Result
     * @throw IllegalInnerState thrown when number of Messages for any Object does not match properties' one
     *
     * @see #buildRaw()
     */
    virtual ResultPtr build() const override;

    /**
     * @brief Build raw Result - one that can be inserted into other results.
     *
     * @return                  Result
     * @throw IllegalInnerState thrown when number of Messages for any Object does not match properties' one
     *
     * @see #build()
     */
    virtual ResultPtr buildRaw() const override;
}; /* END class PlainResultBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_PLAIN_RESULT_BUILDER_HPP__ */
