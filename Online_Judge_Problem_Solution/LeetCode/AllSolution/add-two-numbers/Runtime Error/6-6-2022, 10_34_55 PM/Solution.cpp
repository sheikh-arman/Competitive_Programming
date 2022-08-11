// https://leetcode.com/problems/add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root=NULL;
        ListNode* ans;
        ans=root;
        int carry=0;
        while(l1!=NULL){
            int sum=l1->val+l2->val+carry;carry=0;
            l1=l1->next;
            l2=l2->next;
            if(sum>9){
                carry=sum/10;
                sum=sum%10;
            }
            if(root==NULL){
                root=new ListNode(sum);
                ans=root;
            }
            else{
                ListNode* tm=new ListNode(sum);
                ans->next=tm;
                ans=tm;
            }
        }
        return root;
    }
};