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
        Node* temp = head;
        while(temp){
            Node* curr = new Node(temp->val);
            curr->next = temp->next;
            temp->next = curr;
            temp = curr->next;
        }
        temp = head;
        while(temp){
            if (temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        temp =head;
        Node* dummy = new Node(-1);
        Node* t2 = dummy;

        while(temp){
            t2->next = temp->next;
            temp->next = temp->next->next;
            t2 = t2->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};

// https://leetcode.com/problems/copy-list-with-random-pointer/
