int Solution::perfectPeak(vector<int> &A) {
    int siz=A.size();
    int ar[siz+10];
    ar[siz-1]=A[siz-1];
    for(int i=siz-2;i>=0;i--){
        ar[i]=min(ar[i+1],A[i]);
    }
    int ma=A[0];
    int ck=0;
    ar[siz]=INT_MAX;
    for(int i=1;i<siz-1;i++){
        if(A[i]>ma){
            ma=A[i];
            if(ma<ar[i+1]){
                return 1;
            }
        }
    }
    return 0;
}
