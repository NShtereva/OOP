#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "D:/doctest.h"
#include "fib.hpp"

TEST_CASE("Test Fibonacci")
{
    REQUIRE(FibonacciSolver::getInstance().getNthFibonacciNumber(0) == 0);
    REQUIRE(FibonacciSolver::getInstance().getNthFibonacciNumber(1) == 1);
    REQUIRE(FibonacciSolver::getInstance().getNthFibonacciNumber(12) == 144);
    CHECK_THROWS_WITH(FibonacciSolver::getInstance().getNthFibonacciNumber(-3), "n must be non-negative");
}
