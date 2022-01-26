vector<int> Solution::solve(vector<int> &A) {
    int cnt=0;
    int siz=A.size();
    for(int i=0;i<siz;i++){
        if(A[i]==0){
            cnt++;
        }
        else{
            A[i-cnt]=A[i];
        }
    }
    for(int i=siz-1;cnt>0;cnt--,i--){
        A[i]=0;
    }
    return A;
}
