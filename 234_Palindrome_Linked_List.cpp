// https://leetcode.com/problems/palindrome-linked-list/

// https://leetcode.com/problems/palindrome-linked-list/discuss/1923879/A-Unique-Recursive-Solution-or-Simple-Logic-(-)

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

ListNode *p = NULL;

void helper(ListNode *head, bool &isPalin)
{
    if (head == NULL)
        return;

    helper(head->next, isPalin);

    if (p->val != head->val)
    {
        isPalin = false;
        return;
    }
    p = p->next;
}

bool isPalindrome(ListNode *head)
{
    p = head;
    bool isPalin = true;
    helper(head, isPalin);

    return isPalin;
}

int main()
{

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next = new ListNode(1);

    cout << isPalindrome(head) << '\n';
    return 0;
}