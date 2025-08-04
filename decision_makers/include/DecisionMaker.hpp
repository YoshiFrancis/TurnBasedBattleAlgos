#ifndef TBA_DECISION_MAKER_HPP
#define TBA_DECISION_MAKER_HPP

#include "Action.hpp"
#include "TeamContainer.hpp"

#include <memory>
#include <vector>

namespace tba {

class DecisionMaker {
protected:
  std::unordered_map<character_id, DecisionMakerID> dm_map;
  std::unordered_map<character_id, std::string> dm_state_map;
  const TeamContainer& teams_ref;

public:
  DecisionMaker(const TeamContainer& teams);
  virtual ~DecisionMaker() = default;
  virtual Action get_action(team_id t_id, character_id c_id) const;
  void set_dm_state(character_id id, const std::string &input);
};

} // namespace tba

#endif
