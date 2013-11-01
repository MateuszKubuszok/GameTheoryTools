#ifndef __GT_GTL_PLAYER_STRATEGIES_PROPERTY_HPP__
#define __GT_GTL_PLAYER_STRATEGIES_PROPERTY_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class PlayerStrategiesProperty : public ObjectProperty {
    Player* player;

public:
    PlayerStrategiesProperty(
        Player* describedPlayer
    );

    virtual ResultPtr findForConditions(
        const Context&    context,
        const Conditions& conditions
    );
}; /* END class PlayerStrategiesProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef __GT_GTL_PLAYER_STRATEGIES_PROPERTY_HPP__ */
