#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Time.h"
#include <iostream>
#include <ostream>
#include <string>

TEST_CASE("initialization"){
  Time t;
  CHECK(t.hours == 0);
  CHECK(t.minutes == 0);
  CHECK(t.seconds == 0);
}

TEST_CASE("is_Valid"){
  Time t1{15,57,30};//random time
  Time t2{00,00,00};//minimum time
  Time t3{23,59,59};//maximum time
  Time t4{28,59,59};//wrong time
  REQUIRE(is_Valid(t1));
  REQUIRE(is_Valid(t2));
  REQUIRE(is_Valid(t3));
  REQUIRE(!(is_Valid(t4)));
}

TEST_CASE("to_String"){
  Time t{14,57,30};
  std::string str{"02:57:30 pm"};
  bool twelve{true};//decide if printed in 12h format(TRUE) or 24h(FALSE)
  std::stringstream ss{};
  ss<<to_string(t,twelve);
  std::string sstr = ss.str();
  REQUIRE(str.compare(sstr) == 0);
}

TEST_CASE("is_am()"){
  Time t1{11,59,59};//maximum time
  Time t2{00,00,00};//minimum time
  Time t3{12,00,00};//pm
  REQUIRE(is_am(t1));
  REQUIRE(is_am(t2));
  REQUIRE(!(is_am(t3)));
}

TEST_CASE("Operator +"){
  Time t1{15,40,50};
  Time t2{15,40,55};
  REQUIRE(t1+5==t2);//add 5 seconds

  Time t3{15,40,50};
  Time t4{15,41,55};
  REQUIRE(t3+65==t4);//add 1 minute and 5 seconds

  Time t5{15,40,50};
  Time t6{16,40,50};
  REQUIRE(t5+3600==t6);// add 1 hour

  Time t7{23,59,55};
  Time t8{00,00,05};
  REQUIRE(t7+10==t8);//add 10 seconds and resets the time
}


TEST_CASE("Operator -"){
  Time t1{15,40,50};
  Time t2{15,40,45};
  REQUIRE(t1-5==t2);//subtract 5 seconds

  Time t3{15,40,50};
  Time t4{15,39,45};
  REQUIRE(t3-65==t4);//subtract 1 minute and 5 seconds

  Time t5{15,40,50};
  Time t6{14,40,50};
  REQUIRE(t5-3600==t6);//subtract 1 hour

  Time t7{00,00,05};
  Time t8{23,59,55};
  REQUIRE(t7-10==t8);//subtract 10 seconds and resets the time
}

TEST_CASE("Operator ++"){
  Time t1{15,40,50};
  Time t2{15,40,51};

  REQUIRE(++t1==t2);
  t1-1;
  REQUIRE(t1++==t2);
}


TEST_CASE("Operator --"){
  Time t1{15,40,50};
  Time t2{15,40,49};

  REQUIRE(--t1==t2);
  t1+1;
  REQUIRE(t1--==t2);
}


TEST_CASE("Comparison =="){
  Time t1{14,47,34};
  Time t2{14,47,34};//equal time
  Time t3{19,50,30};//different time
  REQUIRE(t1==t2);
  REQUIRE(!(t1==t3));
}

TEST_CASE("Comparison !="){
  Time t1{14,47,30};
  Time t2{14,47,35};//different seconds
  Time t3{14,50,30};//different minutes
  Time t4{15,47,30};//different hours
  REQUIRE(t1!=t2);
  REQUIRE(t1!=t3);
  REQUIRE(t1!=t4);
}

TEST_CASE("Comparison >"){
  Time t1{14,50,30};
  Time t2{14,50,35};//higher seconds
  Time t3{14,55,30};//higher minutes
  Time t4{15,40,20};//higher hours
  REQUIRE(t2>t1);
  REQUIRE(t3>t1);
  REQUIRE(t4>t1);
}

TEST_CASE("Comparison <"){
  Time t1{14,50,30};
  Time t2{14,50,20};//lower seconds
  Time t3{14,40,30};//lower minutes
  Time t4{13,50,20};//lower hours
  REQUIRE(t2<t1);
  REQUIRE(t3<t1);
  REQUIRE(t4<t1);
}

TEST_CASE("Comparison >="){
  Time t1{14,50,30};
  Time t2{14,50,35};//higher seconds
  Time t3{14,55,30};//higher minutes
  Time t4{15,40,20};//higher hours
  Time t5{14,50,30};//equal time
  REQUIRE(t2>=t1);
  REQUIRE(t3>=t1);
  REQUIRE(t4>=t1);
  REQUIRE(t5>=t1);
}

TEST_CASE("Comparison <="){
  Time t1{14,50,30};
  Time t2{14,50,20};//lower seconds
  Time t3{14,40,30};//lower minutes
  Time t4{13,50,20};//lower hours
  Time t5{14,50,30};//equal time
  REQUIRE(t2<=t1);
  REQUIRE(t3<=t1);
  REQUIRE(t4<=t1);
  REQUIRE(t5<=t1);
}


TEST_CASE("output <<"){
  Time t{14,47,34};
  std::stringstream ss{};
  ss << t;
  std::string str = "14:47:34\n";
  std::string sstr = ss.str();
  REQUIRE(str.compare(sstr) == 0);
}

TEST_CASE("input >>"){
  Time t{};
  std::stringstream ss{"14:47:34"};
  ss >> t;
  REQUIRE(t.hours==14);
  REQUIRE(t.minutes==47);
  REQUIRE(t.seconds==34);
}
