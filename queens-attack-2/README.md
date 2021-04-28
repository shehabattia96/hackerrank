# Queen's Attack 2

Challenge at https://www.hackerrank.com/challenges/queens-attack-2/problem
Time to solve (metric to improve on in the future!): 1hr -> 30 minutes analyzing, 20 minutes writing and debugging, 10 minutes looking at others' solutions and improving mine.
Date solved: 4/28/2021

Notes:

- I liked this problem because it was chess-y in nature!
- At first I was tempted to create a 2D array, but I found an easy solution using vector? math. Analyzing the board for 20 minutes paid off.
- After I found the total number of unobstructed movements, I was tempted to sort the obstacles and go through each one of them one by one. Then I took a step back again and found another mathematical solution.
- After submitting my solution, I got a chance to review others' submissions. I learned that despite the problem giving me a std::vector, I didn't have to use it and I could change the problem to give me an std::set instead, which is more performant since "A single cell may contain more than one obstacle.".
