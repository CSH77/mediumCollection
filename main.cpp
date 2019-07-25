#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void preOrder(int count, vector<vector<int>>& v, queue<TreeNode*> que)
    {
        if(!que.empty())
        {
            queue<TreeNode*> q1;
            vector<int> arr;
            while(!que.empty())
            {
                TreeNode* node = que.front();
                arr.push_back(node->val);
                que.pop();
                if(node->left != NULL) {q1.push(node->left);};
                if(node->right != NULL) {q1.push(node->right);};
            }
            if(count % 2 != 0)
            {
                reverse(arr.begin(), arr.end());
                v.push_back(arr);
            }
            else
            {
                v.push_back(arr);
            }
            preOrder(count + 1, v, q1);
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> v;
        if(root != NULL)
        {
            queue<TreeNode*> que;
            que.push(root);
            preOrder(0, v, que);
        }

        return v;
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
    vector<vector<int>> answer = obj.zigzagLevelOrder(node3);

    for(vector<int> v : answer)
    {
        for(int n : v)
        {
            cout << n << " ";
        }
        cout << endl;
    }


    return 0;
}



