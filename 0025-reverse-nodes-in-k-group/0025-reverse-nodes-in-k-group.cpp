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
    ListNode* reverseList(ListNode* node, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = node;

        while(curr && k--) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0;
        ListNode* curr = head;

        while(curr && cnt < k) {
            curr = curr->next;
            cnt++;
        }

        if(cnt == k) {
            ListNode* reversedHead = reverseList(head, k);
            head->next = reverseKGroup(curr, k);
            return reversedHead;
        }
        return head;
    }
};