// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/discuss/1888546/C%2B%2B-trivial-O(n)-solution-%3A)

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int pairSum(ListNode *head)
{

    ListNode *tail = head;

    vector<int> temp;

    while (tail != NULL)
    {
        temp.push_back(tail->val);
        tail = tail->next;
    }

    int i = 0, j = temp.size() - 1;
    int max_sum = -1;

    while (i < j)
    {
        max_sum = max(max_sum, (temp[i++] + temp[j--]));
    }

    return max_sum;
}

int max_sum = 0;
ListNode *s = NULL;

void find_sum(ListNode *p)
{

    if (p == NULL)
        return;

    find_sum(p->next);

    // backtracking
    max_sum = max(max_sum, (p->val + s->val));

    s = s->next;
}

int pairSum2(ListNode *head)
{
    s = head;

    find_sum(head);

    return max_sum;
}

int main()
{
    // make a linked list with struct ListNode
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    // head->next->next->next->next = new ListNode(3);

    cout << pairSum2(head) << endl;

    return 0;
}