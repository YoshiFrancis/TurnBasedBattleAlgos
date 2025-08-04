#ifndef TBA_ENUMS_HPP
#define TBA_ENUMS_HPP

namespace tba {

typedef unsigned int character_id;
typedef unsigned int team_id;

enum class ActionType { ATTACK1, ATTACK2, ATTACK3 };

enum class DecisionMakerID {
  TestAutoInput = 0,
  HumanControllable = 1,
  DecisionTree = 2
};

enum class ElementType { FIRE, WATER, EARTH, AIR, LIGHT, DARK };
enum class EffectType { STUN, SLEEP, POISON, HEAL, NONE } ;

}


#endif
