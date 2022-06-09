// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> pos;
        for(int i = 0; i < nums.size(); i++){
            pos[nums[i]] = i;
        }
        for(auto op : operations){
            nums[pos[op[0]]] = op[1];
            pos[op[1]] = pos[op[0]];
        }
        return nums;
    }
};