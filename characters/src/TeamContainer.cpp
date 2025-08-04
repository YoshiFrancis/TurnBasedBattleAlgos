#include "TeamContainer.hpp"

#include <list>
#include <cassert>

using namespace tba;

std::list<Team> tba::load_teams_file(const std::string& file_path) {
    assert(false && "loading teams file not implemented");
    return {};
}

TeamContainer::TeamContainer(std::list<Team> teams) {
    team_id curr_id = 0;
    std::for_each(teams.begin(), teams.end(), [this, &curr_id](auto& Team) {
            teams_map[curr_id++] = std::move(Team);
            });
}

const std::unordered_map<team_id, Team> TeamContainer::get_const_map_ref() const {
    return teams_map;
}

std::unordered_map<team_id, Team> TeamContainer::get_map_ref() {
    return teams_map;
}

const Team& TeamContainer::get_const_team_ref(team_id id) const {
    return teams_map.at(id);
}

Team& TeamContainer::get_team_ref(team_id id) {
    return teams_map[id];
}
