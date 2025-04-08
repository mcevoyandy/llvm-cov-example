#include "gtest/gtest.h"

#include "cool_stuff_tests.hpp"

int main(int argc, char ** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
