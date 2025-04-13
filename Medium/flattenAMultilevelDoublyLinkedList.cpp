/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;

        std::stack<Node*> st;
        Node* curr = head;

        while (curr) {
            // If current has a child
            if (curr->child) {
                // If next exists, push it on stack
                if (curr->next) {
                    st.push(curr->next);
                }
                // Link child
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
            }

            // If next is null and stack is not empty, pop from stack and continue
            if (!curr->next && !st.empty()) {
                curr->next = st.top();
                st.top()->prev = curr;
                st.pop();
            }

            curr = curr->next;
        }

        return head;
    }
};

// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
