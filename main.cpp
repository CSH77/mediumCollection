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

void preOrderRecursive(TreeNode* node)
{
    if(!node)
        return;

    cout << node->val << " ";
    preOrderRecursive(node->left);
    preOrderRecursive(node->right);
}


class Solution {
public:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,
                     int preorderStart, int preorderEnd,
                     int inorderStart, int inorderEnd)
    {
        if(inorderStart > inorderEnd || preorderStart > preorderEnd)
            return NULL;

        int headValue = preorder[preorderStart];
        TreeNode* node = new TreeNode(headValue);
        int mid = 0;
        for(int i = inorderStart; i <= inorderEnd; i++)
        {
            if(inorder[i] == headValue)
            {
                mid = i;
                break;
            }
        }

        node->left = helper(preorder, inorder,
                            preorderStart + 1, preorderStart + mid - inorderStart, inorderStart, mid - 1
                           );

        node->right = helper(preorder, inorder,
                             preorderStart + mid - inorderStart + 1, preorderEnd,
                             mid + 1, inorderEnd
                            );
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};

int main()
{
    Solution obj;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    TreeNode* node = obj.buildTree(preorder, inorder);

    preOrderRecursive(node);

    return 0;
}



