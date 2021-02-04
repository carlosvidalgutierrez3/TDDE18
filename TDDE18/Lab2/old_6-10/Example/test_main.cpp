#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Book.h"

TEST_CASE("inizialitation"){
  Book b1;
  CHECK(b1.title == "");
  CHECK(b1.author == "");
  CHECK(b1.year == 0);
  CHECK(b1.edition == 0);
}

TEST_CASE("GET_AUTHOR"){
  Book b1{"Harry Potter","Astrid L.",2021,1};
  REQUIRE(getAuthor(b1)=="Astrid L.");
}
