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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* curr = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        while(curr) {
            auto front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        ListNode* first = head;
        ListNode* second = prev;
        while(second) {
            ListNode* front1 = first->next;
            ListNode* front2 = second->next;
            first->next = second;
            second->next = front1;
            first = front1;
            second = front2;
        }
    }
};