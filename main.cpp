#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* node = root;
        stack<TreeNode*> stk;
        vector<int> answer;

        while(!stk.empty() || node != NULL)
        {
            while(node) //go left, add node to stack
            {
                stk.push(node);
                node = node->left;
            }

            //node is NULL at this point.
            node = stk.top();
            stk.pop();
            answer.push_back(node->val);

            node = node->right;
        }
        return answer;

    }
};

int main()
{
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node9 = new TreeNode(9);
    TreeNode* node20 = new TreeNode(20);
    TreeNode* node15 = new TreeNode(15);
    TreeNode* node7 = new TreeNode(7);

    node3->left = node9;
    node3->right = node20;
    node20->left = node15;
    node20->right = node7;

    Solution obj;
    vector<int> answer = obj.inorderTraversal(node3);

    for(auto v : answer)
        cout << v << " ";
    cout << endl;

    return 0;
}



