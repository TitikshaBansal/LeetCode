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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        int len = 0;
        ListNode* temp = head;
        while(temp){
            temp=temp->next;
            len++;
        }

        k%=len;
        if(k==0) return head;

        ListNode* ptr1 = head;
        ListNode* ptr2 = head;

        while(k--) ptr1 = ptr1->next;

        while(ptr1->next){
            ptr1=ptr1->next;
            ptr2 = ptr2->next;
        }
        ListNode* newHead = ptr2->next;
        ptr2->next = nullptr;
        ptr1->next = head;

        return newHead;
    }
};

// https://leetcode.com/problems/rotate-list/
