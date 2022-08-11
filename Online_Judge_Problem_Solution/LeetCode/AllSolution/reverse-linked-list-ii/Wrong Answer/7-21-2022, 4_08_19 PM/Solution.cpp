// https://leetcode.com/problems/reverse-linked-list-ii

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* root=new ListNode();
        root=head;
        ListNode* cur=new ListNode();
        cur=root;
        ListNode* breakPoint=new ListNode();
        ListNode* rev=new ListNode();
        ListNode* rev_save=new ListNode();
        int cnt=0,ck=0;
        while(cur!=NULL){
            cnt++;
            if(cnt==left){
                ck=1;
            }
            if(ck==0){
                breakPoint=cur;
            }
            if(cnt==left){
                rev=cur;
                rev_save=cur;
            }
            else if(cnt>left){
                ListNode* tm=new ListNode();
                tm->val=cur->val;
                tm->next=rev;
                rev=tm;
            }
            cur=cur->next;
            if(cnt==right)break; 
            
        }
        breakPoint->next=rev;
        if(left==1)root=rev;
        while(cur!=NULL){
            rev_save->next=cur;
            cur=cur->next;
        }
        rev_save->next=NULL;
        return root;
    }
};