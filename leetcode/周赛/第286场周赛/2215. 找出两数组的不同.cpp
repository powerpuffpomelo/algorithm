class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        unordered_set<int> hash1, hash2;
        for(auto x : nums1) hash1.insert(x);
        for(auto x : nums2) hash2.insert(x);
        for(auto x : hash1){
            if(!hash2.count(x)) ans[0].push_back(x);
        }
        for(auto x : hash2){
            if(!hash1.count(x)) ans[1].push_back(x);
        }
        return ans;
    }
};