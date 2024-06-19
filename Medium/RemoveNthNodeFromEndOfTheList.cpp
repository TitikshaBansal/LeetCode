class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *start = new ListNode();
        start->next = head;
        ListNode *temp1 = start;
        ListNode *temp2 = start;

        // Move temp1 n+1 steps ahead to maintain a gap of n between temp1 and temp2
        for (int i = 0; i <= n; ++i) {
            temp1 = temp1->next;
        }

        // Move temp1 to the end, maintaining the gap
        while (temp1 != nullptr) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        // Remove the nth node from the end
        ListNode *toDelete = temp2->next;
        temp2->next = temp2->next->next;

        // Update the head in case the first node was removed
        ListNode *newHead = start->next;
        return newHead;
        
    }
};
