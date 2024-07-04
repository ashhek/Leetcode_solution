/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto slow = head;
        auto fast = head;
        bool isCycle = false;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                isCycle = true; break;
            }
        }
        if(!isCycle) return NULL;
        auto slow2 = head;
        while(slow2 != slow){
            slow2 = slow2->next;
            slow = slow->next;
        }
        return slow;     
    }
};