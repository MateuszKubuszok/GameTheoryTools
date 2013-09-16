#ifndef __GT_MODEL_PURE_GAME_BUILDER_HPP__
#define __GT_MODEL_PURE_GAME_BUILDER_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class PureGameBuilder : public PlainGameBuilder {
public:
    virtual GamePtr build();

    virtual Message toString();
}; /* END class PureGameBuilder */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_PURE_GAME_BUILDER_HPP__ */
