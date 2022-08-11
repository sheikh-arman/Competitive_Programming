// https://leetcode.com/problems/smallest-number-in-infinite-set

class SmallestInfiniteSet {
public:
    set<int>pq;
    SmallestInfiniteSet() {
        for(int i=1;i<=2000;i++){
            pq.insert(i);
        }
    }
    
    int popSmallest() {
        int val=*pq.begin();
        pq.erase(pq.begin());
        return val;
    }
    
    void addBack(int num) {
        if(pq.find(num)==pq.end())
        pq.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */