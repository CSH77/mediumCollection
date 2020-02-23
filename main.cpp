#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;


//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //two pointer method,
        ListNode* head = new ListNode(0);
        ListNode* cur = head;

        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        while(l1)
        {
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;
        }

        while(l2)
        {
            cur->next = l2;
            l2 = l2->next;
            cur = cur->next;
        }

        return head->next;

    }
};

int main()
{
    ListNode* l1 = new ListNode(0);
    ListNode* cur = l1;
    cur->next = new ListNode(1);
    cur = cur->next;
    cur->next = new ListNode(2);
    cur = cur->next;
    cur->next = new ListNode(4);
    cur = cur->next;

    ListNode* l2 = new ListNode(0);
    cur = l2;
    cur->next = new ListNode(1);
    cur = cur->next;
    cur->next = new ListNode(3);
    cur = cur->next;
    cur->next = new ListNode(4);
    cur = cur->next;

    l1 = l1->next;
    l2 = l2->next;

    Solution obj;
    ListNode* answer = obj.mergeTwoLists(l1, l2);

    while(answer)
    {
        cout << answer->val << " ";
        answer = answer->next;
    }

    return 0;
}



