#ifndef TBA_TEAM_HPP
#define TBA_TEAM_HPP

#include "Action.hpp"
#include "Character.hpp"

#include <vector>

namespace tba {
    class Team {
        private:
            std::vector<Character> characters;
            int id;

        public:
            bool has_living_character() const;
            void set_id(size_t id);

            std::vector<Action> get_actions(const std::vector<Team>& teams);
        private:
    };
}

#endif
