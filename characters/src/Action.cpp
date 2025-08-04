#include "Action.hpp"

using namespace tba;

Action::Action(character_id _user, character_id _target, ActionType _type)
    : user_id(_user), target_id(_target), speed(100), type(_type) {}
character_id Action::get_user_id() const { return user_id; };
character_id Action::get_target_id() const { return target_id; }
ActionType Action::get_type() const { return type; }
int Action::get_speed() const { return speed; }

void tba::apply_action(Character& user, Character& target, const Action&& action) {
  if (user.is_alive()) {
    switch (action.get_type()) {
    case ActionType::ATTACK1:
      target.apply_attack(user.get_attack1());
      break;
    case ActionType::ATTACK2:
      target.apply_attack(user.get_attack2());
      break;
    case ActionType::ATTACK3:
      target.apply_attack(user.get_attack3());
      break;
    }
  }
}
