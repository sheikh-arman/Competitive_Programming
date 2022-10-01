#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=1000000;
string s;

ll segTree[3*MX+10][30];

void init(){
    for(ll i=0;i<3*MX+10;i++){
        for(ll j=0;j<30;j++)segTree[i][j]=0;
    }
}

void build(ll v, ll l, ll r)
{
    if(l==r){
        ll idx=s[l-1]-'a';
        segTree[v][idx]=1;
    }
    else{
        ll left=v*2;
        ll right=left+1;
        ll mid=l+(r-l)/2;
        build(left,l,mid);
        build(right,mid+1,r);
        for(ll i=0;i<26;i++){
            segTree[v][i]=segTree[left][i]+segTree[right][i];
        }
    }
}

vector<ll> query(ll v, ll l, ll r, ll ql, ll qr)
{
    vector<ll>p(26,0);
    vector<ll>q(26,0);
    if(ql>r||l>qr)return p;
    if(l>=ql&&r<=qr){
        for(ll i=0;i<26;i++)p[i]=segTree[v][i];
        return p;
    }
    ll left=v*2;
    ll right=left+1;
    ll mid=l+(r-l)/2;
    p=query(left,l,mid,ql,qr);
    q=query(right,mid+1,r,ql,qr);
    for(ll i=0;i<26;i++)p[i]+=q[i];
    return p;
}

int main(){
    ll t=1;
    cin>>t;
    for(ll T=1;T<=t;T++){
        init();
        cin>>s;
        ll len=s.size();
        build(1,1,len);
        ll q;
        cin>>q;
        ll ct=0;
        for(ll i=0;i<q;i++){
            ll l,r;
            cin>>l>>r;
            if(l>r)swap(l,r);
            ll dif=r-l+1;
            if(dif%2!=0){
                ll mid=l+(r-l)/2;
                vector<ll>ans1=query(1,1,len,l,mid);
                vector<ll>ans2=query(1,1,len,mid+1,r);
                vector<ll>ans3=query(1,1,len,l,mid-1);
                vector<ll>ans4=query(1,1,len,mid,r);
                /*
                cout<<"ranges: "<<l<<" "<<mid<<" "<<r<<endl;
                for(ll j=0;j<26;j++)cout<<ans1[j]<<" ";
                cout<<endl;
                for(ll j=0;j<26;j++)cout<<ans2[j]<<" ";
                cout<<endl;
                */
                ll ctdif=0,ctdif2=0;
                for(ll j=0;j<26;j++){
                    //cout<<"Case-> "<<T<<": Query "<<i+1<<" "<<ans1[j]<<" "<<ans2[j]<<endl;
                    ctdif+=abs(ans1[j]-ans2[j]);
                }
                for(ll j=0;j<26;j++){
                    //cout<<"Case-> "<<T<<": Query "<<i+1<<" "<<ans1[j]<<" "<<ans2[j]<<endl;
                    ctdif2+=abs(ans3[j]-ans4[j]);
                }
                //cout<<T<<" "<<i<<" "<<ctdif<<endl;
                if(ctdif==1||ctdif2==1)ct++;
            }
        }
        cout<<"Case #"<<T<<": "<<ct<<endl;
    }
    return 0;
}