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

#define DEBUG false

long long findPrimeNumberByDivision(long long N) {
    if (N < 2) return N;

    long long largestPrimeFactor = 1;

    long long tempN = N;
    
    // Reduce even numbers from N
    while (tempN % 2 == 0) {
        largestPrimeFactor = 2;
        tempN /= 2; 
    }

    // Divide by odd numbers until we reach sqrt(tempN), which should be an odd number
    long long oddNumber = 3;
    for (; oddNumber <= floorl(sqrtl(tempN)); oddNumber+=2) {
        while (tempN % oddNumber == 0) {
            largestPrimeFactor = oddNumber;
            tempN /= oddNumber;
        }
    }

    // catch the scenario where we didn't find any matching oddNumbers because we're using sqrt(tempN). e.g. N=10, tempN = 5, largestPrimeFactor=2 when it should be 5 (which is tempN):
    largestPrimeFactor = tempN != 1 ? tempN : largestPrimeFactor; 

    #if DEBUG
        std::cout << "N: " << N << std::endl;
    #endif
    return largestPrimeFactor;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long long n;
        cin >> n;
        std::cout << findPrimeNumberByDivision(n) << std::endl;
    }
    return 0;
}