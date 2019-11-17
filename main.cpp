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

    //if right subtree is exist, min node of the right subtree is the successor
    TreeNode* findMinNode(TreeNode* root)
    {
        if(!root)
            return NULL;

        TreeNode* node = root;
        //find minimum node from right subtree
        if(node->right)
        {
            //find minimum node
            while(node->left)
                node = node->left;
        }
        return node;
    }

    //if right subtree is not exist, find successor from top,
    //if currentNode is bigger than given node, mark as successor
    TreeNode* findSuccessorFromTop(TreeNode* root, TreeNode* node)
    {
        if(!node || !root)
            return NULL;

        TreeNode* current = root;
        TreeNode* successor;

        while(current)
        {
            if(node->val < current->val)
            {
                successor = current;
                current = current->left;
            }
            else
                current = current->right;
        }

        return successor;
    }


    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        //if right subtree is exist, find minimum node from right subtree
        if(p->right)
            return findMinNode(p);
        else
            return findSuccessorFromTop(root, p);
    }

    void inOrder(TreeNode* root)
    {
        if(!root)
            return;

        TreeNode* node = root;
        stack<TreeNode*> stk;

        while(node != NULL || !stk.empty())
        {
            while(node)
            {
                stk.push(node);
                node = node->left;
            }

            node = stk.top();
            stk.pop();
            cout << node->val << " ";
            node = node->right;
        }

    }
};



int main()
{
    // TreeNode* node20 = new TreeNode(20);
    // TreeNode* node8 = new TreeNode(8);
    // TreeNode* node22 = new TreeNode(22);
    // TreeNode* node4 = new TreeNode(4);
    // TreeNode* node4 = new TreeNode(12);
    // TreeNode* node10 = new TreeNode(10);
    // TreeNode* node14 = new TreeNode(14);

    shared_ptr<TreeNode> node20(new TreeNode(20));
    shared_ptr<TreeNode> node8(new TreeNode(8));
    shared_ptr<TreeNode> node22(new TreeNode(22));
    shared_ptr<TreeNode> node4(new TreeNode(4));
    shared_ptr<TreeNode> node12(new TreeNode(12));
    shared_ptr<TreeNode> node10(new TreeNode(10));
    shared_ptr<TreeNode> node14(new TreeNode(14));

    node20->left = node8.get();
    node20->right = node22.get();
    node8->left = node4.get();
    node8->right = node12.get();
    node12->left = node10.get();
    node12->right = node14.get();


    Solution obj;
    // obj.inOrder(node20.get());
    TreeNode* node = obj.inorderSuccessor(node20.get(), node14.get() );
    cout << node->val << endl;


    return 0;
}




