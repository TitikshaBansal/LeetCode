class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre= nullptr;
        ListNode* curr= head;
        ListNode* next= nullptr;
        while(curr!= nullptr){
            next= curr->next;
            curr->next= pre;
            pre= curr;
            curr=next;
        }
        return pre;
        
    }
};
