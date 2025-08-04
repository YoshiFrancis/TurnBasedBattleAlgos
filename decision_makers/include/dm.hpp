#ifndef TBA_DM_HPP
#define TBA_DM_HPP

#include "DecisionMaker.hpp"

// decision makers
#include "TestAutoInput.hpp"
#include "UserControl.hpp"

#include <memory>

namespace tba {

std::unique_ptr<tba::DecisionMaker> get_decision_maker(DecisionMakerID d_id, character_id c_id, team_id t_id, const TeamContainer& teams);

} // namespace tba

#endif
