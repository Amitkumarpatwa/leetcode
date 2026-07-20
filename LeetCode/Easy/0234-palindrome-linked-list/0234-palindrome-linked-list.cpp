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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nextt=head;
        while(curr){
            nextt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* temp=head;
        ListNode* temp1=head;

        while(fast && fast->next){
            temp1=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp1->next=NULL;
        slow=reverse(slow);

        while(temp){
            if(temp->val!=slow->val) return false;
            temp=temp->next;
            slow=slow->next;
        }

        return true;

    }
};