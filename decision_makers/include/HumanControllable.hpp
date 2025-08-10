#ifndef TBA_HUMANCONTROLLABLE_DM_HPP
#define TBA_HUMANCONTROLLABLE_DM_HPP

#include "DecisionMaker.hpp"

#include <optional>

namespace tba {

class HumanControllable : public DecisionMaker {

    public:
        HumanControllable(character_id _c_id, team_id _t_id, const TeamContainer& teams);
        virtual ~HumanControllable() = default;
        std::optional<Action> get_action() const override;

};

}


#endif
