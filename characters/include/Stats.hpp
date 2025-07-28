#ifndef TBA_STATS_HPP
#define TBA_STATS_HPP

namespace tba {

enum class ElementType { FIRE, WATER, EARTH, AIR, LIGHT, DARK };

class Stats {

private:
  int health;
  int speed;
  int attack_dmg;
  ElementType element;

public:
  Stats() = default;
  Stats(int h, int s, int ad, ElementType e);

  int get_health() const;
  int get_speed() const;
  int get_attack_dmg() const;
  ElementType get_type() const;

  void add_health(int amount);
};

bool operator==(const Stats &s1, const Stats &s2);

} // namespace tba

#endif
