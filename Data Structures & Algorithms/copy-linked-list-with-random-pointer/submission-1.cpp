/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        vector<Node *> cpy;
        Node *tmp;
        int n, i;

        n = 0;
        while(head){
            cpy.push_back(new Node(head->val));
            cpy[n]->next = head;
            tmp = head->next;
            head->next = cpy[n++];
            head = tmp;
        }

        for(auto &node: cpy){
            node->random = node->next->random;
            if(node->random) node->random = node->random->next;
        }

        for(i = 1; i < n; i++){
            cpy[i - 1]->next->next = cpy[i]->next;
            cpy[i - 1]->next = cpy[i];
        }
        cpy[i - 1]->next = cpy[i - 1]->next->next = NULL;

        return cpy[0];
    }
};
