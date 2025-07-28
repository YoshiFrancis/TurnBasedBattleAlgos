#include "Stats.hpp"

using namespace tba;



Stats::Stats(int h, int s, int ad, ElementType e) 
    : health(h), speed(s), attack_dmg(ad), element(e)
{}

int Stats::get_health() const { return health; }
int Stats::get_speed() const { return speed; }
int Stats::get_attack_dmg() const { return attack_dmg; }
ElementType Stats::get_type() const { return element; }

void Stats::add_health(int amount) { health += amount; }

bool tba::operator==(const Stats &s1, const Stats &s2) {
  return s1.get_health() == s2.get_health() &&
         s1.get_speed() == s2.get_speed() &&
         s1.get_attack_dmg() == s2.get_attack_dmg() &&
         s1.get_type() == s2.get_type();
}
