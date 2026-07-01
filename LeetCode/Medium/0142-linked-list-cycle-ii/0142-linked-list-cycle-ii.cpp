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
    ListNode* detectCycle(ListNode *head) {
       ListNode* slow=head; 
       ListNode* fast=head; 
       ListNode* temp=head;
       bool flag=false;

       while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            flag=true;
            break;
        }
       }
       if(flag){
       while(temp!=slow){
        temp=temp->next;
        slow=slow->next;
       
       }
       return slow;
       }

       return NULL; 
    }
};