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
    void reorderList(ListNode* head) {
        if (!head->next) return;
        
        ListNode *st, *end, *mid;
        ListNode *prev, *tmp;

        st = mid = end = head;
        while (end->next) {
            end = end->next;
            if (end->next) end = end->next;
            mid = mid->next;
        }

        prev = NULL;
        while (mid) {
            tmp = mid->next;
            mid->next = prev;
            prev = mid;
            mid = tmp;
        }

        tmp = end;
        while (true) {
            if (tmp == st) {
                if (tmp == end->next) break;
                tmp = end->next;
                end->next = st;
                end = tmp;
            }
            else {
                if (tmp == st->next) break;
                tmp = st->next;
                st->next = end;
                st = tmp;
            }
        }
    }
};
