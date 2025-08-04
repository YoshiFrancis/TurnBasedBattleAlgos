#ifndef TBA_TEAMCONTAINER_HPP
#define TBA_TEAMCONTAINER_HPP

#include "Team.hpp"

#include <unordered_map>
#include <list>

namespace tba {

std::list<Team> load_teams_file(const std::string& file_path);

class TeamContainer {

    private:
        std::unordered_map<team_id, Team> teams_map;

    public:
        TeamContainer(std::list<Team> teams);

        const std::unordered_map<team_id, Team> get_const_map_ref() const;
        std::unordered_map<team_id, Team> get_map_ref();

        const Team& get_const_team_ref(team_id id) const;
        Team& get_team_ref(team_id id);
};

}
#endif
