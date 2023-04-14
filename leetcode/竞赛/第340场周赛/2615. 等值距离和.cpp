// 时间复杂度 O(n)
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        map<int, vector<int>> pos; 
        for(int i = 0; i < n; i++) pos[nums[i]].push_back(i);
        for(auto [k,v] : pos){
            long long sum = 0;
            for(int i = 1; i < v.size(); i++) sum += v[i] - v[0];
            ans[v[0]] = sum;  // 先算第一项
            for(int i = 1; i < v.size(); i++){
                sum += (long long)(2 * i - v.size()) * (v[i] - v[i - 1]);  // 之后每项递推计算，i个加(v[i] - v[i - 1])，v.size() - i 个减 (v[i] - v[i - 1])
                ans[v[i]] = sum;
            }
        }
        return ans;
    }
};