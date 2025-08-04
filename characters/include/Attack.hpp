#ifndef TBA_ATTACK_HPP
#define TBA_ATTACK_HPP

#include "enums.hpp"

#include <string>

namespace tba {

struct Attack {
  std::string name;
  std::string desc;
  int damage;
  int accuracy;
  ElementType etype;
  EffectType effect;

  Attack(std::string_view n = "None", std::string_view des = "", int dam = 0,
         int acc = 100, ElementType ele = ElementType::AIR,
         EffectType eff = EffectType::NONE);
};

} // namespace tba

#endif
