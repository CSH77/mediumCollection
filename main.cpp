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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* iterA = headA;
        ListNode* iterB = headB;

        int sizeA = 0, sizeB = 0;

        while(iterA != NULL)
        {
            iterA = iterA->next;
            sizeA++;
        }
        while(iterB != NULL)
        {
            iterB = iterB->next;
            sizeB++;
        }

        iterA = headA;
        iterB = headB;

        if(sizeA > sizeB)
        {
            int diff = sizeA - sizeB;

            for(int i = 0; i < diff; i++)
            {
                iterA = iterA->next;
            }
        }
        else if(sizeA < sizeB)
        {
            int diff = sizeB - sizeA;

            for(int i = 0; i < diff; i++)
            {
                iterB = iterB->next;
            }
        }

        while(iterA != NULL && iterB != NULL)
        {
            if(iterA == iterB)
                return iterA;

            iterA = iterA->next;
            iterB  = iterB->next;
        }

        return NULL;
    };
};

int main()
{
    ListNode* a1 = new ListNode(4);
    ListNode* a2 = new ListNode(1);
    ListNode* c1 = new ListNode(8);
    ListNode* c2 = new ListNode(4);
    ListNode* c3 = new ListNode(5);
    ListNode* b1 = new ListNode(5);
    ListNode* b2 = new ListNode(0);
    ListNode* b3 = new ListNode(1);

    a1->next = a2;
    a2->next = c1;
    c1->next = c2;
    c2->next = c3;
    b1->next = b2;
    b2->next = b3;
    b3->next = c1;

    Solution obj;
    ListNode* answer = obj.getIntersectionNode(a1, b1);
    cout << answer->val << endl;

    return 0;

}



