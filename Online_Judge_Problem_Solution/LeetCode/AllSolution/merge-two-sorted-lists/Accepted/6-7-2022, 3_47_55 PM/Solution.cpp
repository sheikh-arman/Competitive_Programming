// https://leetcode.com/problems/merge-two-sorted-lists

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* root=NULL;
        ListNode* ans;
        while(list1!=NULL && list2!=NULL){
            int val;
            if(list1->val<=list2->val){
                val=list1->val;
                list1=list1->next;
            }
            else{
                val=list2->val;
                list2=list2->next;
            }
            
            if(root==NULL){
                root = new ListNode(val);
                ans=root;
            }
            else{
                ListNode* tm=new ListNode(val);
                ans->next=tm;
                ans=tm;
            }
        }
        while(list1!=NULL){
            if(root==NULL){
                root = new ListNode();
                root->val=list1->val;
                ans=root;
            }
            else{
                ListNode* tm=new ListNode(list1->val);
                ans->next=tm;
                ans=tm;
            }
            list1=list1->next;
        }
        while(list2!=NULL){
            if(root==NULL){
                root = new ListNode();
                root->val=list2->val;
                ans=root;
            }
            else{
                ListNode* tm=new ListNode(list2->val);
                ans->next=tm;
                ans=tm;
            }
            list2=list2->next;
        }
        return root;
    }
};