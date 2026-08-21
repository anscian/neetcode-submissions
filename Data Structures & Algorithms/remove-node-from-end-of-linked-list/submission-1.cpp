/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1, *p2, *prev;

        p1 = p2 = head;
        prev = NULL;
        while (n--) p2 = p2->next;
        while (p2)  prev = p1, p1 = p1->next, p2 = p2->next;

        if (!prev) return p1->next;
        prev->next = p1->next;
        return head;
    }
};
