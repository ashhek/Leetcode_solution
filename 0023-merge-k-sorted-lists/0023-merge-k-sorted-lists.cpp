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
private:
    ListNode* conquer(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(left && right) {
            if(left->val < right->val) {
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        if(left) {
            curr->next = left;
        } else {
            curr->next = right;
        }
        return dummy->next;
    }
    ListNode* divide(vector<ListNode*>lists, int low, int high) {
        if(low > high) return nullptr;
        if(low == high) return lists[low];

        int mid = (low + high) >> 1;
        ListNode* left = divide(lists, low, mid);
        ListNode* right = divide(lists, mid+1, high);
        return conquer(left, right);
    }    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) {
            return nullptr;
        }
        return divide(lists, 0, lists.size()-1);
    }
};