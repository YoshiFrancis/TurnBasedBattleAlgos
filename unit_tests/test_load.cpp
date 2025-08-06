#include "Character.hpp"
#include "Team.hpp"
#include "TeamContainer.hpp"
#include "DMContainer.hpp"

#include <fstream>
#include <stdexcept>

#include <gtest/gtest.h>
#include <nlohmann/json.hpp>

TEST(Loading, LoadJsonFile) {
  using json = nlohmann::json;
  std::ifstream f;
  EXPECT_NO_THROW(f.open("build/files/test.json"));
  EXPECT_TRUE(f.is_open()); // optional
  json data = json::parse(f);

  json expected_data = {
      {"name", "Testa"},
      {"description", "Used for testing character json files"},
      {"health", 100},
      {"speed", 100},
      {"attack_dmg", 100},
      {"element", "FIRE"},
      {"dm_id", 0}};

  EXPECT_EQ(expected_data, data);
}

TEST(Loading, LoadFileFail) {
  EXPECT_THROW(tba::Character("build/files/this_file_dne.fail"),
               std::runtime_error);
  EXPECT_THROW(tba::Character("build/test.json"), std::runtime_error);
}

TEST(Loading, TestCharacterLoad) {
  tba::Character test = tba::Character("build/files/test.json");
  tba::Stats test_stats(100, 100, 100, tba::ElementType::FIRE);
  EXPECT_EQ(test.get_stats(), test_stats)
      << "test: " << test.get_readable_info() << "\n"
      << "test_stats expected: " << test_stats.get_readable_info();
  EXPECT_EQ(test.get_name(), "Testa");
  EXPECT_EQ(test.get_desc(), "Used for testing character json files");
  EXPECT_EQ(test.get_dm_id(), tba::DecisionMakerID::TestAutoInput);

  tba::Character test2 = tba::Character("build/files/test2.json");
  tba::Stats test_stats2(200, 200, 200, tba::ElementType::EARTH);
  EXPECT_EQ(test2.get_stats(), test_stats2)
      << "test2: " << test2.get_readable_info() << "\n"
      << "test_stats2 expected: " << test_stats2.get_readable_info();
  EXPECT_EQ(test2.get_name(), "Twoah");
  EXPECT_EQ(test2.get_desc(),
            "Used for multiple testing characters json files");
  EXPECT_EQ(test2.get_dm_id(), tba::DecisionMakerID::TestAutoInput);

  EXPECT_NE(test.get_stats(), test2.get_stats());
}

TEST(Loading, TestTeamsLoad) {
    auto teams_list_opt = tba::load_teams_file("build/files/battlegrounds/test0.json");
    ASSERT_TRUE(teams_list_opt.has_value());
    auto teams_list = teams_list_opt.value();
    std::list<tba::Team>::iterator teams_it = teams_list.begin();
    ASSERT_NE(teams_it, teams_list.end());

    tba::Team& team_0 = *teams_it;
    EXPECT_EQ(team_0.get_id(), 0);
    const auto& a = team_0.get_characters();
    EXPECT_EQ(a[0].get_id(), 0);
    EXPECT_EQ(a.size(), 2);
    EXPECT_TRUE(team_0.has_living_character());

    std::advance(teams_it, 1);
    ASSERT_NE(teams_it, teams_list.end());

    tba::Team& team_1 = *teams_it;
    EXPECT_EQ(team_1.get_id(), 1);
    const auto& b = team_1.get_characters();
    EXPECT_EQ(b[0].get_id(), 1000);
    EXPECT_EQ(b.size(), 2);
    EXPECT_TRUE(team_1.has_living_character());

    std::advance(teams_it, 1);
    ASSERT_NE(teams_it, teams_list.end());

    tba::Team& team_2 = *teams_it;
    EXPECT_EQ(team_2.get_id(), 2);
    const auto& c = team_2.get_characters();
    EXPECT_EQ(c[0].get_id(), 2000);
    EXPECT_EQ(c.size(), 2);
    EXPECT_TRUE(team_2.has_living_character());

    std::advance(teams_it, 1);
    EXPECT_EQ(teams_it, teams_list.end());
}

TEST(Loading, TestDMContainerLoad) {
    auto teams_list_opt = tba::load_teams_file("build/files/battlegrounds/test0.json");
    ASSERT_TRUE(teams_list_opt.has_value());
    auto teams_list = teams_list_opt.value();
    tba::TeamContainer tc(teams_list);
    tba::DMContainer dmc(tc);

    tba::Action expected_action(0, 0, tba::ActionType::ATTACK1);
    tba::Action action = dmc.get_action(0);
    EXPECT_EQ(expected_action.get_user_id(), action.get_user_id());
    EXPECT_EQ(expected_action.get_target_id(), action.get_target_id());
    EXPECT_EQ(expected_action.get_type(), action.get_type());
    EXPECT_EQ(expected_action.get_speed(), action.get_speed());
}

TEST(Loading, TestBattleGroundLoad) {

}
