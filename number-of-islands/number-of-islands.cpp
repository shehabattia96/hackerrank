#include <cassert>
#include <utility>
#include <array>
#include <vector>
#include <map>
#include <queue>
using namespace std;

namespace Utils
{

    enum Directions
    {
        up,
        down,
        left,
        right
    };

    pair<int, int> translateInDirection(pair<int, int> location, Directions direction)
    {
        switch (direction)
        {
        case Directions::up:
            return {location.first, location.second - 1};
        case Directions::down:
            return {location.first, location.second + 1};
        case Directions::left:
            return {location.first - 1, location.second};
        case Directions::right:
            return {location.first + 1, location.second};
        }
    }

    array<pair<int, int>, 4> getAdjacentLocations(pair<int, int> location)
    {
        return {
            translateInDirection(location, Directions::up),
            translateInDirection(location, Directions::down),
            translateInDirection(location, Directions::left),
            translateInDirection(location, Directions::right)

        };
    }

}
using namespace Utils;

class Tests
{
public:
    void testTranslateInDirection()
    {
        assert((translateInDirection({1, 1}, Directions::down) == pair<int, int>(1, 2)));
    }
    void runAllTests()
    {
    }
};

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {

        // Tests().runAllTests();

        int rows = grid.size();
        int columns = grid[0].size();

        int numberOfIslands = 0;

        map<pair<int, int>, bool> visitedNodes;

        queue<pair<int, int>> queue;

        pair<int, int> currentLocation = {0, 0};

        for (int row = 0; row < rows; row++)
        {
            for (int column = 0; column < columns; column++)
            {
                currentLocation = {row, column};

                if (visitedNodes.count(currentLocation) == 1)
                    continue;

                visitedNodes[currentLocation] = true;

                if (isLand(grid, currentLocation))
                {
                    numberOfIslands++;

                    queue.push(currentLocation);

                    while (!queue.empty())
                    {
                        currentLocation = queue.front();
                        queue.pop();

                        auto adjacentLocations = getAdjacentLocations(currentLocation);
                        for (auto &location : adjacentLocations)
                        {

                            if (visitedNodes.count(location) == 1)
                                continue;

                            visitedNodes[location] = true;
                            if (isLand(grid, location))
                            {
                                queue.push(location);
                            }
                        }
                    }
                }
            }
        }

        return numberOfIslands;
    }

private:
    bool isLand(vector<vector<char>> &grid, pair<int, int> location)
    {
        if (location.first >= grid.size() || location.second >= grid[0].size() || location.first < 0 || location.second < 0)
            return false;

        return grid[location.first][location.second] == '1';
    }
};