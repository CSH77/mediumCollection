#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool helper(TreeNode* left, TreeNode* right)
    {
        if(left == NULL && right == NULL)
            return true;

        if(left && right && left->val == right->val)
        {
            return helper(left->left, right->right)
                 && helper(left->right, right->left);
        }

        return false;

    }

    bool isSymmetric(TreeNode* root) {

        return helper(root,root);
    }
};

int main()
{
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(2);
    TreeNode* node4 = new TreeNode(3);
    TreeNode* node5 = new TreeNode(4);
    TreeNode* node6 = new TreeNode(4);
    TreeNode* node7 = new TreeNode(3);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;

    Solution obj;
    cout << obj.isSymmetric(node1);


    return 0;
}



