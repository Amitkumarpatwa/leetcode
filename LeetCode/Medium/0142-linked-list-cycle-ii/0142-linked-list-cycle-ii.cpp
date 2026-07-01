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
        // here we detect the cycle
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast){
                flag=true;
                break;
            }
        }
        // if cycle found then move both slow and temp until they meet 
        // there meeting point is starting node of cycle
        if(flag){
            while(temp!=slow){
                slow=slow->next;
                temp=temp->next;
            }

            return slow;
        }

        return NULL;

    }
};