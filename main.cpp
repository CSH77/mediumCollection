#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // ListNode* p1 = head;
        // ListNode* p2 = head;

        ListNode* cur = head;
        ListNode* next = NULL;
        ListNode* prev = head;

        int indexCount = 0;
        //get endIndex
        while(cur)
        {
            cur = cur->next;
            indexCount++;
        }
        cur = head;
        int targetCount = indexCount - n;
        int currentIndexCount = 0;
        while(currentIndexCount < targetCount)
        {
            prev = cur;
            cur = cur->next;
            currentIndexCount++;
        }
        ListNode* deleteNode = NULL;

        if(cur == head) //if head needs to be deleted
        {
            deleteNode = cur;
            cur = cur->next;
            head = cur;
            delete deleteNode;
        }
        else
        {
            deleteNode = cur;
            prev->next = cur->next;
            delete deleteNode;
        }

        return head;

    }
};
int main()
{

    vector<int> nodeValues = {1,2,3,4,5};

    ListNode* head = new ListNode(0);
    ListNode* node = head;

    for(auto n : nodeValues)
    {
        node->next = new ListNode(n);
        node = node->next;
    }

    node = head;
    node = node->next;

    while(node)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;

    node = head;
    node = node->next;

    Solution obj;
    node = obj.removeNthFromEnd(node, 2);

    while(node)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;



    return 0;
}



