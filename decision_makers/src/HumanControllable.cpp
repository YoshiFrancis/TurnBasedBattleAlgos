#include "HumanControllable.hpp"

#include "dm_helper.hpp"

#include <iostream>
#include <string>

using namespace tba;

HumanControllable::HumanControllable(character_id _c_id, team_id _t_id, const TeamContainer& teams) : DecisionMaker(_c_id, _t_id, teams) { }

std::optional<Action> HumanControllable::get_action() const {
    const Character& c = get_character();
    if (!c.is_alive())
        return std::nullopt;

    while (true) {
        std::cout << "humancontrollable input for c_id: " << c_id << "\n";
        std::cout << "Enter <ActionType> <c_id>: ";
        std::string input;
        std::getline(std::cin, input);
        auto [ action_str, target_c_id ] = dm_helper::parse_acion_str(input);
        std::cout << "actionstr: " << action_str << " | " << target_c_id << "\n";

        std::optional<ActionType> action_type_opt = dm_helper::get_action(action_str);
        if (action_type_opt == std::nullopt)  {
            std::cout << "input invalid action type: " << action_str << "\n";
            continue;
        }

        std::cout << "\n";

        return Action(c_id, target_c_id, action_type_opt.value());
    }
}
