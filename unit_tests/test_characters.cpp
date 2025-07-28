#include "Character.hpp"

#include <fstream>
#include <stdexcept>

// third pary
#include <gtest/gtest.h>
#include <nlohmann/json.hpp>

TEST(JSON, LoadJsonFile) {
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
      {"element", "FIRE"}};

  EXPECT_EQ(expected_data, data);
}

TEST(Characters, LoadFile) {
  tba::Character test = tba::Character("build/files/test.json");
  tba::Stats test_stats(100, 100, 100, tba::ElementType::FIRE);
  EXPECT_EQ(test.get_stats(), test_stats)
      << "test: " << test.get_readable_info() << "\n"
      << "test_stats expected: " << test_stats.get_readable_info();
  EXPECT_EQ(test.get_name(), "Testa");
  EXPECT_EQ(test.get_desc(), "Used for testing character json files");

  tba::Character test2 = tba::Character("build/files/test2.json");
  tba::Stats test_stats2(200, 200, 200, tba::ElementType::EARTH);
  EXPECT_EQ(test2.get_stats(), test_stats2)
      << "test2: " << test2.get_readable_info() << "\n"
      << "test_stats2 expected: " << test_stats2.get_readable_info();
  EXPECT_EQ(test2.get_name(), "Twoah");
  EXPECT_EQ(test2.get_desc(),
            "Used for multiple testing characters json files");

  EXPECT_NE(test.get_stats(), test2.get_stats());
}

TEST(Characters, LoadFileFail) {
  EXPECT_THROW(tba::Character("build/files/this_file_dne.fail"),
               std::runtime_error);
  EXPECT_THROW(tba::Character("build/test.json"), std::runtime_error);
}
