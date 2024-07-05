class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head== nullptr || head->next == nullptr) return {-1, -1};
        vector<int> index;
        int pos=1;
        int pre= head->val;
        head= head->next;
        while(head->next!=nullptr){
            if(head->val> pre && head->next->val < head->val) index.push_back(pos);
            else if(head->val< pre && head->next->val > head->val) index.push_back(pos);
            pre= head->val;
            head= head->next;
            pos++;
        } 
        if (index.size()<2) return {-1, -1};
        int mini= INT_MAX;
        for(int i=0; i<index.size()-1; i++){
            mini= min(mini, index[i+1]-index[i]);
        }
        int maxi= index.back()-index.front();
        return {mini, maxi};
    }
};
