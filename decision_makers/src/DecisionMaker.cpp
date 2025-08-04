#include "DecisionMaker.hpp"

#include <iostream>
#include <functional>

using namespace tba;

DecisionMaker::DecisionMaker(const TeamContainer& teams) 
    : teams_ref(teams)
{
    const std::unordered_map<team_id, Team>& teams_map = teams_ref.get_const_map_ref();
    std::for_each(teams_map.begin(), teams_map.end(), [this](auto& p) {
            auto decision_types = p.second.get_decision_types();
            std::for_each(decision_types.begin(), decision_types.end(), [this](auto& s) {
                    dm_map[std::get<0>(s)] = std::get<1>(s);
                    });
            });
}

Action DecisionMaker::get_action(team_id t_id, character_id c_id) const {
    return Action(c_id, c_id, ActionType::ATTACK1);
}

void DecisionMaker::set_dm_state(character_id id, const std::string &input) {
    dm_state_map[id] = input;
}
