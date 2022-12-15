class MyCalendarThree {
public:
    map<int, int> mp;
    MyCalendarThree() {
    }
    
    int book(int start, int end) {
        mp[start]++, mp[end]--;
        int sum = 0, ret = 0;
        for(auto [k, v] : mp){
            sum += v;
            ret = max(ret, sum);
        }
        return ret;
    }
};