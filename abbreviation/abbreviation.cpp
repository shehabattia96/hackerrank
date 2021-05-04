#include <string>
#include <stdio.h>
#include <assert.h> 
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector> 

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

#define DEBUG false

// Note, works only on ascii [A-Za-z]
bool isLowerCase(char letter) {
    return letter >= 97;
}

// convert string a into uppercase. Note, works only on ascii [A-Za-z]
char upperCase(char letter) {
    return isLowerCase(letter) ? letter - 32 : letter;
}

// sanity check
void testUpperCase() {
    assert(upperCase('a') == 'A');
    assert(upperCase('c') == 'C');
    assert(upperCase('z') == 'Z');
    assert(upperCase('Z') == 'Z');
    assert(upperCase('A') == 'A');
    assert(upperCase('C') == 'C');
}

string abbreviationBruteForce(string a, const string b) {
    bool aMatchesB = false;

    int indexA=0, indexB=0;
    size_t lengthB=b.length();
    // we should search all of a
    while (indexA < a.length() && indexB > -1) {
        char currentLetterA = a.at(indexA);
        char currentLetterAUpper = upperCase(currentLetterA);
    
        char currentLetterB = b.at(indexB >= lengthB ? lengthB-1 : indexB);

        // if lowercase, move on to the next letter in a (since we can remove it)
        if (isLowerCase(currentLetterA)) {
            indexA++;

            // if they match, move on to the next letter in B
            if (currentLetterAUpper == currentLetterB) 
                indexB+= indexB<lengthB? 1 : 0;
        } else {
            // we found an uppercase letter in A, we should rollback B until we match A
            while (currentLetterAUpper != currentLetterB) {
                indexB--;
                if (indexB < 0) break; // if we've rolled back past 0, no matches are found.
                
                currentLetterB = b.at(indexB >= lengthB ? lengthB-1 : indexB);
            }
            if (indexB < 0) break; // if we've rolled back past 0, no matches are found, exit function.
            indexA++;
            indexB+= indexB<lengthB? 1 : 0;
        }
    }

    // if we reached the end of A (implied) and B, then they match
    if (indexB == lengthB) aMatchesB = true;
    
    return (aMatchesB ? "YES" : "NO");
}

int main(int argc, char** argv)
{
    #if DEBUG
        testUpperCase();
    #endif

    char* filePath = getenv("OUTPUT_PATH");
    if (argc > 0) filePath = argv[1];

    #if DEBUG
        std::cout << "results path: " << filePath << std::endl;
    #endif


    ofstream fout(filePath);

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        #if DEBUG
            std::cout << "reading: " << q_itr << std::endl;
        #endif
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviationBruteForce(a, b);

        #if DEBUG
            std::cout<< "result: " << result << std::endl;
        #endif

        fout << result << "\n";
    }

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
