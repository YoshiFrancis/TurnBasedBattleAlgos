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
      team_list.back().set_id(i);
    }
    return team_list;
  } catch (std::exception &e) {
    std::cout << "error loading teams file: " << e.what() << "\n";
    return std::nullopt;
  }
}

TeamContainer::TeamContainer(std::list<Team> teams) 
    : count(teams.size()) {
        std::cout << "tc initializing\n";
        team_id curr_id = 0;
        std::for_each(teams.begin(), teams.end(), [this, &curr_id](Team& team) {
                team.set_id(curr_id);
                auto characters = team.get_characters();
                std::for_each(characters.begin(), characters.end(), [this, curr_id](auto& c) {
                        character_id c_id = c.get_id();
                        characters_map[c_id] = curr_id;
                        });
                teams_map[curr_id++] = std::move(team);
                });
}

size_t TeamContainer::size() const {
    return count;
}

size_t TeamContainer::alive_teams() const {
    size_t counter = 0;
    std::for_each(teams_map.begin(), teams_map.end(), [&counter](auto& p) {
            const Team& t = std::get<1>(p);
            if (t.has_living_character()) ++counter;
            });
    return counter;
}

team_id TeamContainer::get_team(character_id c_id) const {
    return characters_map.at(c_id);
}

std::vector<character_id> TeamContainer::get_all_c_ids() const {
    std::vector<character_id> c_ids;
    std::for_each(teams_map.begin(), teams_map.end(), [&c_ids](auto& p) {
            const Team& t = std::get<1>(p);
            auto t_c_ids = t.get_c_ids();
            c_ids.insert(c_ids.end(), t_c_ids.begin(), t_c_ids.end());
            });
    return c_ids;
}

const std::unordered_map<team_id, Team>&
TeamContainer::get_const_map_ref() const {
  return teams_map;
}

std::unordered_map<team_id, Team>& TeamContainer::get_map_ref() {
  return teams_map;
}

const Team &TeamContainer::get_const_team_ref(team_id id) const {
  return teams_map.at(id);
}

Team &TeamContainer::get_team_ref(team_id id) { return teams_map[id]; }
