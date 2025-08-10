#ifndef TBA_TEAMCONTAINER_HPP
#define TBA_TEAMCONTAINER_HPP

#include "Team.hpp"

#include <unordered_map>
#include <optional>
#include <list>

namespace tba {

std::optional<std::list<Team>> load_teams_file(const std::string& file_path);

class TeamContainer {

    private:
        std::unordered_map<team_id, Team> teams_map;
        size_t count = 0;

    public:
        TeamContainer(std::list<Team> teams);

        size_t size() const;
        size_t alive_teams() const;
        std::vector<character_id> get_all_c_ids() const;


        const std::unordered_map<team_id, Team>& get_const_map_ref() const;
        std::unordered_map<team_id, Team>& get_map_ref();

        const Team& get_const_team_ref(team_id id) const;
        Team& get_team_ref(team_id id);
};

}
#endif
