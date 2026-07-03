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
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL) return head;

        if(left==right) return head;
        ListNode* temp=head;
        ListNode* a;
        ListNode* b;
        ListNode* c;
        ListNode* d;
        int len=1;
        
        while(temp){
            if(len==left-1) a=temp;
            if(len==left) b=temp;
            if(len==right) c=temp;
            if(len==right+1) d=temp;
            temp=temp->next;
            len++;
        }

        if(a) a->next=NULL;
        c->next=NULL;

        c=reverse(b);
        if(a) a->next=c;
        b->next=d;

        if(a) return head;

        return c;

       
    }
};