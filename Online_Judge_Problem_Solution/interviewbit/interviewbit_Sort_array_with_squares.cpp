vector<int> Solution::solve(vector<int> &A) {
    int siz=A.size();
    int ar[siz+10];
    int left=0,right=siz-1,cn=siz-1;
    while(left<=right){
        int tm1=A[left]*A[left];
        int tm2=A[right]*A[right];
        if(tm1>=tm2){
            left++;
            ar[cn--]=tm1;
        }
        else{
            right--;
            ar[cn--]=tm2;
        }
    }
    vector<int>V;
    for(int i=0;i<siz;i++){
        V.push_back(ar[i]);
    }
    return V;
}
