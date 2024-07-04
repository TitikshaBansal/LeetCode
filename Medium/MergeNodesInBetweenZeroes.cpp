class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp= dummy;
        while(head!=nullptr){
            head= head->next;
            if(head == nullptr) break;
            int num=0;
            while(head->val != 0){
                num+= head->val;
                head= head->next;
            }
            temp->next= new ListNode(num);
            temp = temp->next;
        }
        temp= dummy;
        dummy= dummy->next;
        delete temp;
        return dummy;
    }
};
