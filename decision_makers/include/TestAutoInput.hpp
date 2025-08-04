#ifndef TBA_TESTAUTOINPUT_HPP
#define TBA_TESTAUTOINPUT_HPP

#include "DecisionMaker.hpp"

namespace tba {

class TestAutoInputDM : public DecisionMaker {

    public:
        TestAutoInputDM(const TeamContainer& teams);

        virtual ~TestAutoInputDM()  = default;
        Action get_action(team_id t_id, character_id c_id) const override;
};

}

#endif
