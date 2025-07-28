#ifndef TBA_DECISION_MAKER_HPP
#define TBA_DECISION_MAKER_HPP

#include "Action.hpp"
#include "Team.hpp"

#include <memory>
#include <vector>

namespace tba {

class DecisionMaker {
protected:
  character_id c_id;
  team_id t_id;
  DecisionMakerID d_id;
  const Character &character;

  std::string dm_state = ""; // used by dms like user handled, test auto
public:
  DecisionMaker(const Character &c, team_id _t_id, DecisionMakerID _d_id);
  virtual ~DecisionMaker() = default;
  virtual Action get_action(const std::vector<Team> &teams) const;

  bool operator==(const DecisionMaker &other) const;

  inline character_id get_c_id() const { return c_id; }
  inline team_id get_t_id() const { return t_id; }

  void set_dm_state(const std::string &input);
};

struct DMAKERHashFunction {
  size_t operator()(const DecisionMaker &dmaker) const;
};

} // namespace tba

#endif
