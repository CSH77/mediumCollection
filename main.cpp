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
        ListNode* currentPtr = head;
        ListNode* oddPtrHead = new ListNode(0);
        ListNode* evenPtrHead = new ListNode(0);
        ListNode* oddPtr = oddPtrHead;
        ListNode* evenPtr = evenPtrHead;

        int count = 1;
        while(currentPtr != NULL)
        {
            if(count % 2 == 0)
            {
                evenPtr->next = currentPtr;
                evenPtr = evenPtr->next;
                // evenPtr->next = NULL;
            }
            else
            {
                oddPtr->next = currentPtr;
                oddPtr = oddPtr->next;
                // oddPtr->next = NULL;
            }
            count++;
            currentPtr = currentPtr->next;
        }
        evenPtr->next = NULL;
        oddPtr->next = NULL;

        ListNode* delNode = evenPtrHead;
        evenPtrHead = evenPtrHead->next;
        delete delNode;

        oddPtr->next = evenPtrHead; //add odd and even together

        delNode = oddPtrHead;
        oddPtrHead = oddPtrHead->next;
        delete delNode;

        return oddPtrHead;
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



