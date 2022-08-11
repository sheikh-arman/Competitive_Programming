// https://leetcode.com/problems/my-calendar-i

class MyCalendar {
    map<int,int>mp;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto next=mp.upper_bound(start);
        if(next!=mp.end() && (*next).second<end)return false;
        mp.insert({end,start});
        return true;
    }
};
