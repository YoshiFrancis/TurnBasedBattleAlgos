#include "Character.hpp"

#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <stdexcept>

// third party
#include <nlohmann/json.hpp>

using namespace tba;
using json = nlohmann::json;

Character::Character(const std::string &file_path) {
  if (!load_info_file(file_path)) {
    std::stringstream error;
    error << "Failed to load info file of path: " << file_path;
    throw(std::runtime_error(error.str()));
  }
}

Character::Character(const char* file_path) {
  if (!load_info_file(file_path)) {
    std::stringstream error;
    error << "Failed to load info file of path: " << file_path;
    throw(std::runtime_error(error.str()));
  }
}

Character::Character(json data) {
    if (!load_json(data)) {
        std::stringstream error;
        error << "Failed to load json for character";
        throw(std::runtime_error(error.str()));
    }
}

void Character::set_id(character_id _id) { id = _id; }

character_id Character::get_id() const { return id; }
DecisionMakerID Character::get_dm_id() const { return dm_id; }


bool Character::is_alive() const { return stats.get_health() > 0; }

const Stats Character::get_stats() const { return stats; }

std::string Character::get_readable_info() const {
  std::stringstream info;
  info << "Name: " << name << "\n"
       << "Description" << desc << "\n"
       << stats.get_readable_info() << "\n";
  return info.str();
}

std::string Character::get_name() const { return name; }
std::string Character::get_desc() const { return desc; }

static std::optional<ElementType> get_element_type(const std::string &element) {
  if (element == "FIRE") {
    return ElementType::FIRE;
  } else if (element == "EARTH") {
    return ElementType::EARTH;
  } else if (element == "AIR") {
    return ElementType::AIR;
  } else if (element == "DARK") {
    return ElementType::DARK;
  } else if (element == "LIGHT") {
    return ElementType::LIGHT;
  } else if (element == "WATER") {
    return ElementType::WATER;
  }
  return std::nullopt;
}

const Attack Character::get_attack1() const {
    return attack1;
}
const Attack Character::get_attack2() const {
    return attack2;
}
const Attack Character::get_attack3() const {
    return attack3;
}

void Character::apply_attack(const Attack &&attack) {
    stats.add_health(attack.damage);
}

bool Character::load_info_file(const std::string &file_path) {
  try {
    std::ifstream f(file_path);
    if (!f.is_open())
      return false;
    json data = json::parse(f);
    return load_json(data);
  } catch (std::exception &e) {
    return false;
  }
}

bool Character::load_json(json data) {
    name = data["name"];
    desc = data["description"];
    int health = data["health"];
    int speed = data["speed"];
    int attack_dmg = data["attack_dmg"];
    auto element_opt = get_element_type(data["element"]);
    if (!element_opt.has_value())
      return false;
    dm_id = static_cast<DecisionMakerID>(data["dm_id"]);
    stats = Stats(health, speed, attack_dmg, element_opt.value());
    return true;
}
