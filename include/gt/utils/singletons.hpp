#ifndef __GT_UTILS_SINGLETONS_HPP__
#define __GT_UTILS_SINGLETONS_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Macro for declaring singletons.
 *
 * <p>Intended to be used like:</p>
 *
 * <p><pre>
 * class SingletonImplementation {
 *
 * SINGLETON_DECLARATION(SingletonImplementation)
 *
 * public:
 *     SingletonImplementation& getInstance();
 *
 * private:
 *     SingletonImplementation();
 *
 *     SingletonImplementation(const SingletonImplementation*);
 *
 *     ~SingletonImplementation();
 * };
 * </pre></p>
 *
 * @param SINGLETON_NAME name of declared singleton
 */
#define SINGLETON_DECLARATION(SINGLETON_NAME) \
    static std::unique_ptr<SINGLETON_NAME, void (*)(SINGLETON_NAME*)> instance; \
    \
    static void deleter( \
        SINGLETON_NAME* singleton \
    );

/**
 * @brief Macro for defining singletons.
 *
 * <p>Intended to be used like:</p>
 *
 * <p><pre>
 * // class SingletonImplementation {
 *
 * SINGLETON_DEFINITION(SingletonImplementation, getInstance)
 *
 * // public:
 *
 * // methods implementations
 *
 * // private:
 *
 * SingletonImplementation::SingletonImplementation() {}
 *
 * SingletonImplementation::~SingletonImplementation() {}
 *
 * // }
 * </pre></p>
 *
 * @param SINGLETON_NAME    name of defined singleton
 * @param GET_INSTANCE_NAME name of getInstance method
 * @param MUTEX_NAME        name of mutex to generate
 */
#define SINGLETON_DEFINITION(SINGLETON_NAME,GET_INSTANCE_NAME,MUTEX_NAME) \
    boost::mutex MUTEX_NAME; \
    \
    std::unique_ptr<SINGLETON_NAME, void (*)(SINGLETON_NAME*)> \
        SINGLETON_NAME::instance(nullptr, &deleter); \
    \
    SINGLETON_NAME& SINGLETON_NAME::GET_INSTANCE_NAME() { \
        if (!instance) { \
            boost::mutex::scoped_lock lock(MUTEX_NAME); \
            if (!instance) \
                instance = decltype(instance)(new SINGLETON_NAME(), &deleter); \
        } \
        return *instance; \
    } \
    \
    void SINGLETON_NAME::deleter( \
        SINGLETON_NAME* singleton \
    ) { \
        delete singleton; \
    }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif /* #define __GT_UTILS_SINGLETONS_HPP__ */
