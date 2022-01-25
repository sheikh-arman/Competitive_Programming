int Solution::solve(vector<int> &A, int B) {
    int sum1=0,sum2=0;
    for(int i=0;i<B;i++){
        sum1+=A[i];
    }
    int ans=sum1;
    int siz=A.size();siz--;
    for(int i=B-1;i>=0;i--){
        sum1-=A[i];
        sum1+=A[siz];siz--;
        ans=max(ans,sum1);
    }
   return ans;
}

