class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*, int> m;
        while(head!=nullptr){
            m[head]++;
            if(m[head]>1) return true;
            head= head->next;
        }
        return false;
    }
};
