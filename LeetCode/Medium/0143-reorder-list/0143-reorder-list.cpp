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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return ;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* middle=head;

        while(fast &&  fast->next){
            middle=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        middle->next=NULL;

        slow=reverse(slow);
        
        // merge them
        ListNode* c= new ListNode(100);
        ListNode* tempC=c;
        ListNode* tempA=head;
        ListNode* tempB=slow;

        while(tempA && tempB){
            tempC->next=tempA;
            tempC=tempA;
            tempA=tempA->next;

            tempC->next=tempB;
            tempC=tempB;
            tempB=tempB->next;
        }
        delete(c);
        tempC->next=tempB;

        head=c->next;

        
    }
};