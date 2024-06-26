class Solution {
    private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        if (!head) return nullptr;

        head = reverseList(head);
        ListNode* temp = head;
        int carry = 0;

        // Double each digit and handle carry
        while (temp != nullptr) {
            int doubledValue = temp->val * 2 + carry;
            temp->val = doubledValue % 10;
            carry = doubledValue / 10;
            if (temp->next == nullptr && carry > 0) {
                temp->next = new ListNode(carry);
                carry = 0;
                break;
            }
            temp = temp->next;
        }

        // Reverse the list back to its original order
        head = reverseList(head);
        return head;
    }
};
