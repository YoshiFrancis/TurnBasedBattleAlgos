#include "BattleGround.hpp"

#include "dm.hpp"
#include "dm_helper.hpp"

#include <iostream>

using namespace tba;

BattleGround::BattleGround(TeamContainer _teams)
    : tc(_teams), dmc(tc), round(0) {}

BattleGround::~BattleGround() {}

void BattleGround::begin_battle() {
  initialize();
}

void BattleGround::end_battle() {}

void BattleGround::initialize() {
  round = 0;
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
    character_id user_id = action.get_user_id();
    character_id target_id = action.get_user_id();
    team_id user_t_id = tc.get_team(user_id);
    team_id target_t_id = tc.get_team(target_id);
    apply_action(get_character(user_t_id, user_id), 
            get_character(target_t_id, target_id), 
            std::move(action));
    actions_q.pop();
  }
}

Character& BattleGround::get_character(team_id t_id, character_id c_id) {
    Team& t = tc.get_team_ref(t_id);
    Character& c = t.get_character(c_id);
    return c;
}
