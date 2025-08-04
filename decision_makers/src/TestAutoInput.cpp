#include "TestAutoInput.hpp"

#include <sstream>

using namespace tba;

TestAutoInputDM::TestAutoInputDM(character_id _c_id, team_id _t_id, const TeamContainer& teams) 
    : DecisionMaker(_c_id, _t_id, teams) 
{}

Action TestAutoInputDM::get_action() const {
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
    return Action(c_id, target_c_id, ActionType::ATTACK1);
  }
}
