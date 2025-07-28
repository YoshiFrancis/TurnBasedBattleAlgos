#include "TestAutoInput.hpp"

#include <sstream>

using namespace tba;

TestAutoInputDM::TestAutoInputDM(const Character &c, team_id _t_id,
                                 DecisionMakerID _d_id)
    : DecisionMaker(c, _t_id, _d_id) {}

Action TestAutoInputDM::get_action(const std::vector<Team> &teams) const {
  std::istringstream iss(dm_state);
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
    return Action(0, 0, ActionType::ATTACK1);
  }
}
