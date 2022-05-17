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
class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode *root;
        ListNode *lastNode=root;
        int ck=1;
        while(head->next!=NULL)
        {
            ListNode *tm=head->next;
            if(tm->val==head->val)
            {
                while(tm->next!=NULL && tm->val==head->val)
                {
                    tm=tm->next;
                }
            }
            else
            {
                if(ck)
                {
                    root=head;
                    lastNode=root;
                }
                else
                {
                    lastNode->next=head;
                    lastNode=head;
                }
                ck=0;
            }
            cout<<head->val<<" t\n";
            if(tm->next==NULL)
            {
                if(head->val!=tm->val)
                {
                    if(ck)
                    {
                        root=head;
                        lastNode=root;
                    }
                    else
                    {
                        lastNode->next=head;
                        lastNode=head;
                    }
                    ck=0;
                }
                else
                {

                }
            }
            head=tm;
        }
        if()
            return root;
    }
};
