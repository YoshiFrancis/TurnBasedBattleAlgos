#include "dm.hpp"

using namespace tba;

std::unique_ptr<tba::DecisionMaker> tba::get_decision_maker(const TeamContainer& teams) {
  return std::make_unique<tba::TestAutoInputDM>(
      tba::TestAutoInputDM(teams));
}

std::unique_ptr<tba::DecisionMaker>
tba::get_user_decision_maker(const Character &c, team_id t_id) {
    return nullptr;
}
