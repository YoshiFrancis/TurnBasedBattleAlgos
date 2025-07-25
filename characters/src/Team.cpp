#include "Team.hpp"

#include <algorithm>

using namespace tba;

bool Team::has_living_character() const {
  return std::any_of(characters.cbegin(), characters.cend(),
                     [](const Character &c) { return c.is_alive(); });
}

void Team::set_id(size_t _id) { id = _id; }

std::vector<Action> Team::get_actions(const std::vector<Team> &teams) {
  std::vector<Action> actions;
  std::for_each(characters.begin(), characters.end(),
                [&actions, &teams](Character &c) {
                  actions.push_back(c.get_action(teams));
                });
  return actions;
}
