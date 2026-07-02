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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode* tempA=a;
        ListNode* tempB=b;
        ListNode* c=new ListNode(-1);
        ListNode* temp=c;

        while(tempA && tempB){
            if(tempA->val<=tempB->val){
                ListNode* t= new ListNode(tempA->val);
                temp->next=t;
                temp=temp->next;
                tempA=tempA->next;
            }else{
                ListNode* t= new ListNode(tempB->val);
                temp->next=t;
                temp=temp->next;
                tempB=tempB->next;

            }
        }

        if(tempA==NULL){
            temp->next=tempB;
        }
        else{
            temp->next=tempA;
        }

        return c->next;
        

    }
};