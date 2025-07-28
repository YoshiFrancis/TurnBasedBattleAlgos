
#include "Character.hpp"
#include <gtest/gtest.h>
#include <stdexcept>

TEST(Characters, LoadFile) {
  tba::Character test = tba::Character("files/test.json");
  tba::Stats test_stats(100, 100, 100, tba::ElementType::FIRE);
  EXPECT_EQ(test.get_stats(), test_stats);

  tba::Character test2 = tba::Character("files/test2.json");
  tba::Stats test_stats2(200, 200, 200, tba::ElementType::EARTH);
  EXPECT_EQ(test2.get_stats(), test_stats2);

  EXPECT_NE(test.get_stats(), test2.get_stats());
}

TEST(Characters, LoadFileFail) {
  EXPECT_THROW(tba::Character("files/this_file_dne.fail"), std::runtime_error);
  EXPECT_THROW(tba::Character("test.json"), std::runtime_error);
}
