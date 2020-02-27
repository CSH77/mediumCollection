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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* head = new ListNode(0);
        ListNode* node = head;

        int sum = 0;
        int carryOver = 0;
        while(l1 && l2)
        {
            int sum = l1->val + l2->val + carryOver;
            carryOver = sum / 10;
            sum = sum % 10;

            node->next = new ListNode(sum);
            node = node->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1)
        {
            sum = l1->val + carryOver;
            carryOver = sum / 10;
            sum = sum % 10;
            node->next = new ListNode(sum);
            node = node->next;

            l1 = l1->next;
        }

        while(l2)
        {
            sum = l2->val + carryOver;
            carryOver = sum / 10;
            sum = sum % 10;
            node->next = new ListNode(sum);
            node = node->next;
            l2 = l2->next;
        }

        if(carryOver)
        {
            node->next = new ListNode(carryOver);
            node = node->next;
        }

        node = head;
        ListNode* delNode = node;
        node = node->next;
        delete delNode;

        return node;
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
    head->next = new ListNode(4);
    head = head->next;
    // head->next = new ListNode(9);
    // head = head->next;

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



