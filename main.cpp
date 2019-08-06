#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*
    Input: root = [2,1,3], p = 1
    Output: 2
    Explanation: 1's in-order successor node is 2. Note that both p and the return value is of TreeNode type.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* res = nullptr;

        auto cur = root;
        while (cur)
        {
            if(cur->val > p->val)
            {
                res=cur;
                cur=cur->left;
            }
            else
            {
                cur = cur->right;
            }
        }

        return res;
    }
};

int main()
{
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(3);

    node2->left = node1;
    node2->right = node3;

    Solution obj;
    TreeNode* answer = obj.inorderSuccessor(node2, node1 );

    cout << answer->val << endl;


    return 0;
}



