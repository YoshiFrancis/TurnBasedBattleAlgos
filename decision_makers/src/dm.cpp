#include "dm.hpp"

using namespace tba;

std::unique_ptr<tba::DecisionMaker> tba::get_decision_maker(DecisionMakerID d_id, character_id c_id, team_id t_id, const TeamContainer& teams) {
    switch(d_id) {
        case DecisionMakerID::TestAutoInput:
            return std::make_unique<tba::TestAutoInputDM>(tba::TestAutoInputDM(c_id, t_id, teams));
        default:
            return nullptr;
    }

}
