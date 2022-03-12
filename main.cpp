#include <iostream>
#include <set>
#include <vector>
#include <memory>
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* node = root;
        stack<TreeNode*> stk;
        // stk.push(node);
        bool nextNodeIsSuccessor = false;
        while(!stk.empty() || node)
        {
            while(node)
            {
                stk.push(node);
                node = node->left;
            }

            node = stk.top();
            stk.pop();

            if(nextNodeIsSuccessor)
                return node;

            if(node == p)
                nextNodeIsSuccessor = true;

            node = node->right;
        }

        return nullptr;
    }
};

int main()
{

    //         5
    //       /   \
    //      3     6
    //     / \
    //    2   4
    //   /
    //  1
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

    // shared_ptr<TreeNode> node20(new TreeNode(20));
    // shared_ptr<TreeNode> node8(new TreeNode(8));
    // shared_ptr<TreeNode> node22(new TreeNode(22));
    // shared_ptr<TreeNode> node4(new TreeNode(4));
    // shared_ptr<TreeNode> node12(new TreeNode(12));
    // shared_ptr<TreeNode> node10(new TreeNode(10));
    // shared_ptr<TreeNode> node14(new TreeNode(14));

    // node20->left = node8.get();
    // node20->right = node22.get();
    // node8->left = node4.get();
    // node8->right = node12.get();
    // node12->left = node10.get();
    // node12->right = node14.get();


    Solution obj;
    // obj.inOrder(node20.get());
    // TreeNode* node = obj.inorderSuccessor(node20.get(), node14.get() );

    TreeNode* root = node5;
    TreeNode* node = obj.inorderSuccessor(root, node6);

    if(node)
        cout << node->val << endl;
    else
        cout << "NULL" << endl;


    return 0;
}




