// ###################################################### 版本2 ###################################################### //
// 简洁版
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(!intervals.size()) return ans;
        sort(intervals.begin(), intervals.end());
        int l = intervals[0][0], r = intervals[0][1];
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][0] > r){
                ans.push_back({l, r});
                l = intervals[i][0], r = intervals[i][1];
            }else{
                r = max(r, intervals[i][1]);
            }
        }
        ans.push_back({l, r});
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int i = 0, st, ed;
        while(i < intervals.size()){
            auto inter = intervals[i];
            st = inter[0], ed = inter[1];
            int j = i + 1;
            for(; j < intervals.size() && intervals[j][0] <= ed; j++){
                ed = max(ed, intervals[j][1]);
            }
            ans.push_back({st, ed});
            i = j;
        }
        return ans;
    }
};