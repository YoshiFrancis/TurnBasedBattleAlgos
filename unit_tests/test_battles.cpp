#include <gtest/gtest.h>

#include "BattleGround.hpp"

TEST(BattleGrounds, TestBattleGroundFile0) {
    const std::string teams_file = "build/files/battlegrounds/test0.json";

    auto teams_list_opt = tba::load_teams_file(teams_file);
    ASSERT_TRUE(teams_list_opt.has_value())
        << "Unable to load teams file: " << teams_file;
    auto teams_list = teams_list_opt.value();
    tba::TeamContainer tc(teams_list);
    tba::BattleGround bg(tc);
    bg.begin_battle();
    // while (bg.update_state()) {
    //     
    // }
    // 

}
