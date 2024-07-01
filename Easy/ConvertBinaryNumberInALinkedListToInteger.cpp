class Solution {

public:
    int getDecimalValue(ListNode* head) {
        int ans=0;
        while(head!=nullptr){
            ans = (ans<<1) | head->val;
            head= head->next;
        }
        return ans;
    }
};

************************************************************************************************************************************************************************************************************************
second Approach
class Solution {

private:
    void reverse(ListNode* &head){
        ListNode* pre= nullptr;
        ListNode* curr= head;
        ListNode* next= nullptr;
        while(curr!=nullptr){
            next= curr->next;
            curr->next= pre;
            pre= curr;
            curr= next;
        }
        head= pre;
    }
public:
    int getDecimalValue(ListNode* head) {
        reverse(head);
        int ans=0;
        int mul=1;
        while(head!=nullptr){
            ans+= head->val*mul;
            mul*=2;
            head= head->next;
        }
        return ans;
    }
};
