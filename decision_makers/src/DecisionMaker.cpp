#include "DecisionMaker.hpp"

#include <iostream>
#include <functional>

using namespace tba;



DecisionMaker::DecisionMaker(const Character& c, team_id _t_id, DecisionMakerID _d_id) 
    : character(c), c_id(c.get_id()), t_id(_t_id), d_id(_d_id) 
{}


Action DecisionMaker::get_action(const std::vector<Team>& teams) const {
    return Action(0, 0, ActionType::ATTACK1);
}

bool DecisionMaker::operator==(const DecisionMaker& other) const {
    return c_id == other.c_id && t_id == other.t_id && d_id == other.d_id;
}


void DecisionMaker::set_dm_state(const std::string& input) {
    dm_state = input;
}

struct DMAKERHashFunction
{
    size_t operator()(const DecisionMaker& dmaker) const
    {
        size_t xHash = std::hash<int>()(dmaker.get_c_id());
        size_t yHash = std::hash<int>()(dmaker.get_t_id()) << 1;
        return xHash ^ yHash;
    }
};
