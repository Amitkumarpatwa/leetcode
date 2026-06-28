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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //optimal approach
        ListNode* slow;
        ListNode* fast;
        slow=fast=head;
        //now we move fast pointer n+1 step ahead

        for(int i=1;i<=n+1;i++){
            if(fast==NULL) return head->next;
            fast=fast->next;
        }

        while(fast){
            slow=slow->next;
            fast=fast->next;
        }

        ListNode* temp=slow->next;
        slow->next=slow->next->next;
        delete temp;
        return head;
    }
};