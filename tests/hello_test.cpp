#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hello.hpp"

TEST_CASE( "returns 0" ) {
    REQUIRE( strcmp_case_insensitive("Hi", "hi") == 0 );
}

TEST_CASE( "returns -1" ) {
    REQUIRE( strcmp_case_insensitive("cat", "dog") == -1 );
}

TEST_CASE( "returns 1" ) {
    REQUIRE( strcmp_case_insensitive("two", "one") == 1 );
}

TEST_CASE( "returns -1 for shorter" ) {
    REQUIRE( strcmp_case_insensitive("One", "One Two") == -1 );
}

TEST_CASE( "returns 1 for longer" ) {
    REQUIRE( strcmp_case_insensitive("fizzbuzz", "fizz") == 1 );
}

TEST_CASE( "returns 0 ignoring spaces" ) {
    REQUIRE( strcmp_case_insensitive("My Cool String", "mycoolstring", true) == 0 );
}

TEST_CASE( "returns 0 ignoring more spaces" ) {
    REQUIRE( strcmp_case_insensitive("My Cool String", "my co oL    st ring", true) == 0 );
}

TEST_CASE( "returns 1 ignoring spaces" ) {
    REQUIRE( strcmp_case_insensitive("notMy Co  ol  String", "my  coo    lstring", true) == 1 );
}

TEST_CASE( "returns 0 after 5 characters" ) {
    REQUIRE( strcmp_case_insensitive("keyboard", "keybog", false, 5) == 0 );
}

TEST_CASE( "returns 0 after 1 character" ) {
    REQUIRE( strcmp_case_insensitive("a", "ab", false, 1) == 0 );
}

TEST_CASE( "returns 0 after 5 characters for short words with spaces" ) {
    REQUIRE( strcmp_case_insensitive("cat", "c a t", true, 5) == 0 );
}

TEST_CASE( "returns 1 after 5 characters for short words with spaces" ) {
    REQUIRE( strcmp_case_insensitive("dog", "c a t", true, 5) == 1 );
}

TEST_CASE( "returns 0 after 0 characters" ) {
    REQUIRE( strcmp_case_insensitive("keyboard", "keybog", false, 0) == 0 );
}

TEST_CASE( "2 and 50 is Negative" ) {
    REQUIRE( strcmp_case_insensitive("2", "50") == -1);
}

TEST_CASE( "2 and 10 is Negative" ) {
    REQUIRE( strcmp_case_insensitive("2", "10") == -1);
}

TEST_CASE( "20 and 5 is Positive" ) {
    REQUIRE( strcmp_case_insensitive("20", "5") == 1);
}

TEST_CASE( "20 and 1 is Positive" ) {
    REQUIRE( strcmp_case_insensitive("20", "1") == 1);
}

TEST_CASE( "100 and 100 is Zero" ) {
    REQUIRE( strcmp_case_insensitive("100", "100") == 0);
}

TEST_CASE( "2 Some String and 50 Some String is Negative" ) {
    REQUIRE( strcmp_case_insensitive("2 Some String", "50 Some String") == -1);
}

TEST_CASE( "2 Some String and 10 Some String is Negative" ) {
    REQUIRE( strcmp_case_insensitive("2 Some String", "10 Some String") == -1);
}

TEST_CASE( "20 Some String and 5 Some String is Positive" ) {
    REQUIRE( strcmp_case_insensitive("20 Some String", "5 Some String") == 1);
}

TEST_CASE( "20 Some String and 1 Some String is Positive" ) {
    REQUIRE( strcmp_case_insensitive("20 Some String", "1 Some String") == 1);
}

TEST_CASE( "100 Some String and 100 Some String is Zero" ) {
    REQUIRE( strcmp_case_insensitive("100 Some String", "100 Some String") == 0);
}
