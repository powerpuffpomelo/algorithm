// ###################################################### 版本2 ###################################################### //
// 优化一点点~
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){  // 匿名函数
            return a[1] < b[1];   // 仅考虑右端点即可
        });
        if(intervals.empty()) return 0;
        int ans = 1, r = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= r){
                ans++;
                r = intervals[i][1];
            }
        }
        return n - ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[1] != b[1]) return a[1] < b[1];
        return a[0] > b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        int r = INT_MIN;
        int ans = 0;
        for(auto e : intervals){
            if(e[0] >= r){
                r = e[1];
                ans++;
            }
        }
        return n - ans;
    }
};