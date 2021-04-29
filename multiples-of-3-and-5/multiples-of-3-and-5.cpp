// Challenge at https://www.hackerrank.com/contests/projecteuler/challenges/euler001/problem
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
#define smallerNumber 3
#define largerNumber 5

// following equation Sum = numberOfTerms/2 * (numberOfTerms+1); source https://math.stackexchange.com/questions/9259/find-the-sum-of-all-the-multiples-of-3-or-5-below-1000
long getSumOfTerms(long numberOfTerms) {
    return (numberOfTerms/((long double)2.0)) * (numberOfTerms+1);
}

long findSumOfMultiplesOfNumber(long number) {
    #if DEBUG
        std::cout<<"Number is " <<number<<std::endl;
    #endif
    
    long sum = 0;
    long numberOfTermsForSmallerNumber = std::floor((number-1) / smallerNumber);
    long numberOfTermsForLargerNumber = std::floor((number-1) / largerNumber);
    long numberOfTermsForMultipleOfBothNumbers = std::floor((number-1) / (largerNumber*smallerNumber));
    
    #if DEBUG
        std::cout<<"numberOfTermsForSmallerNumber  " <<numberOfTermsForSmallerNumber<<std::endl;
        std::cout<<"numberOfTermsForMultipleOfBothNumbers  " <<numberOfTermsForLargerNumber<<std::endl;
        std::cout<<"numberOfTermsForMultipleOfBothNumbers  " <<numberOfTermsForLargerNumber<<std::endl;
    #endif
    
    long sumForSmallerNumber = smallerNumber*getSumOfTerms(numberOfTermsForSmallerNumber);
    long sumForLargerNumber = largerNumber*getSumOfTerms(numberOfTermsForLargerNumber);
    long sumForMultipleOfBothNumbers = (largerNumber*smallerNumber)*getSumOfTerms(numberOfTermsForMultipleOfBothNumbers);
    
    
    #if DEBUG
        std::cout<<"sumForSmallerNumber  " <<sumForSmallerNumber<<std::endl;
        std::cout<<"sumForLargerNumber  " <<sumForLargerNumber<<std::endl;
        std::cout<<"sumForMultipleOfBothNumbers  " <<sumForMultipleOfBothNumbers<<std::endl;
    #endif
    
    sum = sumForSmallerNumber + sumForLargerNumber - sumForMultipleOfBothNumbers;
    
    return sum;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        std::cout << 
            findSumOfMultiplesOfNumber(n)
            <<std::endl;
    }
    return 0;
}