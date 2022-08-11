// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *ans;
        ListNode *nxt;
        int ck=1;
        while(head!=NULL){
            nxt=head->next;
            if(head->val==nxt->val){
                while(nxt->val!=head->val||nxt!=NULL){
                    nxt=nxt->next;
                }
                head=nxt;
            }
            else{
                if(ck){
                    ans=head;
                }
                else{
                    ListNode *temp;
                    temp->val=head->val;
                    ans->next=temp;
                }
                ck=0;
            }
        }
        return ans;
    }
};