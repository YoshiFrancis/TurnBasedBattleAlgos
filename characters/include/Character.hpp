#ifndef TBA_CHARACTER_HPP
#define TBA_CHARACTER_HPP

#include "Action.hpp"

#include <string>
#include <vector>

namespace tba {

enum class ElementType { FIRE, WATER, EARTH, AIR, LIGHT, DARK };

class Character {

  const std::string name;
  const std::string desc;

  int health;
  int speed;
  int attack_dmg;
  ElementType element;

  DecisionMakerID decision_type;
  character_id id;

public:
  Character(const std::string &_name, const std::string &_desc, int _health,
            int _speed, int _attack_dmg, ElementType _element,
            DecisionMakerID d_type);

  void set_id(character_id _id);

  character_id get_id() const;
  DecisionMakerID get_decision_type() const;
  bool is_alive() const;
};

} // namespace tba

#endif
