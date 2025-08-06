#include "TeamContainer.hpp"

#include <nlohmann/json.hpp>

#include <cassert>
#include <fstream>
#include <iostream>

using namespace tba;
using json = nlohmann::json;

std::optional<std::list<Team>>
tba::load_teams_file(const std::string &file_path) {
  try {
    std::ifstream f(file_path);
    if (!f.is_open()) {
      std::cout << "could not open file\n";
      return std::nullopt;
    }
    json all_data = json::parse(f);
    std::list<Team> team_list;
    for (size_t i = 0; i < all_data.size(); ++i) {
      json curr_team_data = all_data[i];
      team_list.emplace_back(curr_team_data);
    }
    return team_list;
  } catch (std::exception &e) {
    std::cout << "error loading teams file: " << e.what() << "\n";
    return std::nullopt;
  }
}

TeamContainer::TeamContainer(std::list<Team> teams) {
  team_id curr_id = 0;
  std::for_each(teams.begin(), teams.end(), [this, &curr_id](auto &Team) {
    teams_map[curr_id++] = std::move(Team);
  });
}

const std::unordered_map<team_id, Team>
TeamContainer::get_const_map_ref() const {
  return teams_map;
}

std::unordered_map<team_id, Team> TeamContainer::get_map_ref() {
  return teams_map;
}

const Team &TeamContainer::get_const_team_ref(team_id id) const {
  return teams_map.at(id);
}

Team &TeamContainer::get_team_ref(team_id id) { return teams_map[id]; }
