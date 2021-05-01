// challenge at https://www.hackerrank.com/challenges/grading/problem
#include <bits/stdc++.h>

#define debug false

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

#define minimumRoundingGrade 38
// checks if grade is greater than the minimum AND the remainder is greater than 3.
int roundUpGrade(int grade) {
    int remainderToFive = 5 - grade % 5;
        
    grade = grade >= minimumRoundingGrade && remainderToFive < 3 ?
                 grade + remainderToFive : grade;

    return grade;
}

vector<int> gradingStudents(vector<int> grades) {
    for (int& grade : grades ) {
        #if debug
            std::cout << "grade: " << grade << std::endl;
        #endif
            
        grade = roundUpGrade(grade);
            
        #if debug
            std::cout << "grade after rounding: " << grade << std::endl << std::endl;
        #endif
    }
    return grades;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string grades_count_temp;
    getline(cin, grades_count_temp);

    int grades_count = stoi(ltrim(rtrim(grades_count_temp)));

    vector<int> grades(grades_count);

    for (int i = 0; i < grades_count; i++) {
        string grades_item_temp;
        getline(cin, grades_item_temp);

        int grades_item = stoi(ltrim(rtrim(grades_item_temp)));

        grades[i] = grades_item;
    }

    vector<int> result = gradingStudents(grades);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
