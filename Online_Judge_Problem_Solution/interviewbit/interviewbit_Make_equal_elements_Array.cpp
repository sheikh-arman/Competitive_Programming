int Solution::solve(vector<int> &A, int B) {
    int siz=A.size();
    int cnt=0,ck=1,pre=A[0];
    for(int i:A){
        if(i%B==0){
            cnt++;
        }
        if(pre!=i){
            ck=0;
        }
    }
    return (ck||cnt==siz);
}
