#include "gtest/gtest.h"

#include "other_stuff_tests.hpp"

int main(int argc, char ** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
