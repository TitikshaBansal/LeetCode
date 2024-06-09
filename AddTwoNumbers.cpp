ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head= new ListNode(0);
        ListNode *tail= head;
        int carry=0;
        while(l1!=nullptr || l2!=nullptr){
            int digit1 = (l1 != nullptr) ? l1->val : 0;
            int digit2 = (l2 != nullptr) ? l2->val : 0;
            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            ListNode *temp = new ListNode(digit);
            tail->next=temp;
            tail=tail->next;
            carry= sum/10;
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
        while(l1!=nullptr){
            int digit = l1->val + carry;
            ListNode *temp = new ListNode(digit%10);
            tail->next=temp;
            tail=tail->next;
            carry= digit/10;
            l1=l1->next;
        }
        while(l2!=nullptr){
            int digit = l2->val + carry;
            ListNode *temp = new ListNode(digit%10);
            tail->next=temp;
            tail=tail->next;
            carry= digit/10;
            l2=l2->next;
        }
        if(carry!=0){
            ListNode *temp = new ListNode(carry);
            tail->next=temp;
            tail=tail->next;
        }
        return head->next;
