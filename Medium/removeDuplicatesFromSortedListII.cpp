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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr) {
            bool isDuplicate = false;

            while (curr->next && curr->val == curr->next->val) {
                isDuplicate = true;
                ListNode* temp = curr;
                curr = curr->next;
                delete temp;
            }

            if (isDuplicate) {
                ListNode* temp = curr;
                curr = curr->next;
                delete temp;
                continue; 
            }

            prev->next = curr;
            prev = curr;
            curr = curr->next;
        }

        prev->next = nullptr; // Cut off any trailing duplicates
        return dummy->next;
    }
};

// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
