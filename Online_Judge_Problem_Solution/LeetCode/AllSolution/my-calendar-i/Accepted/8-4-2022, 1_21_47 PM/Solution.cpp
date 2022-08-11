// https://leetcode.com/problems/my-calendar-i

class MyCalendar {
public:
    set<pair<int,int>>st;
    MyCalendar() {
        st.clear();
    }
    
    bool book(int start, int end) {
        auto it=st.lower_bound({start,end});
        int ck=1;
        if(it==st.end()){
            if(st.size()>0){
                it--;
                if(it->second<start){
                     st.insert({start,end-1});
                }
                else{
                    ck=0;
                }
            }
            else
            st.insert({start,end-1});
        }
        else if(it==st.begin()){
            if(it->first>=end){
                st.insert({start,end-1});
            }
            else{
                ck=0;
            }
        }
        else{
            if(it->first>=end){
                it--;
                if(it->second<start){
                    st.insert({start,end-1});
                }
                else{
                    ck=0;
                }
            }
            else{
                ck=0;
            }
        }
        return ck;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */