# Multiples of 3 and 5

Challenge at https://www.hackerrank.com/contests/projecteuler/challenges/euler001/problem

**Time to solve (metric to improve on in the future!):** 1hr10min -> 5 minutes analyzing first attempt (bruteforce solution), 10 minutes writing and debugging first attempt, 10 minutes researching second attempt, 50 minutes writing and debugging second attempt -> Should've thought about the (long double) datatype!!

**Date solved:** 4/29/2021

**Score:** 100

**Notes:**

- This looked easy at first and I didn't think to look for a mathematical formula on my first attempt. This was a mistake. I should always research before attempting the problem!!
- I also was in a hurry and didn't explain my code in plain language like I should have to show my thought process.
- The first attempt solution timed out for the longer use-cases. I had to find a more optimal solution. This led me to look for a mathematical formula. Found an equation at https://math.stackexchange.com/questions/9259/find-the-sum-of-all-the-multiples-of-3-or-5-below-1000.
- Debugging the second attempt took forever, I couldn't understand why I kept getting a wrong answer. Turned out when I did division, I was doing `numberOfTerms/2.0f` which yielded a float, which didn't work for really big numbers. Had to use `long double` datatype. Totally overlooked this and was relieved when I discovered it.
