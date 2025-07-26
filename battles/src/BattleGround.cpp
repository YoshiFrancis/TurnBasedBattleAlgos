#include "BattleGround.hpp"

using namespace tba;

BattleGround::BattleGround(std::vector<Team> &_teams) : teams(_teams), round(0)
{ }

BattleGround::~BattleGround() { }

void BattleGround::begin_battle() {
    initialize();
}

void BattleGround::end_battle() {}

void BattleGround::initialize() {
    round = 0;
    for (size_t i = 0; i < teams.size() * 1000; i += 1000) {
        teams[i].set_id(i);
    }
}

void BattleGround::update_state() {
    unsigned int alive_ctr = 0;
    std::for_each(teams.begin(), teams.end(), [&alive_ctr](Team& team) {
            if (team.has_living_character())
            ++alive_ctr;
            });

    while (alive_ctr > 1) {
        ask_inputs();
        apply_actions();
        alive_ctr = 0;
        std::for_each(teams.begin(), teams.end(), [&alive_ctr](Team& team) {
                if (team.has_living_character())
                ++alive_ctr;
                });
    }
    end_battle();
}

// currently linear asking -> no concurrency
// make concurrent via a worker pool in the future
// TODO
void BattleGround::ask_inputs() {
    std::for_each(decision_makers.begin(), decision_makers.end(), [this](const DecisionMaker& d_maker) {
            Action action = d_maker.get_action(teams);
            actions_q.push(action);

            });
}

void BattleGround::apply_actions() {
    while (!actions_q.empty()) {
        Action action = actions_q.top();
        actions_q.pop();
        // if (action.user.is_alive() && action.target.is_alive())
        //     action.apply();
    }
}

