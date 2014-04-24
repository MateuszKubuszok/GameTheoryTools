#ifndef GT_GTL_DETAILS_HPP_INCLUDED
#define GT_GTL_DETAILS_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/details.hpp
 * @brief     Defines GT::GTL::Details class.
 * @copyright (C) 2013-2014
 * @author    Mateusz Kubuszok
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero
 * General Public License as published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this program. If not,
 * see [http://www.gnu.org/licenses/].
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class Details
 * @brief Contains Coordinates as well as defined Players.
 *
 * Contains information about Players and Coordinates that will be used to build data.
 *
 * @author Mateusz Kubuszok
 *
 * @see GameDriver
 * @see Parser
 */
class Details : public virtual ValidableSymbol {
    /**
     * @brief Players' collection.
     */
    const ObjectsPtr players;

    /**
     * @brief Coordinates' collection.
     */
    const CoordinatesPtr coordinates;

public:
    /**
     * @brief Constructor for Players with data.
     *
     * @param playersDetails     declared players
     * @param coordinatesDetails declared data
     */
    Details(
        const ObjectsPtr     playersDetails,
        const CoordinatesPtr coordinatesDetails
    );

    /**
     * @brief Returns Coordinates with data.
     *
     * @return Coordinates wit data
     */
    virtual const CoordinatesPtr getCoordinates() const;

    /**
     * @brief Returns Players definitions.
     *
     * @return Players definitions
     */
    virtual const ObjectsPtr getPlayers() const;

    /**
     * @brief Returns Message about Game details.
     *
     * @return Game Details Message
     */
    virtual Message toString() const override;
}; /* END class Details */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class NullDetails
 * @brief Null Details for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullDetails final : public Details {
public:
    NullDetails() :
        Details(
            NullFactory::getInstance().createObjects(),
            NullFactory::getInstance().createCoordinates()
        )
        {}

    virtual const CoordinatesPtr getCoordinates() const override {
        return NullFactory::getInstance().createCoordinates();
    }

    virtual const ObjectsPtr getPlayers() const override {
        return NullFactory::getInstance().createObjects();
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullDetails");
    }
}; /* END class NullDetails */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class ErrorDetails
 * @brief Error Details for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class ErrorDetails final : public Details {
    /**
     * @brief Error message.
     */
    const Message message;

public:
    ErrorDetails(
        const Message errorMessage
    ) :
        Details(
            NullFactory::getInstance().createObjects(),
            NullFactory::getInstance().createCoordinates()
        ),
        message(errorMessage)
        {}

    virtual const CoordinatesPtr getCoordinates() const override {
        return NullFactory::getInstance().createCoordinates();
    }

    virtual const ObjectsPtr getPlayers() const override {
        return NullFactory::getInstance().createObjects();
    }

    virtual bool isValid() const override {
        return false;
    }

    virtual Message toString() const override {
        return message;
    }
}; /* END class ErrorDetails */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef GT_GTL_DETAILS_HPP_INCLUDED */
