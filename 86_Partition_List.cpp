// https://leetcode.com/problems/partition-list/

// https://leetcode.com/problems/partition-list/discuss/2318027/Single-Pass-O(n)-or-Constant-Space-O(1)-or-Explained!

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

/*
Logic Explained:
    Idea is to create two seperate linked lists,
    1. left : list having values < x and 2. right : list having values >= x

    and at last, just link both of them and return that list

    Time Complexity : O(n)
    Space Complexity : O(1), because we are NOT creating NEW Nodes, we are just borrowing Nodes from input list only and just rearranging them
*/

ListNode *partition(ListNode *head, int x)
{
    // two dummy nodes for creating two different lists
    // 1. left : has values < x
    // 2. right : has values >= x
    ListNode *left = new ListNode(), *right = new ListNode();

    // heads for left and right
    ListNode *newHead = left, *mid = right;

    while (head)
    {
        // add in left list
        if (head->val < x)
        {
            left->next = head;
            left = left->next;
        }
        // add in right list
        else
        {
            right->next = head;
            right = right->next;
        }
        // move ahead
        head = head->next;
    }

    // linking left list with right list
    left->next = mid->next;
    right->next = NULL;

    // newHead is dummy node, from it's next our list starts
    return newHead->next;
}

int main()
{
    // 1 -> 4 -> 3 -> 2 -> 5 -> 2 -> X
    ListNode *head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    int x = 3;
    ListNode *newHead = partition(head, x);

    while (newHead)
    {
        cout << newHead->val << " -> ";
        newHead = newHead->next;
    }
    cout << "NULL\n";
    return 0;
}