#include <string>
#include <stdio.h>
#include <assert.h> 
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector> 

#define DEBUG false

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


vector<int> createSlopeMap(vector<int> numberArray) {
    vector<int> slopeMap;
    for (int counter=0; counter < numberArray.size() - 1; counter++)
        slopeMap.push_back(numberArray[counter+1] -numberArray[counter]);
    return slopeMap;
}

void testCreateSlopeMap() {
    vector<int> slopeMap = createSlopeMap(vector<int>({1,2,3,5,2}));
    vector<int> expectedSlopeMap = vector<int>({1,1,2,-3});
    assert(slopeMap.size() == expectedSlopeMap.size());
    assert(std::equal(slopeMap.begin(), slopeMap.end(), expectedSlopeMap.begin()));
}

long long sumRangeOfNumbers(int lastNumber) {
    return (lastNumber/(long double)2.0)*(1+lastNumber);
}

void testSumRangeOfNumbers() {
    long long sum = sumRangeOfNumbers(10);
    assert(sum == 55);
    sum = sumRangeOfNumbers(100000);
    assert(sum == 5000050000); 
}

long long candies(int numberOfStudents, vector<int> ratings) {
    const vector<int> slopeMap = createSlopeMap(ratings);
    const size_t lengthOfSlopeMap = numberOfStudents - 1;
    #if DEBUG
        vector<int> candiesArray;
    #endif
    long long numCandies;
    // give first student candies
    long numCandyLastStudentReceived = 1;
    // lookahead, if slope is negative, add 1
    long tempNumCandyLastStudentReceived = 1;
    size_t tempSlopeIndex = 0;
    while (tempSlopeIndex < lengthOfSlopeMap) {
        if (slopeMap[tempSlopeIndex] < 0) { 
            tempNumCandyLastStudentReceived++;
            tempSlopeIndex++;
        } else break;
    }
    
    if (numCandyLastStudentReceived < tempNumCandyLastStudentReceived)
        numCandyLastStudentReceived = tempNumCandyLastStudentReceived;
        
    #if DEBUG
        candiesArray.push_back(numCandyLastStudentReceived);
    #endif

    numCandies = numCandyLastStudentReceived;
    
    // long long numberOfDecreasingSlopes = 0;

    for (int slopeIndex=0; slopeIndex < lengthOfSlopeMap; slopeIndex++) {
        const int slopeValue = slopeMap[slopeIndex];
        // if rating increases, increase the number of candies
        if (slopeValue > 0) {
            numCandyLastStudentReceived++;
            // numCandyLastStudentReceived += sumRangeOfNumbers(numberOfDecreasingSlopes) -1;
            // numberOfDecreasingSlopes = 0;
        }
        else {
            // set candies to 1
            numCandyLastStudentReceived = 1;
            
            // // lookahead, if slope is negative, add 1
            // if (slopeIndex < lengthOfSlopeMap-1) {
            //     if (slopeMap[tempSlopeIndex + 1] < 0) { 
            //     numberOfDecreasingSlopes++;
            //     }
            // }
        }
        
        // lookahead: if slope is negative, add 1
        long tempNumCandyLastStudentReceived = 1;
        size_t tempSlopeIndex = slopeIndex + 1;
        while (tempSlopeIndex < lengthOfSlopeMap) {
            if (slopeMap[tempSlopeIndex] < 0) { 
                tempNumCandyLastStudentReceived++;
                tempSlopeIndex++;
            } else break;
        }
        
        if (numCandyLastStudentReceived < tempNumCandyLastStudentReceived)
            numCandyLastStudentReceived = tempNumCandyLastStudentReceived;
        
        #if DEBUG
            candiesArray.push_back(numCandyLastStudentReceived);
        #endif
        numCandies += numCandyLastStudentReceived;
    }
    
    // numCandies += sumRangeOfNumbers(numberOfDecreasingSlopes);
        
    return numCandies;
}

int main(int argc, char** argv)
{
    #if DEBUG
        testCreateSlopeMap();
        testSumRangeOfNumbers();
    #endif

    char* filePath = getenv("OUTPUT_PATH");
    if (argc > 0) filePath = argv[1];

    #if DEBUG
        std::cout << "results path: " << filePath << std::endl;
    #endif

    
    ofstream fout(filePath);

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    long long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
