#ifndef __FIB_HPP
#define __FIB_HPP

#include <stdexcept>

class FibonacciSolver
{
    private:
        FibonacciSolver() = default;

    public:
        FibonacciSolver(const FibonacciSolver& other) = delete;
        FibonacciSolver& operator = (const FibonacciSolver& other) = delete;

        static FibonacciSolver& getInstance()
        {
            static FibonacciSolver object;
            return object;
        }
        
        int getNthFibonacciNumber(int n)
        {
            if(n < 0)
                throw std::invalid_argument("n must be non-negative");

            int a = 1, b = 0, c = 0;
            for (int i = 1; i <= n; i++)
            {
                c = a + b;
                a = b;
                b = c;
            }

            return c;
        }
    
};

#endif
