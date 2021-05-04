# Abbreviation

Challenge at https://www.hackerrank.com/challenges/abbr/problem

**Time to solve (metric to improve on in the future!):** 40mins (productive) + 2hr25mins ("learning", it was actually wasted) -> 10 minutes analyzing the problem, 10 minutes comparing bruteforce and hashing solutions, 25 minutes researching hashing algorithms only to realize that might not be necessary here, 20 minutes implementing bruteforce solution, 2hrs debugging testcase 12 but failing to get it to run.

**Date solved:** 5/3/2021

**Score:** 75 -> testcases 12 and 14 are not passing and I can't figure out why. I've spent enough time trying to debug, I moved on. Maybe we'll revisit this in the future.

**Analysis:**

- The question is not asking us to transform the first string, but only to identify if we can match the second string.
  - One quick thought is to sum or encode the ascii code of the letters so that the hashing operation guarantees a fingerprint for the letter combination.
- Things to look out for:
  - Only lowercase letters can be manipulated.
  - Repeated sequences of substrings can occur. Most importantly, if a sequence matched with lowercase letters, it can occur with uppercase letters, in which case the latter should be used.
- The length of the string can be up to 1000 characters.
- Hashing might be a smarter way to approach this problem
  - Some hashing algo's:
    - [Polynomial rolling hash](https://www.geeksforgeeks.org/string-hashing-using-polynomial-rolling-hash-function/)
    - [SHA-256](https://www.movable-type.co.uk/scripts/sha256.html)
    - [djb2](http://www.cse.yorku.ca/~oz/hash.html)
      - Although [this person refutes that this is a good algo](http://dmytry.blogspot.com/2009/11/horrible-hashes.html) " "cb" collides with "bC", in the version with addition, and "bA" collides with "ab" when using xor, just to name two examples out of hundreds".
        - Collision might be a big problem here so we should likely avoid using this algo.
  - Although before hashing, we should figure out how to manipulate the lowercase and uppercase strings first.

**Brute-forcing High level process:**

- Substring the second string and search for matching in first string. If letter in first string is lowercase, remove it if necessary

Example

``` txt
a: abcdCdeccDec
b: CDE

substring b: C
remove ab
matching a: c
substring b: CD
matching a: cd
substring b: CDE
matching a: ??
rollback substring b: CD
remove d (abcCdeccDec)
matching a: ??
remove c (abCdeccDec)
matching a: Cd
substring b: CDE
matching a: Cde  => answer!! but there's a captial D at the end, so we're not done
rollback substring b: CD
remove decc (abCDec)
matching a: CDe => answer!!

```

**Post-solving Notes:**

- This was a fun problem, I did well breaking it down from the beginning. Thoughts to improve on in the future:
  - I did well to keep the code small and contained, but it wouldn't hurt to write more tests (e.g. test driven dev). It takes some time when I'm trying to solve these quickly, but I think the overall time will improve.
- I tried to find a solution using hashes. However, hashing would've been an extra step on top of the lowercase letter manipulation, so it's not going to improve performance here.
- I took too long trying to figure out why Testcase 12 wasn't working. I should have spent only 30 minutes then consult/research or move on. But I was frustrated enough that I moved the code from the in-browser editor to VSCode and it got me to write a [gcc script to compile and run the code](./compileAndRun.sh) whiched enabled me to do line debugging, so that'll be handy in the future.
