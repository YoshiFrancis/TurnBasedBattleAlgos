#ifndef TBA_DMCONTAINER_HPP
#define TBA_DMCONTAINER_HPP

#include "Action.hpp"
#include "TeamContainer.hpp"

#include "DecisionMaker.hpp"

namespace tba {

class DMContainer {
protected:
  std::unordered_map<character_id, std::unique_ptr<DecisionMaker>> dm_map;
  const TeamContainer &teams_ref;

public:
  DMContainer(const TeamContainer &teams);
  virtual ~DMContainer() = default;
  virtual Action get_action(team_id t_id, character_id c_id) const;
  void set_dm_state(character_id id, const std::string &input);
};

} // namespace tba
  //
#endif
