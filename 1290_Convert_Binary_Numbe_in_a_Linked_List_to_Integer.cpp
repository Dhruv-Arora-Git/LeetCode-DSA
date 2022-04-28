// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/discuss/1989422/Recursion-C%2B%2B-Simple-Code-with-Commented-Explanation-(love_love)

#include <iostream>
#include <math.h>

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

int decimal = 0; // answer
int cnt = 0;     // to know we are at which bit / Node

void traverse(ListNode *head)
{
    if (head == NULL)
        return;

    traverse(head->next);

    // now, we have each node of linked list stored in the system stack (using recursion)
    // now, we can easily traverse from left to right

    // if value of head is 1, add pow(2 , cnt) to answer (decimal) and increment cnt
    if (head->val == 1)
        decimal += pow(2, cnt++); // cnt will keep track of ith bit

    else // just increase cnt and move to next node
        ++cnt;
}
int getDecimalValue(ListNode *head)
{
    traverse(head);

    return decimal;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(1);

    // [1,0,1,0,1]
    cout << getDecimalValue(head);
    return 0;
}

// Example - [1, 1, 0 ,1]
// System stack will have [ 1, 0, 1, 1
// 1. if(head->val == 1) decimal += pow(2, 0); // cnt = 0 for first time
// 2. if(head->val == 1) decimal += pow(2, 1); // cnt = 1 for second time
// 3. else ++cnt // cnt = 2
// 4. if(head->val == 1) decimal += pow(2, 2); // cnt = 3 for second time