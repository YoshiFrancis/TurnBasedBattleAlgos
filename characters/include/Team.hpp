#ifndef TBA_TEAM_HPP
#define TBA_TEAM_HPP

#include "Action.hpp"
#include "Character.hpp"

#include <vector>

namespace tba {


class Team {
    private:
        std::vector<Character> characters;
        team_id id;
        std::vector<std::tuple<character_id, DecisionMakerID>> decision_types;

    public:
        Team(std::vector<Character> _characters);
        void set_id(team_id id);

        bool has_living_character() const;
        std::vector<std::tuple<character_id, DecisionMakerID>> get_decision_types() const;

    private:
        std::vector<std::tuple<character_id, DecisionMakerID>> gen_decision_types() const;
};

}

#endif
