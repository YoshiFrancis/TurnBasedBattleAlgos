#include "Character.hpp"

using namespace tba;

Character::Character(const std::string& _name, const std::string& _desc, int _health, int _speed, int _attack_dmg, ElementType _element, DecisionMakerID d_type) 
    : name(_name), desc(_desc), health(_health), speed(_speed), attack_dmg(_attack_dmg), element(_element), decision_type(d_type)
{}

void Character::set_id(character_id _id) { id = _id; }

character_id Character::get_id() const {
    return id;
}

DecisionMakerID Character::get_decision_type() const {
    return decision_type;
}

bool Character::is_alive() const {
    return health > 0;
}
