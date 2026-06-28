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
    ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL) return head;
    
      ListNode* seen=head;
      ListNode* temp=head->next;

      while(temp){

        if(temp->val==seen->val){
            temp=temp->next;
        }else{
            seen->next=temp;
            seen=temp;
            temp=temp->next;
        }

      }
      seen->next=NULL;
      return head;  
    }
};