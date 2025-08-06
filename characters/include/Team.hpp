#ifndef TBA_TEAM_HPP
#define TBA_TEAM_HPP

#include "Character.hpp"

#include <nlohmann/json.hpp>

#include <deque>
#include <vector>

namespace tba {

class Team {

  using json = nlohmann::json;

private:
  std::string team_name;
  std::vector<Character> characters;
  team_id id;
  std::vector<std::tuple<character_id, DecisionMakerID>> decision_types;

public:
  Team(std::vector<Character> _characters = {});
  Team(json data);

  const std::vector<Character> &get_characters();

  void set_id(team_id id);
  inline team_id get_id() const { return id; }

  bool has_living_character() const;
  std::vector<std::tuple<character_id, DecisionMakerID>>
  get_decision_types() const;

private:
  std::vector<std::tuple<character_id, DecisionMakerID>>
  gen_decision_types() const;
};

} // namespace tba

#endif
