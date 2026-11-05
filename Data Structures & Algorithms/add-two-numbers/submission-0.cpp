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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res, *p;
        int c = 0;

        #define val(l) (l ? l->val : 0)
        #define next(l) if(l) l = l->next

        for(res = p = new ListNode(); l1 || l2; p = p->next){
            c += val(l1) + val(l2);
            p->next = new ListNode(c % 10);
            c /= 10;
            next(l1);
            next(l2);
        }
        if(c) p->next = new ListNode(c);

        p = res;
        res = p->next;
        delete p;

        return res;
    }
};
