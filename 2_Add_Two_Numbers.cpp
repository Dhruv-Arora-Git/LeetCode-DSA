// https://leetcode.com/problems/add-two-numbers/

// https://leetcode.com/problems/add-two-numbers/discuss/1925992/Not-a-messy-Code-or-Simple-to-understand-(-)

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

void InsertAtTail(ListNode *&head, ListNode *&tail, int data)
{
    ListNode *temp = new ListNode(data);

    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
        tail->next = NULL;
    }
}

ListNode *sum(ListNode *l1, ListNode *l2)
{
    int carry = 0;
    ListNode *head = NULL, *tail = head;

    while (l1 != NULL or l2 != NULL or carry > 0)
    {
        int ele1 = 0;
        int ele2 = 0;

        if (l1 != NULL)
            ele1 = l1->val;
        ;

        if (l2 != NULL)
            ele2 = l2->val;

        int sum = ele1 + ele2 + carry;

        int digit = sum % 10;

        carry = sum / 10;

        InsertAtTail(head, tail, digit);

        if (l1 != NULL)
            l1 = l1->next;
        if (l2 != NULL)
            l2 = l2->next;
    }

    return head;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{

    ListNode *l3 = sum(l1, l2);

    return l3;
}

int main()
{
    ListNode *head = new ListNode(2);
    head->next = new ListNode(4);
    head->next->next = new ListNode(9);

    ListNode *head2 = new ListNode(5);
    head2->next = new ListNode(6);
    head2->next->next = new ListNode(4);
    head2->next->next->next = new ListNode(9);

    ListNode *l3 = addTwoNumbers(head, head2);

    while (l3 != NULL)
    {
        cout << l3->val << " -> ";
        l3 = l3->next;
    }
    cout << "NULL" << '\n';
    return 0;
}