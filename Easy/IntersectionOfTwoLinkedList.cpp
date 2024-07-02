class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> set1;
        set<ListNode*> set2;
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1!=NULL){
            set1.insert(temp1);
            temp1= temp1->next;
        }
        while(temp2!=NULL){
            set2.insert(temp2);
            temp2= temp2->next;
        }
        for(auto i : set1){
            if(set2.find(i)!=set2.end()) return i;
        }
        return NULL;
    }
};
