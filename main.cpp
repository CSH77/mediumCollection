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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if(!root)
            return answer;

        stack<TreeNode*> stk;
        TreeNode* node = root;
        // stk.push(node);

        while(!stk.empty() || node != NULL)
        {
            while(node)
            {
                stk.push(node);
                // cout << node->val << " " ; //preorder print here.
                node = node->left;
            }

            //node is NULL at this point
            node = stk.top();
            cout << node->val << " " ; //inorder print here
            stk.pop();
            node = node->right;
        }
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
    vector<vector<int>> answer = obj.levelOrder(node3);

    // for(vector<int> v : answer)
    // {
    //     for(int n : v)
    //     {
    //         cout << n << " ";
    //     }
    //     cout << endl;
    // }


    return 0;
}



