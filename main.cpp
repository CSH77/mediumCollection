#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* head;
    void deleteNode(ListNode* node) {

        ListNode* cur = head;
        ListNode* prev = cur;
        ListNode* next = cur;

        ListNode* deleteNode = NULL;

        while(cur)
        {
            if(cur == node)
            {
                deleteNode = cur;
                next = cur->next;

                prev->next = next;
                delete deleteNode;
                break;
            }
            prev = cur;
            cur = cur->next;
        }
    }
};

int main()
{
    vector<int> nodeVal = {4,5,1,9};

    //create linkedList
    ListNode* node = new ListNode(0);
    ListNode* head = node;
    ListNode* targetNode = NULL;
    int delNodeVal = 5; //delete node 5;

    for(auto n : nodeVal)
    {
        node->next = new ListNode(n);
        node = node->next;
        if(n == delNodeVal)
            targetNode = node;
    }

    node = head;
    ListNode* delNode = node;
    node = node->next;
    head = node;
    delete delNode;

    while(node)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
    node = head;

    //delete node 5;
    Solution obj;
    obj.head = node;
    obj.deleteNode(targetNode);

    while(node)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;

    return 0;
}



