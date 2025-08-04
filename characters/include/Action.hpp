#ifndef TBA_ACTION_HPP
#define TBA_ACTION_HPP

#include "enums.hpp"
#include "Character.hpp"

namespace tba {


class Action {
private:
  character_id user_id;
  character_id target_id;
  int speed;
  ActionType type;

public:
  Action(character_id user, character_id target, ActionType _type);
  ~Action() = default;

  inline virtual bool operator<(const Action &other) const {
    return get_speed() < other.get_speed();
  }

  character_id get_user_id() const;
  character_id get_target_id() const;
  ActionType get_type() const;
  int get_speed() const;
};

void apply_action(Character& user, Character& target, const Action&& action);

} // namespace tba

#endif

