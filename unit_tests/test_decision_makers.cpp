#include <gtest/gtest.h>
#include "DecisionMaker.hpp"
#include "TestAutoInput.hpp"

TEST(DecisionMakers, TestAutoInput) {
    tba::Character test("build/files/test.json");
    auto dm = tba::get_decision_maker(test, 0, tba::DecisionMakerID::TestAutoInput);
    ASSERT_TRUE(dynamic_cast<tba::TestAutoInputDM*>(dm.get()))
        << "Did not receive a TestAutoInput decision maker!";


}
