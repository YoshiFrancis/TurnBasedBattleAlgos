#ifndef TBA_TESTAUTOINPUT_HPP
#define TBA_TESTAUTOINPUT_HPP

#include "DecisionMaker.hpp"

namespace tba {

class TestAutoInputDM : public DecisionMaker {

    public:
        TestAutoInputDM(const Character& c, team_id _t_id, DecisionMakerID _d_id);

        virtual ~TestAutoInputDM()  = default;
        Action get_action(const std::vector<Team>& teams) const override;
};

}

#endif
