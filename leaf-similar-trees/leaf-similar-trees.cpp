#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> root1Leaves = getLeaves(root1);
        vector<int> root2Leaves = getLeaves(root2);

        if (root1Leaves.size() != root2Leaves.size())
            return false;

        for (int index = 0; index < root1Leaves.size(); index++)
        {
            if (root1Leaves.at(index) != root2Leaves.at(index))
                return false;
        }
        return true;
    }

private:
    vector<int> getLeaves(TreeNode *root)
    {
        vector<int> leaves;

        stack<TreeNode *> nodes;

        nodes.push(root);

        while (!nodes.empty())
        {
            TreeNode *currentNode = nodes.top();
            nodes.pop();

            if (isLeaf(currentNode))
            {
                leaves.push_back(currentNode->val);
                continue;
            }

            if (currentNode->left != nullptr)
            {
                nodes.push(currentNode->left);
            }
            if (currentNode->right != nullptr)
            {
                nodes.push(currentNode->right);
            }
        }

        return leaves;
    }

    int isLeaf(TreeNode *node)
    {
        return node->left == nullptr && node->right == nullptr;
    }
};