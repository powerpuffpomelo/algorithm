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