#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 vector<int> seq1,seq2;
int N,A[1000],Inc[1000],Dec[1000];
void Input(){
    cin>>N;
    for(int i=1;i<=N;i++) cin>>A[i];
}
void LBS()
{
    Inc[1]=1;
    for(int i=1;i<=N;i++)
    {
        for(int j=i+1;j<=N;j++)
        {
            if(A[j]>A[i])
            {
                if(Inc[j]<Inc[i]+1)
                {
                    Inc[j]=Inc[i]+1;
                }
            }
        }
    }
    Dec[N]=1;
    for(int i=N;i>=1;i--)
    {
        for(int j=i-1;j>=1;j--)
        {
            if(A[j]>A[i])
            {
                if(Dec[j]<Dec[i]+1)
                {
                    Dec[j]=Dec[i]+1;
                }
            }
        }
    }
    int ans=0;
    int LIS,LDS,idx;
    for(int i=1;i<=N;i++)
    {
        int X=Inc[i]+Dec[i]-1;
        if(X>ans)
        {
            ans=X;
            LIS=Inc[i];
            LDS=Dec[i];
            idx=i;
        }
    }

    for(int i=idx;i>=1;i--)
    {
        if(Inc[i]==LIS)
        {
            seq1.push_back(A[i]);
            LIS--;
        }
    }
    LDS--;
    for(int i=idx+1;i<=N;i++)
    {
        if(Dec[i]==LDS)
        {
            seq2.push_back(A[i]);
            LDS--;
        }
    }
    reverse(seq1.begin(),seq1.end());
}
void Print(){
    for(int i=0;i<seq1.size();i++) cout<<seq1[i]<<" ";
    for(int i=0;i<seq2.size();i++) cout<<seq2[i]<<" "; cout<<endl;
}
int main()
{
    Input();
    LBS();
    Print();
}
