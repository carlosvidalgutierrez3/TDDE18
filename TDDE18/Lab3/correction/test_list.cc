// This test program uses a test framework supporting TDD and BDD.
// You are not required to use the framework, but encouraged to.
// Code:
// https://github.com/philsquared/Catch.git
// Documentation:
// https://github.com/philsquared/Catch/blob/master/docs/tutorial.md

// You ARE however required to implement all test cases outlined here,
// even if you do it by way of your own function for each case.  You
// are recommended to solve the cases in order, and rerun all tests
// after you modify your code.

// This define lets Catch create the main test program
// (Must be in only one place!)
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Sorted_List.h"

#include <random>

//=======================================================================
// Test cases
//=======================================================================

/*
TODO:

You need tests for move contructor and move assignment

*/

TEST_CASE( "Create an empty list" ) {
  Sorted_List l{};

  REQUIRE( l.is_empty() == true );
  REQUIRE( l.size() == 0 );
}

// It is your job to create new test cases and fully test your Sorted_List class

TEST_CASE( "Insert and Remove elements" ) {
  Sorted_List l{};

  std::string str{"1991->1988->1986->1984->1983->end\n"};
  l.insert(1983);
  l.insert(1984);
  l.insert(1991);
  l.insert(1988);
  l.insert(1986);

  // check that all elements are added:
  REQUIRE( str.compare(l.print_list()) == 0 );
  //Delete an element not on the list
  l.remove(1987);
  l.remove(1986);
  str = "1991->1988->1984->1983->end\n";
  REQUIRE( str.compare(l.print_list()) == 0 );
  l.remove(1991);
  str = "1988->1984->1983->end\n";
  REQUIRE( str.compare(l.print_list()) == 0 );
  l.remove(1983);
  str = "1988->1984->end\n";
  REQUIRE( str.compare(l.print_list()) == 0 );
  l.remove(1984);
  str = "1988->end\n";
  REQUIRE( str.compare(l.print_list()) == 0 );
  l.remove(1988);
  REQUIRE( l.is_empty());
  //Try remove on empty list
  l.remove(1988);
  REQUIRE( l.is_empty());
}

TEST_CASE( "Create a copy with constructor" ) {
  Sorted_List l{};
  l.insert(1983);
  l.insert(1984);
  l.insert(1986);

  Sorted_List copy{l};
  REQUIRE( copy.size() == 3 );
  REQUIRE( l.size() == 3 );

  copy.insert(1990);
  REQUIRE( copy.size() == 4 );
  REQUIRE( l.size() == 3 );
}

TEST_CASE( "Copy Operator" ) {
  Sorted_List l{};
  l.insert(1983);
  l.insert(1984);
  l.insert(1986);

  Sorted_List m{};
  m=l;
  REQUIRE( m.size() == 3 );
  REQUIRE( l.size() == 3 );

  m.insert(1990);
  REQUIRE( m.size() == 4 );
  REQUIRE( l.size() == 3 );
}

TEST_CASE( "Move constructor" ){
  Sorted_List l{};
  l.insert(1983);
  l.insert(1984);
  l.insert(1986);

  Sorted_List m{std::move(l)};
  REQUIRE( m.size() == 3 );
  REQUIRE( l.size() == 0 );
}

TEST_CASE( "Move assignment operator" ){
  Sorted_List l{};
  l.insert(1983);
  l.insert(1984);
  l.insert(1986);

  Sorted_List m{};
  m=std::move(l);
  REQUIRE( m.size() == 3 );
  REQUIRE( l.size() == 0 );
}
