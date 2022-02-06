#define CATCH_CONFIG_MAIN
#include "time.h"
#include "catch.hpp"

TEST_CASE("1. Test function is_valid()") {
  current_time valid_time{14, 40, 59};
  current_time invalid_time{25, 61, 120};
  REQUIRE(is_valid(valid_time));
  REQUIRE_FALSE(is_valid(invalid_time));
} 

TEST_CASE("2. Test function to_string(); default 24-hour format") {
  current_time time{15, 20, 40};
  bool is_twelve{false};
  REQUIRE(to_string(time, is_twelve).length() == 8);
} 

TEST_CASE("3. Test function to_string(); 12-hour format") {
  current_time time{21, 10, 55};
  bool is_twelve{true};
  REQUIRE( to_string(time, is_twelve).length() == 11 );
} 

TEST_CASE("4. Test function is_am()") {
  current_time time1{15, 25, 40};
  REQUIRE(is_am(time1) == false);
  current_time time2{04, 25, 40};
  REQUIRE(is_am(time2) == true);
} 

TEST_CASE("5. Test + and -") {
  current_time time1{};
  REQUIRE(to_string((time1+5),true) == "12:00:05 am" );
  REQUIRE(to_string(time1,true) == "12:00:00 am" );
  REQUIRE(to_string((time1-61),false) == "23:58:59" );
  REQUIRE(to_string(time1,true) == "12:00:00 am" ); 
  current_time time3{23, 59, 59};
  REQUIRE(to_string((time3+126),true) == "12:02:05 am" );
}  

TEST_CASE("6. Test PREFIX ++ and --") {
  current_time time{23,59,59};
  REQUIRE(to_string(time,true) == "11:59:59 pm");
  REQUIRE(to_string(++time,true) == "12:00:00 am");
  REQUIRE(to_string(time,true) == "12:00:00 am");
  REQUIRE(to_string(--time,true) == "11:59:59 pm");
}

TEST_CASE("7. Test POSTFIX ++ and operator--") {
  current_time time{23,59,59};
  REQUIRE(to_string(time,false) == "23:59:59");
  REQUIRE(to_string(time++,false) == "23:59:59");
  REQUIRE(to_string(time,false) == "00:00:00");
  REQUIRE(to_string(time--,false) == "00:00:00");
  REQUIRE(to_string(time,false) == "23:59:59");
}

TEST_CASE("8. Test comparison operators") {
  current_time time1{15, 02, 55};
  current_time time2{18, 20, 10};
  REQUIRE((time1<time2));                       
  REQUIRE_FALSE((time1>time2)); 
  REQUIRE_FALSE((time1==time2));
  REQUIRE((time1!=time2));
  REQUIRE((time1<=time2));
  REQUIRE_FALSE((time1>=time2));


  //TODO: Your tests for your comparison operators are still
//insufficient. You have to check that they can return true and false
//respectively. For example you have to check that time1 < time2 as
//well as !(time2 < time1). You have to make sure that your functions
//can return both true and false depending on the input.


  REQUIRE(!(time2 < time1));
  REQUIRE((time1 < time2));
  REQUIRE((time2 > time1));
  REQUIRE(!(time1 > time2));


  REQUIRE(!(time1==time2));
  REQUIRE((time1!=time2));
  REQUIRE((time1<=time2));
  REQUIRE(!(time1>=time2));
} 

TEST_CASE("9. Test print time") {
  current_time time {12, 12, 12};
  std::ostringstream oss;
  oss << time;
  std::string str = oss.str();
  REQUIRE(str == "12:12:12");
}

TEST_CASE("10.Test >>") {    
  std::istringstream iss{"16:10:35"}; 
  current_time time{};
  iss >> time;
  REQUIRE(time.hour==16);
  REQUIRE(time.minute==10);
  REQUIRE(time.second==35);
  std::istringstream iss1{"25:10:35"};
  iss1 >> time;
  REQUIRE(time.hour==16);
  REQUIRE(time.minute==10);
  REQUIRE(time.second==35);

  REQUIRE_FALSE(iss.fail());
  REQUIRE(iss1.fail());
} 

TEST_CASE("11. Test to_string") {
  current_time time1{01, 01, 01};
  REQUIRE(to_string(time1, true)=="01:01:01 am");
  REQUIRE(to_string(time1, false)=="01:01:01");
  current_time time2{14, 14, 14};
  REQUIRE(to_string(time2, true)=="02:14:14 pm");
  REQUIRE(to_string(time2, false)=="14:14:14");
} 