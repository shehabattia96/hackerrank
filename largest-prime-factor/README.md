# Largest Prime Factor

Challenge at https://www.hackerrank.com/contests/projecteuler/challenges/euler003/problem

**Time to solve (metric to improve on in the future!):** 2hrs -> 1hr researching existing prime-factor finding algorithms, 30 minutes trying to implement Fermat's algorithm, only to realize it doesn't inherently provide a solution. 30 minutes writing a bruteforce solution by calculating division by 2 and odd numbers (which proved to be the most sure way to find prime factors) and debugging for timeout errors.

**Date solved:** 5/1/2021

**Score:** 100

**Analysis:**

- I feel like there should be a math formula for finding the largest prime factor.
  - Apprantly there several ways, ~~one of them is [Fermat's Factorization](https://en.wikipedia.org/wiki/Fermat's_factorization_method)~~ (this proved to be a good way of finding factors, but not prime factors, and not necessarily the greatest factor).
    - For a number N, first take the square root and ceil the result (save as `a`)
      - then calculate `b^2=a^2-N`. If `b` is an integer, `a+b` is the largest factor of N.
    - This method returns the largest factor, but it's not necessarily prime. So this doesn't work without checking if the solution is prime. This has a worst case O(n) which is higher than what we can afford for 10^2.
- Finding prime numbers up to 10^2 is computationally expensive.. We could use a database of prime numbers (http://www.primos.mat.br/2T_en.html) but we'd have to build the infrastructure for that.
- There is the option of brute forcing division by 2 and then odd numbers. Let's go with this option.
  - Tried this method, which worked great for smaller numbers but took too long for 10^12
  - Then instead bruteforcing odd numbers until N, I did sqrt(N) and made sure oddNumbers ran at least once.
- 10^12 needs long long datatype

**Post-solving Notes:**

- I underestimated the problem and jumped to implement Fermat's algorithm without thinking ahead to what the algorithm would yield. This was a product of "trusting" that someone has solved this before and that I should take their word for which algo to use. I should not do this in the future, I should think the problem through. I wasted a lot of time.
- Brute forcing turned out to be OK here. Brute-forcing isn't always bad. I almost wanted to give up on this problem because I couldn't think of a "smart" approach to solving it and didn't just want to write loops. I think it turned out OK when the loops are not O(n) but where shortened by crumching a subset of the needed solutions and extrapolating the rest.
