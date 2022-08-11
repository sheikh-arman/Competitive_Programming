// https://leetcode.com/problems/booking-concert-tickets-in-groups

class BookMyShow {
public:
    int ar[50010];
    int N,M;
    int start=0;
    int rep[50010];
    int Find(int node){
       return (rep[node]==node)?node:rep[node]=Find(rep[node]);
    }  
    BookMyShow(int n, int m) {
        for(int i=0;i<=n;i++){
            ar[i]=0;
            N=n;
            M=m;
            start=0;
            rep[i]=i;
        }
    }
    vector<int> gather(int k, int maxRow) {
        vector<int>V;
        for(int i=start;i<=maxRow;i++){
            i=Find(i);
            if(k<=(M-ar[i])){
                V.push_back(i);
                V.push_back(ar[i]);
                ar[i]+=k;break;
            }
            if(ar[i]==M){
                rep[i]=Find(i+1);
            }
        }
        return V;
    }
    bool scatter(int k, int maxRow) {
        long long int cnt=0,ck=0;
        for(int i=start;i<=maxRow;i++){
             i=Find(i);
            cnt+=(M-ar[i]);
            if(cnt>=k){
                ck=1;break;
            }
        }
        if(ck){
            for(int i=start;i<=maxRow&&k;i++){
               i=Find(i);
               int mi=min(k,M-ar[i]);
               k-=mi;
               ar[i]+=mi;
               if(ar[i]==M){
                   rep[i]=Find(i+1);start=i+1;
               }
            }
        }
        return (bool)ck;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */