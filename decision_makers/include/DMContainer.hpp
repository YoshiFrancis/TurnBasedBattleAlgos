#ifndef TBA_DMCONTAINER_HPP
#define TBA_DMCONTAINER_HPP

#include "Action.hpp"
#include "DecisionMaker.hpp"
#include "TeamContainer.hpp"
#include "dm.hpp"

#include <memory>
#include <optional>
#include <string>
#include <unordered_map>

namespace tba {

class DMContainer {
protected:
  std::unordered_map<character_id, std::unique_ptr<DecisionMaker>> dm_map;
  const TeamContainer &teams_ref;

public:
  DMContainer(const TeamContainer &teams);
  ~DMContainer() = default;
  std::optional<Action> get_action(character_id c_id) const;
  void set_dm_state(character_id id, const std::string &input);
};

} // namespace tba
  //
#endif
