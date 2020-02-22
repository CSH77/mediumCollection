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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;

    }
};

int main()
{
    ListNode* head = new ListNode(0);
    ListNode* node = head;
    for(int i = 1; i <= 5; i++)
    {
        node->next = new ListNode(i);
        node = node->next;
    }

    node = head;
    node = node->next;

    Solution obj;
    ListNode* answer = obj.reverseList(node);

    while(answer)
    {
        cout << answer->val << " ";
        answer = answer->next;
    }
    cout << endl;


    return 0;
}



