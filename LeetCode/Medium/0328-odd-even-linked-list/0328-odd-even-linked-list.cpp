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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd= new ListNode(10);
        ListNode* even= new ListNode(10);
        ListNode* tempOdd= odd;
        ListNode* tempEven= even;
        ListNode* temp= head;

        bool flag= true;

        while(temp){
            if(flag){
                tempOdd->next=temp;
                tempOdd=tempOdd->next;
                flag=false;
            }else{
                tempEven->next=temp;
                tempEven=tempEven->next;
                flag=true;
            }
            temp=temp->next;
        }
        tempOdd->next=even->next;
        tempEven->next=NULL;

        return odd->next;
         
    }
};