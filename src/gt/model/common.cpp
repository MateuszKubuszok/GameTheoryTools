#include "gt/model/inner_common.hpp"

namespace GT {

////////////////////////////////////////////////////////////////////////////////

bool operator==(
    Messages& messages1,
    Messages& messages2
) {
    if (&messages1 == &messages2)
        return true;
    if (messages1.size() != messages2.size())
        return false;
    for (int i = messages1.size(); i >= 0; i--)
        if (*messages1[i] != *messages2[i])
            return false;
    return true;
}
bool operator!=(
    Messages& messages1,
    Messages& messages2
) {
    return !(messages1 == messages2);
}

// Identifier is identical to Message
// bool operator==(
//     Identifiers& identifier1,
//     Identifiers& identifier2
// ) {
//     if (&identifier1 == &identifier2)
//         return true;
//     if (identifier1.size() != identifier2.size())
//         return false;
//     for (int i = identifier1.size(); i >= 0; i--)
//         if (*identifier1[i] != *identifier2[i])
//             return false;
//     return true;
// }
// bool operator!=(
//     Identifiers& identifier1,
//     Identifiers& identifier2
// ) {
//     return !(identifier1 == identifier2);
// }

bool operator==(
    Numbers& numbers1,
    Numbers& numbers2
) {
    if (&numbers1 == &numbers2)
        return true;
    if (numbers1.size() != numbers2.size())
        return false;
    for (int i = numbers1.size(); i >= 0; i--)
        if (*numbers1[i] != *numbers2[i])
            return false;
    return true;
}
bool operator!=(
    Numbers& numbers1,
    Numbers& numbers2
) {
    return !(numbers1 == numbers2);
}

bool operator==(
    Positions& positions1,
    Positions& positions2
) {
    if (&positions1 == &positions2)
        return true;
    if (positions1.size() != positions2.size())
        return false;
    BOOST_FOREACH(Identifier identifier, positions1 | boost::adaptors::map_keys)
        if (!positions2.count(identifier) || positions1[identifier] != positions2[identifier])
            return false;
    return true;
}
bool operator!=(
    Positions& positions1,
    Positions& positions2
) {
    return !(positions1 == positions2);
}

////////////////////////////////////////////////////////////////////////////////

namespace Model {

////////////////////////////////////////////////////////////////////////////////

bool operator==(
    Players& players1,
    Players& players2
) {
    if (&players1 == &players2)
        return true;
    if (players1.size() != players2.size())
        return false;
    BOOST_FOREACH(Identifier playerName, players1 | boost::adaptors::map_keys)
        if (!players2.count(playerName) || *players1[playerName] != *players2[playerName])
            return false;
    return true;
}
bool operator!=(
    Players& players1,
    Players& players2
) {
    return !(players1 == players2);
}

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GT */
