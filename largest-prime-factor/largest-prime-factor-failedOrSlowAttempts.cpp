// Attempts that have failed or were too slow for 10^12
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

using namespace std;

#define DEBUG true

/*
For a number N, first take the square root and ceil the result (save as `a`)
then calculate `b^2=a^2-N`. If `b` is an integer, `a+b` is the largest factor of N.

Note: this gives us some factors, but not necessarily prime OR greatest.
*/
long fermatFactorization(long N) {
    long largestPrimeFactor = N;
    if (N%2==0) return N/2;
    long a = ceill(sqrtl(N));
    long bSquare = powl(a,2) - N;
    long double b = sqrtl(bSquare);
    long double bMod1 = fmodl(b, 1.0);
    #if DEBUG
        std::cout << "N: " << N << std::endl;
        std::cout << "a: " << a << std::endl;
        std::cout << "bSquare: " << bSquare << std::endl;
        std::cout << "b: " << b << std::endl;
        std::cout << "bMod1: " << bMod1 << std::endl;
    #endif
    while (bMod1 != 0.0 && a != N) {
        if (a*a == N) return a;
        a++;
        bSquare = powl(a,2) - N;
        b = sqrtl(bSquare);
        bMod1 = fmodl(b, 1.0);
        
    #if DEBUG
        std::cout << "N: " << N << std::endl;
        std::cout << "a: " << a << std::endl;
        std::cout << "bSquare: " << bSquare << std::endl;
        std::cout << "b: " << b << std::endl;
        std::cout << "bMod1: " << bMod1 << std::endl;
    #endif
    }
    largestPrimeFactor = a + b;
    return largestPrimeFactor;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        std::cout << fermatFactorization(n) << std::endl;
    }
    return 0;
}