// Challenge at https://www.hackerrank.com/contests/projecteuler/challenges/euler002/problem
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
 

#define DEBUG false

#if DEBUG
    #include <iomanip> // for output manipulator std::setprecision()
#endif

using namespace std;

const long double phi = (1 + sqrtl(5)) / 2;
long findEvenFibonacciSum(long lastTerm) {
    // first we want to find the index of the fibonacci number closest to the last term using formula `n = (log(x)+log(sqrt5))/log(phi)`
    long fibonacciIndexClosestToLastTerm = floorl((logl(lastTerm)+logl(sqrtl(5)))/logl(phi));
    // then we want to find the closest number that's a multiple of 3
    long fibonacciIndexMultipleOf3 = fibonacciIndexClosestToLastTerm - fibonacciIndexClosestToLastTerm % 3;
    // then we find the fibonacci number that's (fibonacciIndexMultipleOf3 + 2)
    long fibonacciIndexMultipleOf3Plus2 = fibonacciIndexMultipleOf3 + 2;
    // then find the fibonacci sequence at n using the golden rule
    long fibonacciNumberAtMultipleOf3Plus2 = ceill(powl(phi,fibonacciIndexMultipleOf3Plus2)/sqrtl(5));
    // use sum equation for even numbers
    long sumOfEvenFibonacci = (fibonacciNumberAtMultipleOf3Plus2 - 1) /2;
    #if DEBUG
        std::cout << "lastTerm: " << lastTerm << std::endl;
        std::cout << "fibonacciIndexClosestToLastTerm: " << fibonacciIndexClosestToLastTerm << std::endl;
        std::cout << "fibonacciIndexMultipleOf3: " << fibonacciIndexMultipleOf3 << std::endl;
        std::cout << "fibonacciIndexMultipleOf3Plus2: " << fibonacciIndexMultipleOf3Plus2 << std::endl;
        std::cout << "fibonacciNumberAtMultipleOf3Plus2: "<<std::setprecision(21)  << fibonacciNumberAtMultipleOf3Plus2 << std::endl;
        std::cout << "sumOfEvenFibonacci: " << sumOfEvenFibonacci << std::endl;
    #endif
    return sumOfEvenFibonacci;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++) {
        long n;
        cin >> n;
        std::cout << findEvenFibonacciSum(n) << std::endl;
    }
    return 0;
}