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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next) return head;

        auto currNode = head;
        auto adjNode = head->next;

        while(adjNode) {
            int gcd = __gcd(currNode->val, adjNode->val);
            auto newNode = new ListNode(gcd);

            currNode->next = newNode;
            newNode->next = adjNode;

            currNode = adjNode;
            adjNode= adjNode->next;
        }
        return head;
    }
};