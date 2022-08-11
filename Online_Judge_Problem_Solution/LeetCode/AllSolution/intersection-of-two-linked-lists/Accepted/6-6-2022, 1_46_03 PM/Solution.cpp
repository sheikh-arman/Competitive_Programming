// https://leetcode.com/problems/intersection-of-two-linked-lists

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
        ListNode *rootA=headA;
        ListNode *rootB=headB;
        int cntA=0,cntB=0;
        while(rootA->next!=NULL){
            rootA=rootA->next;
            cntA++;
        }
        while(rootB->next!=NULL){
            rootB=rootB->next;
            cntB++;
        }
        rootA=headA;
        rootB=headB;
        if(cntA>cntB){
            while(cntA>cntB){
                cntA--;
                rootA=rootA->next;
            }
        }
        else if(cntA<cntB){
            while(cntB>cntA){
                cntB--;
                rootB=rootB->next;
            }
        }
        while(rootA!=rootB){
            rootA=rootA->next;
            rootB=rootB->next;
        }
        return rootA;
    }
};