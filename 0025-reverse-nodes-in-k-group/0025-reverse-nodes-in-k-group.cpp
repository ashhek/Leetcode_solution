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
    ListNode* reverseList(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr && k--) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int cnt = 0;
        while(cnt != k && curr) {
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