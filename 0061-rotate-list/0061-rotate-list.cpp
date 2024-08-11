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
        if(!head) return head;

        ListNode* tail = head;
        int len = 1;
        while(tail->next){
            len++;
            tail = tail->next;
        }
        tail->next = head;
        for(int i=0; i<len-k%len; ++i){
            tail = tail->next;
        }
        ListNode* ans = tail->next;
        tail->next = NULL;
        return ans;
    }
};