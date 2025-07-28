#ifndef TBA_BATTLEGROUND_HPP
#define TBA_BATTLEGROUND_HPP

#include "Team.hpp"
#include "Action.hpp"
#include "DecisionMaker.hpp"

#include <vector>
#include <mutex>
#include <queue>
#include <unordered_map>

namespace tba {


class BattleGround {
    typedef std::tuple<std::optional<std::reference_wrapper<Character>>, std::unique_ptr<DecisionMaker>> char_dm_tup;
private:
  std::vector<Team>& teams;
  std::unordered_map<character_id, char_dm_tup> characters;
  unsigned int round;
  std::priority_queue<Action> actions_q;
  std::mutex q_lock;

public:
  BattleGround(std::vector<Team> &_teams);
  ~BattleGround();
  void begin_battle();
  void end_battle();

private:
  void initialize();

  void update_state();
  void ask_inputs();
  void apply_actions();

  // helpers
  void get_action(size_t idx);

};

} // namespace tba

#endif
