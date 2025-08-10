#include "TestAutoInput.hpp"

#include "dm_helper.hpp"

#include <sstream>
#include <iostream>

using namespace tba;

TestAutoInputDM::TestAutoInputDM(character_id _c_id, team_id _t_id, const TeamContainer& teams) 
    : DecisionMaker(_c_id, _t_id, teams) 
{}

std::optional<Action> TestAutoInputDM::get_action() const {
    std::cout << "getting action str from: " << dm_state << "\n";
    auto [ action, target_c_id ] = dm_helper::parse_acion_str(dm_state);
    std::cout << "got target_c_id: " << target_c_id << "\n";

    std::optional<ActionType> a_type = dm_helper::get_action(action);
    if (a_type == std::nullopt) {
        std::stringstream error;
        error << "Provided an invalid action type: " << action;
        throw std::runtime_error(error.str());
    }

    return Action(c_id, target_c_id, a_type.value());
}
