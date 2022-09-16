#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "D:/doctest.h"
#include "myString.h"

#include <cstring>

TEST_CASE("Test default constructor")
{
    MyString s;

    REQUIRE(s.getSize() == 0);
    REQUIRE(s.empty() == true);
    REQUIRE(s.c_str() == nullptr);
}

TEST_CASE("Test constructor with parameters")
{
    MyString s("ala bala");

    REQUIRE(s.getSize() == 8);
    REQUIRE(s.empty() == false);
    REQUIRE(strcmp(s.c_str(), "ala bala") == 0);
}

TEST_CASE("Test At")
{
    MyString s("ala bala");

    REQUIRE(s.at(2) == 'a');

    s.at(3) = '_';
    REQUIRE(s.at(3) == '_');
    REQUIRE(strcmp(s.c_str(), "ala_bala") == 0);

    REQUIRE_THROWS_AS(s.at(9), std::out_of_range);
}

TEST_CASE("Test operator []")
{
    MyString s("ala bala");

    REQUIRE(s[2] == 'a');

    s[3] = '_';
    REQUIRE(s[3] == '_');
    REQUIRE(strcmp(s.c_str(), "ala_bala") == 0);
}

TEST_CASE("Test front")
{
    MyString s("ala bala");

    REQUIRE(s.front() == 'a');
}

TEST_CASE("Test back")
{
    MyString s("ala bala");

    REQUIRE(s.back() == 'a');
}

TEST_CASE("Test push_back")
{
    MyString s("ala_bala");
    s.push_back('_');

    REQUIRE(strcmp(s.c_str(), "ala_bala_") == 0);
}

TEST_CASE("Test pop_back")
{
    MyString s("ala_bala_");
    s.pop_back();
    
    REQUIRE(strcmp(s.c_str(), "ala_bala") == 0);
}

TEST_CASE("Test operator +=")
{
    MyString s("ala bala");

    s += ' ';
    REQUIRE(strcmp(s.c_str(), "ala bala ") == 0);
    s += "jakdfhk";
    REQUIRE(strcmp(s.c_str(), "ala bala jakdfhk") == 0);
}

TEST_CASE("Test operator ==")
{
    MyString s1("ala bala"), s2("123"), s3(s1);

    REQUIRE(s1 == s3);
    REQUIRE_FALSE(s1 == s2);
}

TEST_CASE("Test operator <")
{
    MyString s1("123"), s2("ala bala");

    REQUIRE(s1 < s2);
}
