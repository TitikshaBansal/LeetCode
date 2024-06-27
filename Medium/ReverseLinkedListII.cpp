class Solution {
    
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* pre = &dummy;

        for (int i = 1; i < left; ++i) {
            pre = pre->next;
        }

        // Reverse the sublist from `left` to `right`
        ListNode* curr = pre->next;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;

        for (int i = left; i <= right; ++i) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Connect the reversed sublist back to the original list
        pre->next->next = curr;
        pre->next = prev;

        return dummy.next;
    }
};
