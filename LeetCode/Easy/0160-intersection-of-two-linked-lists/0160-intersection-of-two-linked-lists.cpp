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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;

        int len1=0,len2=0;

        while(temp1){
            len1++;
            temp1=temp1->next;
        }
        while(temp2){
            len2++;
            temp2=temp2->next;
        }
        temp1=headA;
        temp2=headB;
        if(len1==len2){
            while(temp1!=temp2){
                temp1=temp1->next;
                temp2=temp2->next;
            }
            return temp1;
        }
        else if(len1>len2){
            for(int i=1;i<=abs(len1-len2);i++){
                temp1=temp1->next;
            }

            while(temp1!=temp2){
                temp1=temp1->next;
                temp2=temp2->next;
            }
            return temp1;
        }else{
            for(int i=1;i<=abs(len1-len2);i++){
                temp2=temp2->next;
            }

            while(temp1!=temp2){
                temp1=temp1->next;
                temp2=temp2->next;
            }
            return temp1;
        }
    }
};