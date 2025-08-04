#include "TestAutoInput.hpp"

#include <sstream>

using namespace tba;

TestAutoInputDM::TestAutoInputDM(const TeamContainer& teams)
    : DecisionMaker(teams) {}

Action TestAutoInputDM::get_action(team_id t_id, character_id c_id) const {
  std::istringstream iss(dm_state_map.at(c_id));
  std::string action;
  iss >> action;
  std::string target_c_id_str;
  iss >> target_c_id_str;
  character_id target_c_id = std::stoi(target_c_id_str);

  if (action == "attack1") {
    return Action(c_id, target_c_id, ActionType::ATTACK1);
  } else if (action == "attack2") {
    return Action(c_id, target_c_id, ActionType::ATTACK2);
  } else if (action == "attack3") {
    return Action(c_id, target_c_id, ActionType::ATTACK3);
  } else {
    return Action(c_id, target_c_id, ActionType::ATTACK1);
  }
}
