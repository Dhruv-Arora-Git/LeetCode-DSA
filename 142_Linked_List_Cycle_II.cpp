// https://leetcode.com/problems/linked-list-cycle-ii/

// https://leetcode.com/problems/linked-list-cycle-ii/discuss/1894463/C%2B%2B-Slow-and-Fast-Pointers-or-Commented-Explanation

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int cycleLength(ListNode *f, ListNode *s)
{
    int len = 0;
    // as they are in cycle, they will meet again
    // till then, keep moving the pointer and len++
    // when they will meet, the poinert has traversed the cycle fully
    // so len is the length of the list
    do
    {
        s = s->next;
        ++len;
    } while (f != s);

    return len;
}

ListNode *detectCycle(ListNode *head)
{
    if (head == NULL)
        return NULL;

    // checking for cycle
    ListNode *fast = head, *slow = head;

    int len = 0;

    while (fast != NULL)
    {
        fast = fast->next;

        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if (fast == slow)
        {
            len = cycleLength(fast, slow);
            break;
        }
    }

    if (len == 0)
    {
        // no cycle
        return NULL;
    }

    ListNode *p = head;
    ListNode *q = head;

    // move it for length of cycle times
    for (int i = 0; i < len; ++i)
    {
        p = p->next;
    }

    // now, p from head and q from length of cycle will start moving
    // and will meet at that point where cycle start, that will be (p == q)

    while (p != q)
    {
        p = p->next;
        q = q->next;
    }

    return p; // can return q as well, as both are pointing to same node only
}
int main()
{
    // make a linked list with struct ListNode
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    // making a cycle
    // 5 -> 2
    head->next->next->next->next->next = head->next;

    ListNode *new_head = detectCycle(head);

    cout << new_head->val << endl;

    return 0;
}