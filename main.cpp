#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddNodeHead = new ListNode(0);
        ListNode* evenNodeHead = new ListNode(0);

        ListNode* oddNode = oddNodeHead;
        ListNode* evenNode = evenNodeHead;
        ListNode* current = head;

        int count = 1;
        while(current)
        {
            //odd Node
            if(count % 2 != 0)
            {
                oddNode->next = current;
                oddNode = oddNode->next;
            }
            else
            {
                evenNode->next = current;
                evenNode = evenNode->next;
            }

            current = current->next;
            count++;
        }
        evenNode->next = nullptr;
        oddNode->next = nullptr;

        oddNode->next = evenNodeHead->next; //add even and odd together
        delete evenNodeHead;

        oddNode = oddNodeHead->next;
        delete oddNodeHead;
        return oddNode;

    }
};


int main()
{
    ListNode* head;
    ListNode* l1 = new ListNode(1);
    head = l1;
    head->next = new ListNode(2);
    head = head->next;
    head->next = new ListNode(3);
    head = head->next;
    head->next = new ListNode(4);
    head = head->next;
    head->next = new ListNode(5);
    head = head->next;

    Solution obj;
    ListNode* nodeList = obj.oddEvenList(l1);

    while(nodeList != NULL)
    {
        cout <<  nodeList->val << " ";
        nodeList = nodeList->next;
    }
    cout << endl;

    return 0;
}



