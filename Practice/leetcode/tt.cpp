void removeDuplicate()
{
    node *currNode=root,*lastNode;
    bool isGetRoot=false,flag=false;
    while(!flag)
    {
        ll cnt=0;
        node *prevNode=currNode;
        while(currNode->next!=NULL)
        {
            currNode=currNode->next;
            if(prevNode->roll!=currNode->roll)
            {
                break;
            }
            cnt++;
        }
        if(cnt==0)
        {
            if(isGetRoot==false)
            {
                root=prevNode;
                lastNode=prevNode;
                isGetRoot=true;
            }
            else
            {
                node *temp=lastNode;
                temp->next=prevNode;
                lastNode=prevNode;
            }
        }
        if(currNode->next==NULL)
        {
            if(prevNode->roll!=currNode->roll)
            {
                if(isGetRoot==false)
                {
                    root=currNode;
                    lastNode=currNode;
                    isGetRoot=true;
                }
                else
                {
                    node *temp=lastNode;
                    temp->next=currNode;
                    lastNode=currNode;
                }
            }
            flag=true;
        }
    }
    if(isGetRoot==true)
    {
        lastNode->next=NULL;
    }
    else
    {
        //Empty List
        root=NULL;
    }
}
