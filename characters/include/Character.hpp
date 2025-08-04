#ifndef TBA_CHARACTER_HPP
#define TBA_CHARACTER_HPP

#include "Attack.hpp"
#include "Stats.hpp"
#include "enums.hpp"

#include <string>
#include <vector>

namespace tba {

class Character {

private:
  std::string name;
  std::string desc;

  Attack attack1;
  Attack attack2;
  Attack attack3;

  Stats stats;

  character_id id;
  DecisionMakerID dm_id;

public:
  Character(const std::string &file_name);

  void set_id(character_id _id);

  character_id get_id() const;
  DecisionMakerID get_dm_id() const;
  std::string get_name() const;
  std::string get_desc() const;
  bool is_alive() const;

  const Stats get_stats() const;
  std::string get_readable_info() const;

  const Attack get_attack1() const;
  const Attack get_attack2() const;
  const Attack get_attack3() const;

  void apply_attack(const Attack &&attack);

private:
  bool load_info_file(const std::string &file_path);
};

} // namespace tba

#endif
