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