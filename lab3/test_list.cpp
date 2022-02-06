#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "linked_list.h"
#include <string>

TEST_CASE("1. Test insert and print list" ) {
    linked_list list_test{};
    list_test.insert(2);

    REQUIRE(list_test.print_list() == "{ 2 }");

    list_test.insert(5);
    list_test.insert(3);
 
    REQUIRE(list_test.print_list() == "{ 2 3 5 }");
}

TEST_CASE("2. Test remove") {
    linked_list list_test{};
    list_test.insert(2);
    list_test.remove(2);
    REQUIRE(list_test.print_list() == "{ }");

}

TEST_CASE("3. Test at() ") {
    linked_list list_test{};
    list_test.insert(5);
    list_test.insert(2);
    list_test.insert(7);
    REQUIRE(list_test.at(0) == 2);
}

TEST_CASE("4. Test move assignment") {
    linked_list list_test{};
    list_test.insert(3);
    list_test.insert(4);
    list_test.insert(5);
 
    linked_list list_move{};
    list_move = std::move(list_test);
    REQUIRE(list_test.print_list() == "{ }");
    REQUIRE(list_move.print_list() == "{ 3 4 5 }");
}

TEST_CASE("5. Test copy constructor") {
    linked_list list_test{};
    list_test.insert(1);
    list_test.insert(2);
    linked_list list_test_2{list_test};
    REQUIRE(list_test.print_list() == list_test_2.print_list());

    list_test.remove(2);
    REQUIRE(list_test.print_list() != list_test_2.print_list());

    list_test.insert(2);
    REQUIRE(list_test.print_list() == list_test_2.print_list());

    list_test_2.remove(2);
    REQUIRE(list_test.print_list() != list_test_2.print_list());

}

TEST_CASE("6. Test is_empty ") {
    linked_list list_test{};
    list_test.insert(5);
    list_test.insert(2);
    list_test.insert(7);
    
    
    REQUIRE(list_test.is_empty()==false);
    list_test.remove(5);
    list_test.remove(2);
    list_test.remove(7);

    REQUIRE(list_test.is_empty());
}

TEST_CASE("7. Test empty list") {
    linked_list list_test{};
    REQUIRE(list_test.is_empty());
    list_test.remove(2);
    REQUIRE(list_test.is_empty());
    REQUIRE(list_test.at(2) == NULL);

}