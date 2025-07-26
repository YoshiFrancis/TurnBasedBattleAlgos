#ifndef TBA_DECISION_MAKER_HPP
#define TBA_DECISION_MAKER_HPP

#include "Action.hpp"
#include "Team.hpp"

#include <vector>

namespace tba {

class DecisionMaker {
    private:
        character_id c_id;
        team_id t_id;
        DecisionMakerID d_id;
    public:
        DecisionMaker(character_id _c_id, team_id _t_id, DecisionMakerID _d_id);
        Action get_action(const std::vector<Team>& teams) const;

        bool operator==(const DecisionMaker& other) const;

        inline character_id get_c_id() const { return c_id; }
        inline team_id get_t_id() const { return t_id; }
    private:

};

struct DMAKERHashFunction {
    size_t operator()(const DecisionMaker& dmaker) const;
};

}

#endif
