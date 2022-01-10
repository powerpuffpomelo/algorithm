// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for(int n : nums) cnt[n]++;
        struct CC{
            int nn, cc;
            bool operator< (const CC &W)const{
                return cc > W.cc;
            }
        };
        vector<CC> v;
        for(auto kv : cnt){
            v.push_back({kv.first, kv.second});
        }
        sort(v.begin(), v.end());
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(v[i].nn);
        }
        return ans;
    }
};