// https://leetcode.com/problems/partition-list

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
        int ck=0;
        int ck2=0;
        ListNode* root=new ListNode();
        ListNode* root2=new ListNode();
        ListNode* curr=new ListNode();
        ListNode* small=new ListNode();
        ListNode* big=new ListNode();
        root=head;
        curr=head;
        while(curr!=NULL){
            if(curr->val<x){
                if(ck==0){
                    ck=1;
                    small->val=curr->val;
                    root=small;
                }
                else{
                    small->next=curr;
                    small=small->next;
                }
            }
            else{
                if(ck2==0){
                    ck2=1;
                    big->val=curr->val;
                    if(ck==0)
                       root=big;
                    root2=big;
                }
                else{
                    big->next=curr;
                    big=big->next;
                }
            }
            curr=curr->next;
        }
        big->next=NULL;
        if(ck){
            small->next=root2;
        }
        return root;
    }
};