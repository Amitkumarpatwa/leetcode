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
    ListNode* partition(ListNode* head, int x) {
        ListNode* low=new ListNode(10);
        ListNode* high=new ListNode(10);
        ListNode* temp=head;
        ListNode* tempL=low;
        ListNode* tempH=high;

        while(temp){
            if(temp->val<x){
                tempL->next=temp;
                temp=temp->next;
                tempL=tempL->next;
            }else{
                tempH->next=temp;
                temp=temp->next;
                tempH=tempH->next;
            }
        }
        tempL->next=high->next;
        tempH->next=NULL;


        return low->next;
    }
};