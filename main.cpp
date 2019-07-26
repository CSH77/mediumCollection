#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node(int num = 0) : val(num), left(NULL), right(NULL), next(NULL){}
};

class Solution {
public:
    Node* answer;
    Node* head;

    void traverseTree(Node* node)
    {
        if(node == NULL)
            return;

        cout << node->val << " ";
        traverseTree(node->left);
        traverseTree(node->right);
    }

    int treeHeight(Node* node)
    {
        if(node == NULL)
            return 0;

        int lHeight = treeHeight(node->left);
        int rHeight = treeHeight(node->right);

        if(lHeight > rHeight)
            return lHeight + 1;
        else
            return rHeight + 1;
    }

    void printGivenLevel(Node* node, int level)
    {
        if(node == NULL)
            return;

        if(level == 1)
        {
            // cout << node->val << " ";
            answer->next = node;
            answer = answer->next;
        }
        else
        {
            printGivenLevel(node->left, level - 1);
            printGivenLevel(node->right, level - 1);
        }
    }

    Node* connect(Node* root) {


        int height = treeHeight(root);

        for(int i = 1; i <= height; i++)
        {
            answer = new Node(0);
            head = answer;

            printGivenLevel(root, i);

            Node* delNode;
            delNode = head;
            head = head->next;
            delete delNode;
        }

        return root;

    }

};


int main()
{
/*
    //Node
       1
     2   3
    4 5 6 7
 */
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;


    Solution obj;
    //obj.traverseTree(node1);
    Node* answer = obj.connect(node1);

    answer = node2;
    while(answer != NULL)
    {
        cout << answer->val << " ";
        answer = answer->next;
    }

    while(answer != NULL)
    {
        cout << answer->val << " ";
        answer = answer->next;
    }



    return 0;
}