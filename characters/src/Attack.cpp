#include "Attack.hpp"

tba::Attack::Attack(std::string_view n, std::string_view des, int dam, int acc,
                    ElementType ele, EffectType eff)
    : name(n), desc(des), damage(dam), accuracy(acc), etype(ele), effect(eff) {}
