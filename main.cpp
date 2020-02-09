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
    Node* connect(Node* root) {
        if(root == NULL)
            return NULL;

        Node* node = root;
        while(node->left != NULL)
        {
            Node* temp = node;
            while(temp)
            {
                temp->left->next = temp->right;
                if(temp->next)
                    temp->right->next = temp->next->left;

                temp = temp->next;
            }
            node = node->left;
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

    answer = node4;
    while(answer != NULL)
    {
        cout << answer->val << " ";
        answer = answer->next;
    }

    // while(answer != NULL)
    // {
    //     cout << answer->val << " ";
    //     answer = answer->next;
    // }



    return 0;
}