#include "dm_helper.hpp"

#include <sstream>
#include <exception>

std::pair<std::string, tba::character_id> tba::dm_helper::parse_acion_str(std::string_view str) {
    std::string s = std::string(str);
    std::istringstream iss(s);
    std::string action;
    iss >> action;
    std::string target_c_id_str;
    iss >> target_c_id_str;
    if (target_c_id_str == "") {
        std::stringstream err;
        err << "Failed to get target character id while parsing action string: [ " << s << " ]";
        throw std::runtime_error(err.str());
    } 
    character_id target_c_id = std::stoi(target_c_id_str);
    return { action, target_c_id };
}

std::optional<tba::ActionType> tba::dm_helper::get_action(std::string_view action_str) {
    using namespace tba;
    if (action_str == "attack1") {
        return ActionType::ATTACK1;
    } else if (action_str == "attack2") {
        return ActionType::ATTACK2;
    } else if (action_str == "attack3") {
        return ActionType::ATTACK3;
    } else {
        return std::nullopt;
    }
}
