#include "DMContainer.hpp"

using namespace tba;

DMContainer::DMContainer(const TeamContainer &teams) 
    : teams_ref(teams)
{
    const std::unordered_map<team_id, Team>& teams_map = teams_ref.get_const_map_ref();
    std::for_each(teams_map.begin(), teams_map.end(), [this](auto& p) {
            auto decision_types = p.second.get_decision_types();
            std::for_each(decision_types.begin(), decision_types.end(), [this](auto& s) {
                    dm_map[std::get<0>(s)] = tba::get_decision_maker(std::get<1>(s), p.first);
                    });
            });
}

Action DMContainer::get_action(character_id c_id) const {
    return dm_map.at(c_id)->get_action();
}

void DMContainer::set_dm_state(character_id id, const std::string &input) {
    dm_map[id]->set_dm_state(input);
}
