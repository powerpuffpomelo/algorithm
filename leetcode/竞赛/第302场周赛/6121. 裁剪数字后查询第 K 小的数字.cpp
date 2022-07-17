// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    typedef pair<string, int> pii;
    static bool cmp(pii& a, pii& b){
        if(a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    }
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), len = nums[0].size();
        vector<vector<pii>> vv(len + 1);
        for(int l = 1; l <= len; l++){
            //cout << l << endl;
            vector<pii> temp;
            for(int i = 0; i < n; i++){
                temp.push_back({nums[i].substr(len - l), i});
                //if(l == 2) cout << nums[i] << ' ' << temp[i].first << endl;
            }
            //break;
            sort(temp.begin(), temp.end(), cmp);
            vv[l] = temp;
        }
        //return 0;
        vector<int> ans;
        for(auto q : queries){
            auto temp = vv[q[1]];
            ans.push_back(temp[q[0] - 1].second);
        }
        return ans;
    }
};