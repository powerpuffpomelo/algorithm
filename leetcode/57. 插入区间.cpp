// ###################################################### 版本2 ###################################################### //
// 
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool has_in = false;
        int l = newInterval[0], r = newInterval[1];
        for(auto e : intervals){
            if(e[1] < l){
                ans.push_back(e);
            }else if(e[0] > r){
                if(!has_in){
                    ans.push_back({l, r});
                    has_in = true;
                }
                ans.push_back(e);
            }else{
                l = min(l, e[0]);
                r = max(r, e[1]);
            }
        }
        if(!has_in){
            ans.push_back({l, r});
        }
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int l = newInterval[0], r = newInterval[1];
        vector<vector<int>> ans;
        int i = 0;
        while(i < intervals.size() && intervals[i][1] < newInterval[0]){
            ans.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }
        while(i < intervals.size() && intervals[i][0] <= newInterval[1]){
            l = min(l, intervals[i][0]);
            r = max(r, intervals[i][1]);
            i++;
        }
        ans.push_back({l, r});
        while(i < intervals.size()){
            ans.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }
        return ans;
    }
};