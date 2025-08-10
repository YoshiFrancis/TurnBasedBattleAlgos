#ifndef TBA_BATTLEGROUND_HPP
#define TBA_BATTLEGROUND_HPP

#include "Action.hpp"
#include "DMContainer.hpp"
#include "TeamContainer.hpp"

#include <mutex>
#include <queue>
#include <unordered_map>
#include <vector>

namespace tba {

class BattleGround {

private:
  TeamContainer tc;
  DMContainer dmc;

  unsigned int round;
  std::priority_queue<Action> actions_q;
  std::mutex q_lock;

public:
  BattleGround(TeamContainer _teams);
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
