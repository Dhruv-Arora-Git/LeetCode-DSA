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

int main()
{

    return 0;
}