#include "BattleGround.hpp"

#include "dm.hpp"

using namespace tba;

BattleGround::BattleGround(TeamContainer _teams)
    : tc(_teams), dmc(tc), round(0) {}

BattleGround::~BattleGround() {}

void BattleGround::begin_battle() {
  initialize();
  update_state();
}

void BattleGround::end_battle() {}

void BattleGround::initialize() {
  round = 0;
  auto teams = tc.get_map_ref();
  for (size_t i = 0; i < teams.size(); ++i) {
    team_id t_id = i * 1000;
    teams[i].set_id(t_id);
  }
}

bool BattleGround::update_state() {
  if (tc.alive_teams() > 1) {
    ask_inputs();
    apply_actions();
    return true;
  }
  end_battle();
  return false;
}

// currently linear asking -> no concurrency
// make concurrent via a worker pool in the future
// TODO
void BattleGround::ask_inputs() {
  auto character_ids = tc.get_all_c_ids();
  std::for_each(character_ids.begin(), character_ids.end(), [this](auto id) {
    std::optional<Action> action = dmc.get_action(id);
    if (action.has_value())
      actions_q.push(action.value());
  });
}

void BattleGround::apply_actions() {
  while (!actions_q.empty()) {
    Action action = actions_q.top();
    actions_q.pop();
    // action.apply();
  }
}
