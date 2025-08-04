#ifndef TBA_DECISION_MAKER_HPP
#define TBA_DECISION_MAKER_HPP

#include "Action.hpp"
#include "TeamContainer.hpp"

#include <memory>
#include <vector>

namespace tba {

class DecisionMaker {
protected:
  character_id c_id;
  team_id t_id;
  std::string dm_state;
  const TeamContainer& teams_ref;

public:
  DecisionMaker(character_id _c_id, team_id _t_id, const TeamContainer& teams);
  virtual ~DecisionMaker() = default;
  virtual Action get_action() const;
  void set_dm_state(const std::string &input);
};

} // namespace tba

#endif
