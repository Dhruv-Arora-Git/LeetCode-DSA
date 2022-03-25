// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

// https://leetcode.com/problems/remove-duplicates-from-sorted-list/discuss/1881721/C%2B%2B-simple-2-pointers-solution

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    ListNode *p = head->next, *q = head;

    // q    p
    // 1 -> 1 -> 2 -> 3 -> 3

    while (p != NULL)
    {
        if (p->val == q->val)
        {
            q->next = p->next;
            // delete p;
            p = p->next;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
    return head;
}

int main()
{

    // make a linked list with struct ListNode
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    ListNode *new_head = deleteDuplicates(head);
    while (new_head != NULL)
    {
        cout << new_head->val << " ";
        new_head = new_head->next;
    }
    cout << endl;

    return 0;
}