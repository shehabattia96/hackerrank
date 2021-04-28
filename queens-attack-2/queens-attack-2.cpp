// Challenge at https://www.hackerrank.com/challenges/queens-attack-2/problem
#include <bits/stdc++.h>
#include <limits.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 In a 2D array, the number of squares the queen can move is 
Forward: lengthOfSquareBoard - queenRow
Back: queenRow - 1
Right: lengthOfSquareBoard - queenColumn
Left: queenColumn - 1
Forward_Right: min(Forward, Right)
Forward_Left: min(Forward, Left)
Back_Right: min(Back, Right)
Back_Left: min(Back, Left)

Next we must subtract the number of movements blocked by the obstacles.
Firstly we find obstacles in the way. The rule is:
obstacleRow - queenRow == 0 || obstacleCol - queenCol == 0 || abs(obstacleCol - queenCol) - abs(obstacleRow - queenRow) == 0
 */
 
#define DEBUG true

// keeps track of the closest obstacles to the queen.
struct QueensObstacles {
    int Forward = INT_MAX, Back= INT_MAX, Right= INT_MAX, Left= INT_MAX, Forward_Right= INT_MAX, Forward_Left= INT_MAX, Back_Right= INT_MAX, Back_Left= INT_MAX;
};

int queensAttack(int lengthOfSquareBoard, int numberOfObstacles, int queenRow, int queenColumn, set<pair<int,int>> obstacles) {
    int numberOfMovements = 0;
    
    // the total number of possible movements in the following directions:
    int Forward = lengthOfSquareBoard - queenRow;
    int Back = queenRow - 1;
    int Right = lengthOfSquareBoard - queenColumn;
    int Left = queenColumn - 1;
    int Forward_Right = std::min(Forward, Right);
    int Forward_Left = std::min(Forward, Left);
    int Back_Right = std::min(Back, Right);
    int Back_Left = std::min(Back, Left);
    
    // sum the number of unobstructed movements
    numberOfMovements = Forward + Back + Right + Left + Forward_Right + Forward_Left + Back_Right + Back_Left;
    #if DEBUG
        std::cout << "numberOfUnobstructedMovements: " << numberOfMovements << std::endl;
    #endif
    
    if (numberOfObstacles == 0) return numberOfMovements;
    
    // find obstacles in the way
    QueensObstacles obstaclesNearTheQueen;
    for (auto& obstacle : obstacles) {
        int obstacleRow = obstacle.first;
        int obstacleColumn = obstacle.second;
        int obstacleVerticalDistanceFromQueen = obstacleRow - queenRow; // negative to the bottom
        int obstacleHorizontalDistanceFromQueen = obstacleColumn - queenColumn; // negative to the Left
        
        #if DEBUG
            std::cout << "on obstacle: " << obstacleRow << ", " << obstacleColumn << std::endl;
            std::cout << "obstacleVerticalDistanceFromQueen: " << obstacleVerticalDistanceFromQueen << std::endl;
            std::cout << "obstacleHorizontalDistanceFromQueen: " << obstacleHorizontalDistanceFromQueen << std::endl;
        #endif
        // check if obstacle is in the same row, then calculate the horizontal distance
        if (obstacleVerticalDistanceFromQueen == 0)
        {
            if (obstacleHorizontalDistanceFromQueen > 0) obstaclesNearTheQueen.Right = std::min(obstaclesNearTheQueen.Right, obstacleHorizontalDistanceFromQueen);
            else obstaclesNearTheQueen.Left = std::min(obstaclesNearTheQueen.Left, std::abs(obstacleHorizontalDistanceFromQueen));
        }
        // check if obstacle is in the same column, then calculate the vertical distance
        if (obstacleHorizontalDistanceFromQueen == 0)
        {
            if (obstacleVerticalDistanceFromQueen > 0) obstaclesNearTheQueen.Forward = std::min(obstaclesNearTheQueen.Forward, obstacleVerticalDistanceFromQueen);
            else obstaclesNearTheQueen.Back = std::min(obstaclesNearTheQueen.Back, std::abs(obstacleVerticalDistanceFromQueen));
        }
        
        // check if obstacle is on a diagonal
        if (std::abs(obstacleHorizontalDistanceFromQueen)-std::abs(obstacleVerticalDistanceFromQueen) == 0)
        {
            if (obstacleVerticalDistanceFromQueen > 0) { // Front Diagonal
                if (obstacleHorizontalDistanceFromQueen > 0) obstaclesNearTheQueen.Forward_Right = std::min(obstaclesNearTheQueen.Forward_Right, std::min(obstacleHorizontalDistanceFromQueen, obstacleVerticalDistanceFromQueen));
                else obstaclesNearTheQueen.Forward_Left = std::min(obstaclesNearTheQueen.Forward_Left, std::min(std::abs(obstacleHorizontalDistanceFromQueen), obstacleVerticalDistanceFromQueen));
            }
            else { // Back Diagonal
                if (obstacleHorizontalDistanceFromQueen > 0) obstaclesNearTheQueen.Back_Right = std::min(obstaclesNearTheQueen.Back_Right, std::min(obstacleHorizontalDistanceFromQueen, std::abs(obstacleVerticalDistanceFromQueen)));
                else obstaclesNearTheQueen.Back_Left = std::min(obstaclesNearTheQueen.Back_Left, std::min(std::abs(obstacleHorizontalDistanceFromQueen), std::abs(obstacleVerticalDistanceFromQueen)));
            }
        }
    }

    #if DEBUG
        std::cout << "obstaclesNearTheQueen: " << std::endl;
        std::cout << "Forward: " << obstaclesNearTheQueen.Forward << std::endl;
        std::cout << "Back: " << obstaclesNearTheQueen.Back << std::endl;
        std::cout << "Left: " << obstaclesNearTheQueen.Left << std::endl;
        std::cout << "Right: " << obstaclesNearTheQueen.Right << std::endl;
        std::cout << "Forward_Right: " << obstaclesNearTheQueen.Forward_Right << std::endl;
        std::cout << "Forward_Left: " << obstaclesNearTheQueen.Forward_Left << std::endl;
        std::cout << "Back_Left: " << obstaclesNearTheQueen.Back_Left << std::endl;
        std::cout << "Back_Right: " << obstaclesNearTheQueen.Back_Right << std::endl;
    #endif

    numberOfMovements = 
        (obstaclesNearTheQueen.Forward == INT_MAX ? Forward : obstaclesNearTheQueen.Forward - 1) +
        (obstaclesNearTheQueen.Back == INT_MAX ? Back : obstaclesNearTheQueen.Back - 1) +
        (obstaclesNearTheQueen.Left == INT_MAX ? Left : obstaclesNearTheQueen.Left - 1) +
        (obstaclesNearTheQueen.Right == INT_MAX ? Right : obstaclesNearTheQueen.Right - 1) +
        (obstaclesNearTheQueen.Forward_Right == INT_MAX ? Forward_Right : obstaclesNearTheQueen.Forward_Right - 1) +
        (obstaclesNearTheQueen.Forward_Left == INT_MAX ? Forward_Left : obstaclesNearTheQueen.Forward_Left - 1) +
        (obstaclesNearTheQueen.Back_Left == INT_MAX ? Back_Left : obstaclesNearTheQueen.Back_Left - 1) +
        (obstaclesNearTheQueen.Back_Right == INT_MAX ? Back_Right : obstaclesNearTheQueen.Back_Right - 1);
    
    return numberOfMovements;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int r_q = stoi(second_multiple_input[0]);

    int c_q = stoi(second_multiple_input[1]);

    set<pair<int,int>> obstacles;

    for (int i = 0; i < k; i++) {
        // obstacles[i].resize(2);

        string obstacles_row_temp_temp;
        getline(cin, obstacles_row_temp_temp);

        vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));

        obstacles.insert({stoi(obstacles_row_temp[0]),stoi(obstacles_row_temp[1])});
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
