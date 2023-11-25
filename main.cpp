#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


struct Node
{
    Node* next;
    int val;

    Node(int v, Node* n = nullptr) : val(v), next(n){}
};

int main()
{
    Node* virHead = new Node(0);
    Node* cur = virHead;
    cur->next = new Node(1);
    cur = cur->next;

    cur->next = new Node(2);
    cur = cur->next;

    cur->next = new Node(3);
    cur = cur->next;

    cur = virHead->next;
    while(cur)
    {
        cout << cur->val << ", ";
        cur = cur->next;
    }
    cout << endl;

    //reverse linked list.
    cur = virHead->next;
    Node* tail = cur;
    Node* prev = virHead;
    Node* next = cur;

    while(cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    tail->next = nullptr;
    cur = prev;

    cout << "reverse linkedList" << endl;
    while(cur)
    {
        cout << cur->val << ", ";
        cur = cur->next;
    }
    cout << endl;

    return 0;
}



