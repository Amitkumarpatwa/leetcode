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
        ListNode* head= new  ListNode(100);
        ListNode* temp= head;
        
        while(a && b){
            if(a->val <=b->val){
                temp->next=a;
                temp=temp->next;
                a=a->next;
            }else{
                temp->next=b;
                temp=temp->next;
                b=b->next;

            }
        }
        if(a==NULL){
            temp->next=b;
        }else{
            temp->next=a;
        }

        return head->next;
    }
};