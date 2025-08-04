#include "Action.hpp"
#include "dm.hpp"
#include <gtest/gtest.h>

TEST(DecisionMakers, TestAutoInput) {
  tba::Character test("build/files/test.json");
  tba::Team test_team({ test });
  tba::TeamContainer container( { test_team });
  test.set_id(0);
  auto dm = tba::get_decision_maker(container);
  ASSERT_TRUE(dynamic_cast<tba::TestAutoInputDM *>(dm.get()))
      << "Did not receive a TestAutoInput decision maker!";
  dm->set_dm_state(test.get_id(), "attack1 0");
  tba::Action a = dm->get_action(0, test.get_id());
  EXPECT_EQ(a.get_type(), tba::ActionType::ATTACK1);
  EXPECT_EQ(a.get_speed(), test.get_stats().get_speed());
  EXPECT_EQ(a.get_user_id(), test.get_id());
  EXPECT_EQ(a.get_target_id(), 0);

  dm->set_dm_state(test.get_id(), "attack2 1");
  tba::Action b = dm->get_action(0, test.get_id());
  EXPECT_EQ(b.get_type(), tba::ActionType::ATTACK2);
  EXPECT_EQ(b.get_speed(), test.get_stats().get_speed());
  EXPECT_EQ(b.get_user_id(), test.get_id());
  EXPECT_EQ(b.get_target_id(), 1);

  dm->set_dm_state(test.get_id(), "attack3 2");
  tba::Action c = dm->get_action(0, test.get_id());
  EXPECT_EQ(c.get_type(), tba::ActionType::ATTACK3);
  EXPECT_EQ(c.get_speed(), test.get_stats().get_speed());
  EXPECT_EQ(c.get_user_id(), test.get_id());
  EXPECT_EQ(c.get_target_id(), 2);
}
