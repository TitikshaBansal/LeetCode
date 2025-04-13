/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* getKthNode(ListNode* head, int k){
        k--;
        while(head && k>0){
            k--;
            head = head->next;
        }
        return head;
    }
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr= next;
        }
        head = prev;
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while(temp){
            ListNode* kThNode = getKthNode(temp,k);
            if(!kThNode){
                if(prev) prev->next = temp;
                break;
            }

            ListNode* nextNode = kThNode->next;
            kThNode->next = nullptr;
            reverse(temp);
            if(temp == head) head = kThNode;
            else prev->next = kThNode;

            prev = temp;
            temp = nextNode;
        }
        return head;
    }
};

// https://leetcode.com/problems/reverse-nodes-in-k-group/
