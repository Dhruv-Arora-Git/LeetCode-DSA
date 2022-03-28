// https://leetcode.com/problems/linked-list-cycle/

// https://leetcode.com/problems/linked-list-cycle/discuss/1890503/Very-Simple-Clean-Code-C%2B%2B-or-O(1)-space-2-Pointer

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

bool hasCycle(ListNode *head)
{

    ListNode *slow = head, *fast = head;

    while (slow and fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

int main()
{
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = new ListNode(5);
    // make a cycle
    head->next->next->next->next->next = head->next->next;

    cout << hasCycle(head) << '\n';
    return 0;
}