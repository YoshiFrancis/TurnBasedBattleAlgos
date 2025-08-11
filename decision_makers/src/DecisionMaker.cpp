#include "DecisionMaker.hpp"

#include <functional>

using namespace tba;

DecisionMaker::DecisionMaker(character_id _c_id, team_id _t_id, const TeamContainer& teams) 
    : c_id(_c_id), t_id(_t_id), teams_ref(teams) { }


// TODO
std::optional<Action> DecisionMaker::get_action() const {
    return Action(c_id, c_id, ActionType::ATTACK1);
}

void DecisionMaker::set_dm_state(const std::string &input) {
    dm_state = input;
}

const Character& DecisionMaker::get_character() const {
    const Team& t = teams_ref.get_const_team_ref(t_id);
    const Character& c = t.get_const_character(c_id);
    return c;
}
