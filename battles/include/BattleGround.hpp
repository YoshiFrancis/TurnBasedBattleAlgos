#ifndef TBA_BATTLEGROUND_HPP
#define TBA_BATTLEGROUND_HPP

#include "Team.hpp"
#include "Action.hpp"

#include <vector>
#include <mutex>
#include <queue>

namespace tba {

class BattleGround {
private:
  std::vector<Team>& teams;
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
