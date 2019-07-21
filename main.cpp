#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:
Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL

Example 2:
Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL

Note:

    The relative order inside both the even and odd groups should remain as it was in the input.
    The first node is considered odd, the second node even and so on ..
 */
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



