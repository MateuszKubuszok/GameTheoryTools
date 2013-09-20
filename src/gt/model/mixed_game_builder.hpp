#ifndef __GT_MODEL_MIXED_GAME_BUILDER_HPP__
#define __GT_MODEL_MIXED_GAME_BUILDER_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class MixedGameBuilder : public PlainGameBuilder {
public:
    virtual GamePtr build();

    virtual Message toString();
}; /* END class MixedGameBuilder */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_MIXED_GAME_BUILDER_HPP__ */
