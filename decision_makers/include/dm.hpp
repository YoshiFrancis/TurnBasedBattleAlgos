#ifndef TBA_DM_HPP
#define TBA_DM_HPP

#include "DecisionMaker.hpp"

// decision makers
#include "TestAutoInput.hpp"
#include "UserControl.hpp"

#include <memory>

namespace tba {

std::unique_ptr<tba::DecisionMaker> get_decision_maker(const TeamContainer& teams);

std::unique_ptr<DecisionMaker> get_user_decision_maker(const Character &c,
                                                       team_id t_id);

} // namespace tba

#endif
