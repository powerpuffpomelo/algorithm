// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    typedef pair<string, int> psi;
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), len = nums[0].size();
        vector<vector<psi>> vv;
        for(int l = 1; l <= len; l++){
            vector<psi> temp;
            for(int i = 0; i < n; i++){
                temp.push_back({nums[i].substr(len - l), i});
            }
            sort(temp.begin(), temp.end());
            vv.push_back(temp);
        }
        vector<int> ans;
        for(auto q : queries){
            vector<psi> temp = vv[q[1] - 1];
            ans.push_back(temp[q[0] - 1].second);
        }
        return ans;
    }
};