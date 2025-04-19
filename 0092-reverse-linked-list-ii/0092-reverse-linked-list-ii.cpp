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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int>nums;
        auto temp = head;

        while(temp) {
            nums.push_back(temp->val);
            temp = temp->next;
        }
        reverse(nums.begin()+left-1, nums.begin()+right);
        
        temp = head;
        int i = 0;
        while(temp) {
            temp->val = nums[i++];
            temp = temp->next;
        }
        return head;
    }
};