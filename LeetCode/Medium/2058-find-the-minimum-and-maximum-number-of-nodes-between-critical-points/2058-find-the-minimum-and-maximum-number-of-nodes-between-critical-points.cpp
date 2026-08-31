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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
      int idx= 1;
      int first=-1;
      int second=-1;
      ListNode* a=head;
      ListNode* b=head->next;
      ListNode* c=head->next->next;

      int mind=INT_MAX;
      int f=-1,s=-1;
      while(c){
        if(b->val >a->val && b->val >c->val||b->val <a->val && b->val <c->val){
            if(first==-1) first=idx;
            else second=idx;
            f=s;
            s=idx;
            if(f!=-1)mind=min(mind,s-f);

        }
        a=a->next;
        b=b->next;
        c=c->next;
        idx++;
      }
      if(second==-1) return {-1,-1};
      int maxd= second-first;
     
      
      return {mind,maxd};
    }
};