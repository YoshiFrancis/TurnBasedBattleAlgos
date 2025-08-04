#include "Action.hpp"
#include "Team.hpp"
#include "dm.hpp"
#include "DMContainer.hpp"
#include <gtest/gtest.h>

TEST(DecisionMakers, TestDecisionMakerContainer) {
    std::list<tba::Team> teams_list = tba::load_teams_file("test_battleground_0.json");
    tba::TeamContainer tc(teams_list);
    tba::DMContainer dmc(tc);

    tba::Action expected_action(0, 1000, tba::ActionType::ATTACK1);
    tba::Action action = dmc.get_action(0);
    EXPECT_EQ(expected_action.get_user_id(), action.get_user_id());
    EXPECT_EQ(expected_action.get_target_id(), action.get_target_id());
    EXPECT_EQ(expected_action.get_type(), action.get_type());
    EXPECT_EQ(expected_action.get_speed(), action.get_speed());
}

TEST(DecisionMakers, TestAutoInput) {
  tba::Character test("build/files/test.json");
  tba::Team test_team({ test });
  tba::TeamContainer container( { test_team });
  test.set_id(0);
  auto dm = tba::get_decision_maker(test.get_dm_id(), test.get_id(), 0, container);
  ASSERT_TRUE(dynamic_cast<tba::TestAutoInputDM *>(dm.get()))
      << "Did not receive a TestAutoInput decision maker!";
  dm->set_dm_state("attack1 0");
  tba::Action a = dm->get_action();
  EXPECT_EQ(a.get_type(), tba::ActionType::ATTACK1);
  EXPECT_EQ(a.get_speed(), test.get_stats().get_speed());
  EXPECT_EQ(a.get_user_id(), test.get_id());
  EXPECT_EQ(a.get_target_id(), 0);

  dm->set_dm_state("attack2 1");
  tba::Action b = dm->get_action();
  EXPECT_EQ(b.get_type(), tba::ActionType::ATTACK2);
  EXPECT_EQ(b.get_speed(), test.get_stats().get_speed());
  EXPECT_EQ(b.get_user_id(), test.get_id());
  EXPECT_EQ(b.get_target_id(), 1);

  dm->set_dm_state("attack3 2");
  tba::Action c = dm->get_action();
  EXPECT_EQ(c.get_type(), tba::ActionType::ATTACK3);
  EXPECT_EQ(c.get_speed(), test.get_stats().get_speed());
  EXPECT_EQ(c.get_user_id(), test.get_id());
  EXPECT_EQ(c.get_target_id(), 2);
}
