#include "Action.hpp"

using namespace tba;

Action::Action(character_id user, character_id target, ActionType _type) 
    : user_id(user), target_id(target), speed(100), type(_type)
{}
character_id Action::get_user_id() const { return user_id; };
character_id Action::get_target_id() const { return target_id; }
ActionType Action::get_type() const { return type; }
int Action::get_speed() const { return speed; }
