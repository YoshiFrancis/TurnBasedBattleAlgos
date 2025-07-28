#ifndef TBA_CHARACTER_HPP
#define TBA_CHARACTER_HPP

#include "Action.hpp"
#include "Stats.hpp"

#include <string>
#include <vector>

namespace tba {

class Character {

private:
  std::string name;
  std::string desc;

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

private:
  bool load_info_file(const std::string &file_path);
};

} // namespace tba

#endif
