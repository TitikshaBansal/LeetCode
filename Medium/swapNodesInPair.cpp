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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode dum(0,head);
        ListNode* prev = &dum, *curr = head;

        while(curr && curr->next){
            ListNode* temp = curr->next->next;
            ListNode* temp2 = curr->next;

            temp2->next = curr;
            curr->next = temp;
            prev->next = temp2;

            prev= curr;
            curr = temp;
        }
        return dum.next;
    }
};

// https://leetcode.com/problems/swap-nodes-in-pairs/
