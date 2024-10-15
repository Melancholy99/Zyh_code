#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head = nullptr, *tail = nullptr;
    int carry = 0;
    while (l1 || l2)
    {
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;
        int sum = n1 + n2 + carry;
        if (!head)
        {
            head = tail = new ListNode(sum % 10);
        }
        else
        {
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }
        carry = sum / 10;
        if (l1)
        {
            l1 = l1->next;
        }
        if (l2)
        {
            l2 = l2->next;
        }
    }
    if (carry > 0)
    {
        tail->next = new ListNode(carry);
    }
    return head;
}

ListNode *addTwoNumbers1(ListNode *l1, ListNode *l2, int carry = 0)
{
    if (l1 == nullptr && l2 == nullptr)
        return carry ? new ListNode(carry) : nullptr;
    if (l1 == nullptr)
        swap(l1, l2);
    carry += l1->val + (l2 ? l2->val : 0);
    l1->val = carry % 10;
    l1->next = addTwoNumbers1(l1->next, (l2 ? l2->next : nullptr), carry / 10);
    return l1;
}