#include "Team.hpp"

#include <algorithm>

using namespace tba;

Team::Team(std::vector<Character> _characters) 
    : characters(_characters), decision_types(gen_decision_types())
{ }


Team::Team(json data) {
    team_name = data["team_name"];
    for (size_t i = 0; i < data["members"].size(); ++i) {
        characters.emplace_back(data["members"][i]);
    }
}

const std::vector<Character>& Team::get_characters() {
    return characters;
}

bool Team::has_living_character() const {
  return std::any_of(characters.cbegin(), characters.cend(),
                     [](const Character &c) { return c.is_alive(); });
}

void Team::set_id(team_id _id) { 
    id = _id; 
    for (size_t i = 1; i < characters.size(); ++i) {
        characters[i].set_id(id + i);
    }
}

std::vector<std::tuple<character_id, DecisionMakerID>> Team::get_decision_types() const {
    return decision_types;
}

std::vector<std::tuple<character_id, DecisionMakerID>> Team::gen_decision_types() const {
    std::vector<std::tuple<character_id, DecisionMakerID>> d_types;
    std::for_each(characters.cbegin(), characters.cend(),
            [&d_types](const Character &c) {
            d_types.emplace_back(c.get_id(), c.get_dm_id());
            });
    return d_types;
}
