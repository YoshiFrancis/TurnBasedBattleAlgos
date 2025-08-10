#ifndef TBA_TESTAUTOINPUT_HPP
#define TBA_TESTAUTOINPUT_HPP

#include "DecisionMaker.hpp"

namespace tba {

class TestAutoInputDM : public DecisionMaker {

    public:
        TestAutoInputDM(character_id _c_id, team_id _t_id, const TeamContainer& teams);

        virtual ~TestAutoInputDM()  = default;
        std::optional<Action> get_action() const override;
};

}

#endif
