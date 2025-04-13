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
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // min-heap: higher value has lower priority
        }
    };
    ListNode* sortList(ListNode* head) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        while(head){
            pq.push(head);
            head = head->next;
        }
        ListNode* dummy = new ListNode();
        ListNode* root = dummy;
        while(!pq.empty()){
            ListNode* temp = pq.top();
            pq.pop();
            root->next = temp;
            root= temp;
        }
        root->next = nullptr;
        return dummy->next;
    }
};

// https://leetcode.com/problems/sort-list/
