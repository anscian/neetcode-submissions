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

        while(head){
            cpy.push_back(new Node(head->val));
            cpy.back()->next = head;
            tmp = head->next;
            head->next = cpy.back();
            head = tmp;
        }

        for(auto &node: cpy){
            node->random = node->next->random;
            if(node->random) node->random = node->random->next;
        }

        for(int i = 1; i < cpy.size(); i++){
            cpy[i - 1]->next->next = cpy[i]->next;
            cpy[i - 1]->next = cpy[i];
        }
        cpy.back()->next = cpy.back()->next->next = NULL;

        return cpy[0];
    }
};
