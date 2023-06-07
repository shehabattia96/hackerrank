#include <cassert>
#include <string>
#include <vector>

using namespace std;

namespace Utils
{
    int getDistanceBetweenLetters(char letter1, char letter2)
    {
        int distance = int(letter1) - int(letter2);
        if (distance > 0)
        {
            return distance - 26;
        }
        return distance;
    }

    int isWordASuccessiveSequence(string &string1, string &string2)
    {
        if (string1.length() != string2.length())
            return false;

        int previousDistance = getDistanceBetweenLetters(string1.at(0), string2.at(0));
        for (int index = 1; index < string1.length(); index++)
        {

            int currentDistance = getDistanceBetweenLetters(
                string1.at(index), string2.at(index));

            if (previousDistance != currentDistance)
                return false;

            previousDistance = currentDistance;
        }
        return true;
    }
};

using namespace Utils;

class Tests
{
public:
    void testGetDistanceBetweenLetters()
    {
        assert((getDistanceBetweenLetters('a', 'b') == -1));
        assert((getDistanceBetweenLetters('a', 'y') == getDistanceBetweenLetters('b', 'z')));
    }

    void testIsWordASuccessiveSequence()
    {
        string word1 = "abc";
        string word2 = "xyz";
        assert(isWordASuccessiveSequence(word1, word2));
    }

    void runAllTests()
    {
        testGetDistanceBetweenLetters();
        testIsWordASuccessiveSequence();
    }
};
class Solution
{
    /*
    "az" can becomde "ba", but "ab" cannot become "ba".
    We need the abilities to:
    1. get the distance between letters in consecutive words
        e.g. "ab" -> "ba", a to b is +1, b to a is -1
    2. the distance should be the same for all the letters in the first word.
    */
public:
    vector<vector<string>> groupStrings(vector<string> &strings)
    {

        // Tests().runAllTests();

        vector<vector<string>> groups;

        for (string &word : strings)
        {
            bool isWordAddedToAGroup = false;
            for (int groupIndex = 0; groupIndex < groups.size(); groupIndex++)
            {

                if (isWordASuccessiveSequence(word, groups[groupIndex][0]))
                {
                    groups[groupIndex].push_back(word);
                    isWordAddedToAGroup = true;
                    break;
                }
            }
            if (!isWordAddedToAGroup)
            {
                groups.push_back({word});
            }
        }

        return groups;
    }
};