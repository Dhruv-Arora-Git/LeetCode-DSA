// https://leetcode.com/problems/merge-two-sorted-lists/

// https://leetcode.com/problems/merge-two-sorted-lists/discuss/1881644/C%2B%2B-Iterative-Code-or-4ms-Fast

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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{

    if (list1 == NULL and list2 == NULL)
        return NULL;

    if (list1 == NULL)
        return list2;

    if (list2 == NULL)
        return list1;

    ListNode *first = NULL, *last = NULL;

    if (list1->val < list2->val)
    {
        first = list1;
        last = list1;
        list1 = list1->next;
        last->next = NULL;
    }
    else
    {
        first = list2;
        last = list2;
        list2 = list2->next;
        last->next = NULL;
    }

    while (list1 != NULL and list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            last->next = list1;
            last = list1;
            list1 = list1->next;
            last->next = NULL;
        }
        else
        {
            last->next = list2;
            last = list2;
            list2 = list2->next;
            last->next = NULL;
        }
    }

    if (list1 != NULL)
        last->next = list1;
    else if (list2 != NULL)
        last->next = list2;

    return first;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);

    ListNode *head3 = mergeTwoLists(head, head2);

    while (head3 != NULL)
    {
        cout << head3->val << " -> ";
        head3 = head3->next;
    }
    cout << "NULL" << '\n';
    return 0;
}