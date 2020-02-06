#include <iostream>
#include <vector>
#include <set>
#include <stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        //use iterative method,

        stack<TreeNode*> stk;
        TreeNode* node = root;
        bool flag = false;

        while(!stk.empty()|| node != NULL)
        {
            while(node != NULL)
            {
                stk.push(node);
                node = node->left;
            }

            //node is NULL at this point,
            node = stk.top();
            stk.pop();
            if(flag)
                return node;

            if(node == p)
                flag = true;
            // if(flag)
            //     cout << node->val << " ";
            node = node->right;
        }
        return node;
    }
};

int main()
{
    // TreeNode* node2 = new TreeNode(2);
    // TreeNode* node1 = new TreeNode(1);
    // TreeNode* node3 = new TreeNode(3);
    // node2->left = node1;
    // node2->right = node3;

    TreeNode* node5 = new TreeNode(5);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node1 = new TreeNode(1);
    node5->left = node3;
    node5->right = node6;
    node3->left = node2;
    node3->right = node4;
    node2->left = node1;


    Solution obj;
    TreeNode* answer = obj.inorderSuccessor(node5, node6 ); //expect NULL
    // TreeNode* answer = obj.inorderSuccessor(node5, node3 ); //expect node4

    if(!answer)
        cout << "NULL" << endl;
    else
        cout << answer->val << endl;


    return 0;
}



