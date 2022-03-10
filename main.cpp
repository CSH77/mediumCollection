#include <iostream>
#include <set>
#include <vector>
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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* node = root;

        stack<TreeNode*> stk;
        //stk.push(root);

        int count = 1;

        while(node || !stk.empty())
        {
            while(node)
            {
                stk.push(node);
                node = node->left;
            }

            node = stk.top();
            stk.pop();

            if(count == k)
                return node->val;

            node = node->right;
            count++;

        }

        return 0;
    }
};

int main()
{

    TreeNode* node5 = new TreeNode(5);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node1 = new TreeNode(1);

//        5
//       / \
//      3   6
//     / \
//    2   4
//   /
//  1

    node5->left = node3;
    node5->right = node6;
    node3->left = node2;
    node3->right = node4;
    node2->left = node1;

    Solution obj;
    cout << obj.kthSmallest(node5, 4);


    return 0;
}



