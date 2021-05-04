# Candies

Challenge at https://www.hackerrank.com/challenges/candies/problem

**Time to solve (metric to improve on in the future!):** 40mins on initial design + 2hrs for implementing fix for outliers => 10 minutes analyzing the problem, 10 minutes writing out high level process, 10 minutes writing solution, 10 minutes figuring out why only example testcases pass and the other ones are failing. 2hrs implementing a fix for scenarios I missed when designing the problem that weren't pointed out in the original problem!! I should think more broadly about problems, I think I stick too much to the given requirements but that's not always good. I should think more broadly!!

**Date solved:** 5/4/2021

**Score:** 100 (accuracy), times out if we have to do too much forward lookup.

**Analysis:**

- Alice needs to buy a minimum of 10 candies (? first example she only buys 4.. ?) and is trying to minimize the number of candies she buys
  - The number of candies increases based on the local average
    - "when two children have equal rating, they are allowed to have different number of candies."
  - The example given is `ratings = [4,6,4,5,6,2]` and `candies = [1,2,1,2,3,1]`
    - The number of candies is determined based on the `previousValue * weight + nextValue * weight` where weight is how much candy the adjacent candy has gotten.
- At first a sequential approach is inviting, but we may fall into the trap of needing to pre-calculate a slope map. 
  - I can't think of a way to approach this problem without looking at every number, so this will have at least an O(n) solution.
- The formula we need to calculate is
  - `candyStudentRecieves = rating / numCandies`
    - so normally, `num candies = rating / candyStudentReceives` but there are two unknowns.
  - So instead it boils down to:
    - `num_candies = sum(candyStudentReceives(rating))` i.e. the sum of candyStudentReceives as a function of rating.
      - Our function will dictate how much candy student receives based on rating. But it's not the simple, it must take the local gradient into account.
    - If we assume each student receives a minimum of 1 candy
- Numbers can be up to 10^5 so int datatype is sufficient.
- Technically we don't need to create a slope map but it's more readable if you're looking at the code for the first time.

**High level process:**

- diff adjacent numbers and create a slope map
- assign the number of candies based on the slope map
  - The first number is tricky but if the first number in slope map is positive, we'll assign 1, if the number is negative we'll assign 2.
  - Consequent numbers will be the number previously assigned + (positive slope ? +1 : set to 1 && increment by 1 if next slope is negative)

Example:

```python
ratings = [2,4,3,5,2,6,4,5]
slopeMap = [+2,-1,+2,-3,+4,-2,+1]
Since +2 is positive, first candy is 1
candies = [1,2,1,2,1,2,1,2] => it's important to use the number of candies previously assigned based on the slope


ratings = [2,4,2,6,1,7,8,9,2,1]
slopeMap = [+2,-2,+4,-3,+6,+1,+1,-7,-1]
Since +2 is positive, first candy is 1
candies = [1,2,1,2,1,2,3,4,3,2] => however this gives the last two students 1 extra candy each
The rule is to minimize the cost of candies, so if we ever get a negative sign, we set the candy to 1 then we lookahead to the next number, if it's negative we need to give +1 candies to this student. Applying this:
candies = [1,2,1,2,1,2,3,4,2,1] => correct answer 
```

**Post-solving Notes:**

- This was a really easy problem when following the steps described in the problem, and I passed all the test-cases that were supplied. I didn't think of the outlier use-cases in the rest of the challenge when I was designing the problem, so I had to ducktape a lookahead solution and it's pretty inefficient.
  - I genuinely took the time to think about the problem, however, I still didn't think of the use-cases that  ended up failing after the perfect implementation of the initial design. I should spend more time trying to "break" my solution before implementing it.
- I'm happy that I wrote more tests throughout doing this problem.
- long long datatype was necessary. I didn't see it because I didn't think of the lookahead scenario in my original design.
- I feel like the code is a bit messy because I had to add the lookahead piece. But it works! There's definitely more room for optimization but I'm not super interested in this specific problem at the moment.
  - I do want to think about other algorithms like Stochastic descent and see if I could come up with a minimizing solution instead of the solution I implemented.
