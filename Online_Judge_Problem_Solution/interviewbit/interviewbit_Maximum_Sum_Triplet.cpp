int Solution::solve(vector<int> &A) {
    int nl=A.size();
    int ar[nl+2];
    ar[nl-1]=A[nl-1];
    for(int i=nl-2;i>=0;i--){
        ar[i]=max(ar[i+1],A[i]);
    }
    int ans=0;
    set<int>st;
    set<int>::iterator it;
    st.insert(A[0]);
    for(int i=1;i<nl-1;i++){
        it=st.lower_bound(A[i]);
        
        if(it!=st.begin()&&A[i]<ar[i+1]){
            it--;
            ans=max(ans,*it+A[i]+ar[i+1]);
        }
        st.insert(A[i]);
    }
    return ans;
}

