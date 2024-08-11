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
        if(!head || k==0) return head;
        int size=1;
        auto temp=head;
        while(temp->next){
            size++;
            temp=temp->next;
        }
        temp->next=head;
        int m= size - k%size -1;
        auto it=head;
        while(m--){
            it=it->next;
        }
        auto ans=it->next;
        it->next=NULL;
        return ans;
    }
};