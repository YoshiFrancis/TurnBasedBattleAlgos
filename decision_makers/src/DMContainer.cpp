#include "DMContainer.hpp"

#include <iostream>

using namespace tba;

DMContainer::DMContainer(const TeamContainer &teams) 
    : teams_ref(teams)
{
    const std::unordered_map<team_id, Team>& teams_map = teams_ref.get_const_map_ref();
    std::for_each(teams_map.begin(), teams_map.end(), [this](auto& p) {
            std::cout << "got team\n"; 
            auto decision_types = p.second.get_decision_types();
            std::cout << "decision_types length: " << decision_types.size() << "\n";
            std::for_each(decision_types.begin(), decision_types.end(), [this, &p](auto& s) {
                    DecisionMakerID dm_id = std::get<1>(s);
                    character_id c_id = std::get<0>(s);
                    std::cout << "setting up c_id: " << c_id << " \n";
                    team_id t_id = p.first;
                    dm_map[std::get<0>(s)] = tba::get_decision_maker(dm_id, c_id, t_id, teams_ref);
                    });
            });
    std::cout << "dm container initialized\n";
}

Action DMContainer::get_action(character_id c_id) const {
    std::cout << "getting action\n";
    return dm_map.at(c_id)->get_action();
}

void DMContainer::set_dm_state(character_id id, const std::string &input) {
    dm_map[id]->set_dm_state(input);
}
