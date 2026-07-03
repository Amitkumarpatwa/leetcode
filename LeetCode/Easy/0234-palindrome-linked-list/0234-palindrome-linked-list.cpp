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
        ListNode* temp = new ListNode(10);
        ListNode* tt=temp;
        ListNode* t=head;

        while(t){
            ListNode* newnode= new ListNode(t->val);
            temp->next=newnode;
            temp=temp->next;
            t=t->next;
        }
        tt=reverse(tt->next);

        ListNode* p1 = head;
        ListNode* p2 = tt;

        while(p1 && p2){
        if(p1->val != p2->val)
        return false;

        p1 = p1->next;
        p2 = p2->next;
}

return true;
    }
};