#include "Character.hpp"

using namespace tba;

Character::Character(const std::string& file_path) {}

void Character::set_id(character_id _id) { id = _id; }

character_id Character::get_id() const {
    return id;
}

DecisionMakerID Character::get_decision_type() const {
    return decision_type;
}

bool Character::is_alive() const {
    return stats.get_health() > 0;
}

const Stats Character::get_stats() const {
    return stats;
}
