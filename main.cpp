#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool check(TreeNode* node, TreeNode* min, TreeNode* max)
    {
        if(!node)
            return true;

        if(min != NULL && min->val >= node->val)
            return false;

        if(max != NULL && max->val <= node->val)
            return false;

        return check(node->left, min, node ) && check(node->right, node, max);
    }


    bool isValidBST(TreeNode* root) {
        return check(root, NULL, NULL);
    }
};

int main()
{
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node6 = new TreeNode(6);

    node5->left = node1;
    node5->right = node4;
    node4->left = node3;
    node4->right = node6;

    Solution obj;
    cout << obj.isValidBST(node3) << endl;

    return 0;
}



