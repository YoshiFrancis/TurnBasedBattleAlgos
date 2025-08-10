#ifndef TBA_DM_HELPER_HPP
#define TBA_DM_HELPER_HPP

#include <string>
#include <string_view>

#include "enums.hpp"

namespace tba {

namespace dm_helper {
    std::pair<std::string, character_id> parse_acion_str(std::string_view str);
    std::optional<ActionType> get_action(std::string_view action_str);
}

}

#endif
