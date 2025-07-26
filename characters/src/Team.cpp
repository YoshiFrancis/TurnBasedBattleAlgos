#include "Team.hpp"

#include <algorithm>

using namespace tba;

Team::Team(std::vector<Character> _characters) 
    : characters(_characters), decision_types(gen_decision_types())
{ }

bool Team::has_living_character() const {
  return std::any_of(characters.cbegin(), characters.cend(),
                     [](const Character &c) { return c.is_alive(); });
}

void Team::set_id(team_id _id) { id = _id; }

std::vector<std::tuple<character_id, DecisionMakerID>> Team::get_decision_types() const {
    return decision_types;
}

std::vector<std::tuple<character_id, DecisionMakerID>> Team::gen_decision_types() const {
    std::vector<std::tuple<character_id, DecisionMakerID>> d_types;
    std::for_each(characters.cbegin(), characters.cend(),
            [&d_types](const Character &c) {
            d_types.emplace_back(c.get_id(), c.get_decision_type());
            });
    return d_types;
}
