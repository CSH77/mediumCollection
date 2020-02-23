#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;


//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)
            return false;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while(slow && fast)
        {
            if(slow == fast)
                return true;

            slow = slow->next;

            if(!fast->next) //jump twice
                return false;
            else
                fast = fast->next->next;
        }

        return false;
    }
};

int main()
{
    cout << "hello world!" << endl;

    return 0;
}



