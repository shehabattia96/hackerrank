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
#define firstNumber 3
#define secondNumber 5


int findSumOfMultiplesOfNumber(int number) {
    #if DEBUG
        std::cout<<"Number is " <<number<<std::endl;
    #endif
    
    int sum = 0;
    int divisorOfNumberAndFirstNumber = std::floor((number-1) / firstNumber);
    int divisorOfNumberAndSecondNumber = std::floor((number-1) / secondNumber);
    
    int counter = 1;
    for (; counter <= divisorOfNumberAndSecondNumber; counter++) {
        int newMultipleOfFirstNumber = firstNumber * counter;
        int newMultipleOfSecondNumber = secondNumber * counter;
        sum += newMultipleOfFirstNumber;
        // make sure to not add the same number twice:
        if (newMultipleOfSecondNumber%firstNumber!=0) sum+=newMultipleOfSecondNumber;
    } 
    
    for (; counter <= divisorOfNumberAndFirstNumber; counter++) 
        sum += firstNumber * counter;
    
    #if DEBUG
        std::cout<<"sum is " <<sum<<std::endl;
    #endif
    
    return sum;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        std::cout << 
            findSumOfMultiplesOfNumber(n)
            <<std::endl;
    }
    return 0;
}