#include "DecisionMaker.hpp"

#include <iostream>
#include <functional>

using namespace tba;

DecisionMaker::DecisionMaker(character_id _c_id, team_id _t_id, const TeamContainer& teams) 
    : c_id(_c_id), t_id(_t_id), teams_ref(teams) { }


// TODO
Action DecisionMaker::get_action() const {
    return Action(c_id, c_id, ActionType::ATTACK1);
}

void DecisionMaker::set_dm_state(const std::string &input) {
    dm_state = input;
}
