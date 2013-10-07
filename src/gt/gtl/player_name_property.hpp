#ifndef __GT_GTL_PLAYER_NAME_PROPERTY_HPP__
#define __GT_GTL_PLAYER_NAME_PROPERTY_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

class PlayerNameProperty : public ObjectProperty {
    Player* player;

public:
    PlayerNameProperty(
        Player* describedPlayer
    );

    virtual ResultPtr findForConditions(
        const Context&    context,
        const Conditions& conditions
    );
}; /* END class PlayerNameProperty */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef __GT_GTL_PLAYER_NAME_PROPERTY_HPP__ */
