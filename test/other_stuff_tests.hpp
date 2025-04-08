#pragma once

#include "other_stuff.hpp"

#include <iostream>

#include "gtest/gtest.h"

class OtherStuffTests : public ::testing::Test
{
    public:
        OtherStuffTests()
        {
            // Leaving for convenience. Not used for current unit tests.
        }

        ~OtherStuffTests()
        {
            // Leaving for convenience. Not used for current unit tests.
        }

        virtual void SetUp()
        {
            // Leaving for convenience. Not used for current unit tests.
        }

        virtual void TearDown()
        {
            // Leaving for convenience. Not used for current unit tests.
        }
    private:
};

TEST_F(OtherStuffTests, OtherTestFixture)
{
    my_namespace::OtherStuff other_stuff;
    other_stuff.some_function();
    EXPECT_EQ(other_stuff.some_other_function(), 42);
}

TEST_F(OtherStuffTests, AnotherOtherTestFixture)
{
    my_namespace::OtherStuff other_stuff;
    EXPECT_EQ(other_stuff.another_function(44), 42);

    other_stuff.another_function(1);
}
