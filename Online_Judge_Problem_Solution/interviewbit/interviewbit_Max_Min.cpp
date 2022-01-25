int Solution::solve(vector<int> &A) {
    int ma=A[0];
    int mi=A[0];
    for(int i:A){
        ma=max(ma,i);
        mi=min(mi,i);
    }
    return ma+mi;
}
