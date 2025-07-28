#include "Stats.hpp"

#include <sstream>

using namespace tba;

std::string tba::element_to_str(ElementType element) {
    switch(element) {
        case tba::ElementType::FIRE:
            return "Fire";
        case tba::ElementType::WATER:
            return "Water";
        case tba::ElementType::LIGHT:
            return "Light";
        case tba::ElementType::DARK:
            return "Dark";
        case tba::ElementType::AIR:
            return "Air";
        case tba::ElementType::EARTH:
            return "Earth";
    }
}


Stats::Stats(int h, int s, int ad, ElementType e) 
    : health(h), speed(s), attack_dmg(ad), element(e)
{}

std::string Stats::get_readable_info() const {
    std::stringstream info;
    info << "health: " << health << "\n"
        << "speed: " << speed << "\n"
        << "attack_dmg: " << attack_dmg << "\n"
        << "element: " << tba::element_to_str(element);
    return info.str();
}

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
