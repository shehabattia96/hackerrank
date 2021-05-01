# Even Fibonacci Numbers

Challenge at https://www.hackerrank.com/contests/projecteuler/challenges/euler002/problem

**Time to solve (metric to improve on in the future!):** 1hr15mins => Finding relevant equations and deriving a calculation method: 30 minutes, 15 minutes writing solution, 30 minutes trying to fix floating point precision errors

**Date solved:** 4/30/2021

**Score:** 100

**Analysis:**

- Fibonacci numbers: 1,2,3,5,8,13,21,34...
  - Every 3rd number after 2 is an even number
  - A good chart at https://www.goldennumber.net/fibonacci-series/
- The formula for finding the sum of even numbered fibonacci:  `sum = F(3n+2)−1 / 2`. where 3n is the last even numbered term. (https://math.stackexchange.com/questions/323058/closed-form-for-the-sum-of-even-fibonacci-numbers)
- The fibonacci series exhibits the convergence phenomenon where the sequence approximates Phi and the Golden Ratio (phi=1.618033988749895) https://www.goldennumber.net/fibonacci-series/
  - From there we can find the `nth fibonacci number = phi^n/sqrt(5)` where n is the nth fibonacci term and phi=1.618033988749895
- So what we want to do is combine the two equations.
  - let's say our max number is 10, we should find the index of the closest even prime number, so we could do 10*sqrt(5)*log(phi) ~= n.
    - The equation to find n closest to the number is `n = 1.67228 - 2.07809*log(1/x)` where x is the fibonacci number we want to find the closest index (n) to.
      - Or `x = phi^n/sqrt(5)` -> `log(x) = n log(phi)-log(sqrt(5))` -> `n = (log(x)+log(sqrt5))/log(phi)`
  - Then we'd find the closest even fibonnaci number by flooring the result to the nearest multiple of 3.

**Post-solving Notes:**

- implementing the equations was pretty straightforward. Had to use powl and floorl, etc.. to make sure the output is long, but otherwise it was easy.
- ran into floating point precision issues with my approach using math equations. This wasn't something I thought about at all. The float point issues only start happening at 10^16 zero's. There's a pretty good explanation and table of the results here: [https://medium.com/@TheZaki/project-euler-2-even-fibonacci-numbers-2219e9438970](https://medium.com/@TheZaki/project-euler-2-even-fibonacci-numbers-2219e9438970)
  - Fixed the floating point precision issues by sticking to CMath library functions. For some reason I was using `std::sqrt(5)` to calculate the sqrt. Changing that to `sqrtl(5)` fixed all rounding issues.
- I'm happy that I didn't try to brute-force a solution and did some research before attempting the code. Using long double here made me think to use the appropriate powl and ceill,etc.. functions.
