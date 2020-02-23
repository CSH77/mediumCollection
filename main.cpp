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
    bool isPalindrome(ListNode* head) {
        if(!head)
            return true;

        if(!head->next)
            return true;

        int numNodes = 0;
        ListNode* cur = head;
        while(cur)
        {
            numNodes++;
            cur = cur->next;
        }

        cur = head;
        stack<ListNode*> stk;
        int currentIndex = 0;
        while(currentIndex < numNodes / 2)
        {
            stk.push(cur);
            currentIndex++;
            cur = cur->next;
        }

        if(numNodes % 2 != 0) //if odd number of nodes, skip one to ignore to compare middle node
            cur = cur->next;

        //compare
        while(cur)
        {
            int numToCompare = stk.top()->val;
            stk.pop();
            if(numToCompare != cur->val)
                return false;

            cur = cur->next;
        }
        return true;
    }
};

int main()
{
    ListNode* l1 = new ListNode(0);
    ListNode* cur = l1;

    cur->next = new ListNode(1);
    cur = cur->next;
    cur->next = new ListNode(0);
    cur = cur->next;
    // cur->next = new ListNode(1);
    // cur = cur->next;

    ListNode* l2 = new ListNode(0);
    cur = l2;
    cur->next = new ListNode(1);
    cur = cur->next;
    cur->next = new ListNode(2);
    cur = cur->next;
    cur->next = new ListNode(2);
    cur = cur->next;
    cur->next = new ListNode(1);
    cur = cur->next;

    l1 = l1->next;
    l2 = l2->next;

    Solution obj;
    cout << obj.isPalindrome(l1); //false ;
    // cout << obj.isPalindrome(l2); //true ;



    return 0;
}



