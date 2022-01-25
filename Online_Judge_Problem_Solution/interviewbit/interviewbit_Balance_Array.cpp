int Solution::solve(vector<int> &A) {
    int even=0,odd=0;
    int siz=A.size();
    for(int i=siz-1;i>=0;i--){
        if(i%2==0){
            even+=A[i];
        }
        else{
            odd+=A[i];
        }
    }
    int fr_odd=0,fr_even=0;
    int cnt=0;
    for(int i=0;i<siz;i++){
        if(i%2==0){
            even-=A[i];
        }
        else{
            odd-=A[i];
        }
        if(fr_odd+even==fr_even+odd){
            cnt++;
        }
        if(i%2==0){
            fr_even+=A[i];
        }
        else{
            fr_odd+=A[i];
        }
    }
    return cnt;
}
