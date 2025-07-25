#ifndef TBA_CHARACTER_HPP
#define TBA_CHARACTER_HPP

#include "Action.hpp"

#include <vector>

namespace tba {

class Team;

class Character {

    public:
        Action get_action(const std::vector<Team> teams);
        bool is_alive() const;
};

}

#endif
