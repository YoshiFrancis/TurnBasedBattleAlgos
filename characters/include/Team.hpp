#ifndef TBA_TEAM_HPP
#define TBA_TEAM_HPP

#include "Action.hpp"

#include <vector>

namespace tba {
    class Team {
        private:
            int id;

        public:
            bool has_living_character() const;
            void set_id(size_t id);

            std::vector<Action> get_actions(const std::vector<Team>& teams);
        private:
    };
}

#endif
