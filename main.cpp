#include <iostream>
#include <set>
#include <vector>
#include <stack>

using namespace std;

/*
Given a binary tree, return the inorder traversal of its nodes' values.
Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        TreeNode* treeNode = root;
        vector<int> treeNodeValueVec;
        stack<TreeNode*> stk;

        while(treeNode || !stk.empty() )
        {
            while(treeNode)
            {
                stk.push(treeNode);
                treeNode =treeNode->left;
            }

            treeNode = stk.top();
            treeNodeValueVec.push_back(treeNode->val);
            stk.pop();

            treeNode = treeNode->right;
        }

        return treeNodeValueVec;
    }
};

int main()
{
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    node1->right = node2;
    node2->left = node3;

    Solution obj;
    vector<int> answer = obj.inorderTraversal(node1);

    for(int n : answer)
    {
        cout << n << " ";
    }
    cout << endl;


    return 0;
}
