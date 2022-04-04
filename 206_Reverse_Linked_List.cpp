// https://leetcode.com/problems/reverse-linked-list/

// https://leetcode.com/problems/reverse-linked-list/discuss/1879300/3-Pointers-iterative-solution-explained-with-Commented-Visualisation

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

ListNode *reverseList(ListNode *head)
{

    struct ListNode *p = head, *q = NULL, *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    head = q;

    return head;

    // 0 means NULL
    // r  q  p
    // 0  0  1 -> 2 -> 3 -> 4 -> 5

    //    r  q  p
    // 0  0  1 -> 2 -> 3 -> 4 -> 5
    // q->next = r (NULL)

    //        r   q    p
    // 0  0 <-1   2 -> 3 -> 4 -> 5
    // q->next = r (1)

    //             r    q    p
    // 0  0 <-1 <- 2 <- 3 -> 4 -> 5
    // q->next = r (2)

    //                  r    q    p
    // 0  0 <-1 <- 2 <- 3 <- 4 -> 5 -> NULL
    // q->next = r (3)

    //                      r    q    p
    // 0  0  1 <- 2 <- 3 <- 4 <- 5   NULL
    // q->next = r (4)

    // now P == NULL , LL is reversed
}

ListNode *reverseList2(ListNode *head)
{

    ListNode *prev = NULL, *curr = head;

    while (curr != NULL)
    {
        ListNode *nxt = curr->next;

        curr->next = prev;
        prev = curr;

        curr = nxt;
    }

    return prev;
}

int main()
{
    // make a linked list with struct ListNode
    // 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode *new_head = reverseList2(head);
    // 5 -> 4 -> 3 -> 2 -> 1 -> NULL
    while (new_head != NULL)
    {
        cout << new_head->val << " -> ";
        new_head = new_head->next;
    }
    cout << "NULL" << '\n';
    return 0;
}