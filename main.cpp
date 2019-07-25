#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int num = 0) : value(num), left(NULL), right(NULL){}
};

void traverseTree(TreeNode* node)
{
    if(node == NULL)
        return;

    traverseTree(node->left);
    cout << node->value << " ";
    traverseTree(node->right);
};

int treeHeight(TreeNode* node)
{
    if(node == NULL)
        return 0;

    int lHeight = treeHeight(node->left);
    int rHeight = treeHeight(node->right);

    if(lHeight > rHeight)
        return lHeight + 1;
    else
        return rHeight + 1;
};

void printGivenLevel(TreeNode* node, int level)
{
    if(node == NULL)
        return;

    if(level == 1)
        cout << node->value << " ";
    else
    {
        printGivenLevel(node->left, level -1);
        printGivenLevel(node->right, level -1);
    }
};

void printLevelOrder(TreeNode* node)
{
    int height = treeHeight(node);

    for(int i = 1; i <= height; i++)
    {
        printGivenLevel(node, i);
        cout << endl;
    }
}

void printLevelOrderReverse(TreeNode* node)
{
    int height = treeHeight(node);

    for(int i = height; i > 0; i--)
    {
        printGivenLevel(node, i);
        cout << endl;
    }

}


void printLevelOrderQueue(TreeNode* node)
{
    if(node == NULL)
        return;

    queue<TreeNode*> que;

    que.push(node);

    while(!que.empty())
    {
        node = que.front();
        cout << node->value << " ";
        que.pop();
        if(node->left != NULL)
            que.push(node->left);

        if(node->right != NULL)
            que.push(node->right);

    }
}


bool iter(TreeNode* node, TreeNode* min, TreeNode* max)
{
    if(node == NULL)
        return true;

    if(min != NULL && min->value >= node->value)
        return false;

    if(max != NULL && max->value <= node->value)
        return false;

    return iter(node->left, min, node) && iter(node->right, node, max);
}


bool isValidBST(TreeNode* root) {
    return iter(root, NULL, NULL);
}



int main()
{
/*
    //TreeNode
       1
     2   3
    4 5 6
 */
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    // node3->left = node5;
    node3->right = node6;

    // traverseTree(node1);
    // cout << endl;
    // cout << treeHeight(node1) << endl;

    // printGivenLevel(node1, 3);
    // cout << endl;

    // cout << "print Level Order: " << endl;
    // printLevelOrderReverse(node1);
    // cout << endl;

    printLevelOrderQueue(node1);

    return 0;
}