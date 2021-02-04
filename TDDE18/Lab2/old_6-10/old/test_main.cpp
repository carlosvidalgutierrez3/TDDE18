#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Time.h"

TEST_CASE("inizialitation"){
  Time t;
  CHECK(t.hours == 0);
  CHECK(t.minutes == 0);
  CHECK(t.seconds == 0);
}

TEST_CASE("GET_HOURS"){
  Time t{9,59,30};
  int i{};
  int j{};
  char c{};
  std::cin >> t.hours >> c >> t.minutes >> c >> t.seconds;
  std::cout << t.hours << ":" << t.minutes << ":" << t.seconds << std::endl;
}
