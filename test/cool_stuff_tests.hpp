#pragma once

#include "cool_stuff.hpp"

#include <iostream>

#include "gtest/gtest.h"

class CoolStuffTests : public ::testing::Test
{
    public:
        CoolStuffTests()
        {
            // Leaving for convenience. Not used for current unit tests.
        }

        ~CoolStuffTests()
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

TEST_F(CoolStuffTests, CoolTestFixture)
{
    my_namespace::CoolStuff cool_stuff;
    cool_stuff.cool_function();
    EXPECT_EQ(cool_stuff.another_cool_function(), 42);
}

TEST_F(CoolStuffTests, AnotherCoolTestFixture)
{
    my_namespace::CoolStuff cool_stuff;
    EXPECT_EQ(cool_stuff.the_coolest_function(0), 42);
}
