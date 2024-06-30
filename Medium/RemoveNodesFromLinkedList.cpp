class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        if (!head) return head;
        head = reverseList(head);
        ListNode* maxNode = head;
        ListNode* curr = head->next;
        ListNode* prev = head;
        while (curr != nullptr) {
            if (curr->val < maxNode->val) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else {
                maxNode = curr;
                prev = curr;
                curr = curr->next;
            }
        }
        return reverseList(head);
    }
};
