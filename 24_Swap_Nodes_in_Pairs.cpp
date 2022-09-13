// https://leetcode.com/problems/swap-nodes-in-pairs/

// https://leetcode.com/problems/swap-nodes-in-pairs/discuss/2570257/C%2B%2B-Swapping-Nodes-oror-3-Pointers-oror-Simple-code

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

ListNode *swapPairs(ListNode *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;

    ListNode *ans = head->next; // preserving head (after swapping head->next will become new head)

    ListNode *prev = NULL, *curr = head, *nxt = head->next;

    while (curr && curr->next)
    {
        // swapping two nodes
        curr->next = nxt->next;
        nxt->next = curr;

        // maintaining link with the linked list
        if (prev)
            prev->next = nxt;

        // moving 2 steps ahead
        prev = curr;
        curr = curr->next;
        if (!curr)
            break;
        nxt = curr->next;
    }

    return ans;
}

int main()
{
    // 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // 2 -> 1 -> 4 -> 3 -> 5
    ListNode *ans = swapPairs(head);

    while (ans)
    {
        cout << ans->val << " -> ";
        ans = ans->next;
    }
    cout << "NULL\n";
    return 0;
}