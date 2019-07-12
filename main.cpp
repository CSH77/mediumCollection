#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* temp = new ListNode(0);
        ListNode* head = temp;
        int carryOver = 0;
        int currentNumber = 0;
        while(l1 != NULL && l2 != NULL)
        {
            currentNumber = 0;
            if( carryOver )
            {
                currentNumber = carryOver;
            }

            currentNumber += l1->val + l2->val;
            carryOver = currentNumber / 10;
            currentNumber = currentNumber % 10;

            temp->next = new ListNode(currentNumber);
            temp = temp->next;

            l1 = l1->next;
            l2 = l2->next;

        }

        while(l1 != NULL)
        {
            currentNumber = 0;
            if( carryOver )
                currentNumber = carryOver;

            currentNumber += l1->val;
            carryOver = currentNumber / 10;
            currentNumber = currentNumber % 10;

            temp->next = new ListNode(currentNumber);
            temp = temp->next;
            l1 = l1->next;
        }

        while(l2 != NULL)
        {
            currentNumber = 0;
            if( carryOver )
                currentNumber = carryOver;

            currentNumber += l2->val;
            carryOver = currentNumber / 10;
            currentNumber = currentNumber % 10;

            temp->next = new ListNode(currentNumber);
            temp = temp->next;
            l2 = l2->next;
        }

        if(carryOver)
            temp->next = new ListNode(carryOver);

        ListNode* del = head;
        head = head->next;
        delete del;

        return head;
    }
};

int main()
{
    ListNode* head;
    ListNode* l1 = new ListNode(2);
    head = l1;
    head->next = new ListNode(4);
    head = head->next;
    head->next = new ListNode(3);
    head = head->next;

    // ListNode* l2 = new ListNode(5);
    // head = l2;
    // head->next = new ListNode(6);
    // head = head->next;
    // head->next = new ListNode(4);
    // head = head->next;

    ListNode* l2 = new ListNode(5);
    head = l2;
    head->next = new ListNode(6);
    head = head->next;
    head->next = new ListNode(9);
    head = head->next;
    head->next = new ListNode(9);
    head = head->next;

    Solution obj;
    ListNode* nodeList = obj.addTwoNumbers(l1, l2);

    while(nodeList != NULL)
    {
        cout <<  nodeList->val << " ";
        nodeList = nodeList->next;
    }
    cout << endl;

    return 0;
}



