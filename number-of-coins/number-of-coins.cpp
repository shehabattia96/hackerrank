#include <cassert>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {

        if (amount == 0)
            return 0;

        unordered_map<int, int> numberOfCoins;

        queue<int> intermediateAmounts;
        intermediateAmounts.push(amount);
        numberOfCoins[amount] = 1;

        while (!intermediateAmounts.empty())
        {

            int currentAmount = intermediateAmounts.front();
            intermediateAmounts.pop();

            int currentCoins = numberOfCoins.at(currentAmount);

            for (auto &coin : coins)
            {
                int newAmount = currentAmount - coin;

                if (numberOfCoins.count(newAmount))
                    continue;

                if (newAmount == 0)
                    return currentCoins;

                if (newAmount < 0)
                {
                    numberOfCoins[newAmount] = -1;
                    continue;
                }

                numberOfCoins[newAmount] = currentCoins + 1;
                intermediateAmounts.push(newAmount);
            }
        }

        return -1;
    }
};