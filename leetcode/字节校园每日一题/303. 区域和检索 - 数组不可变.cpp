// ###################################################### 版本1 ###################################################### //
// 我的初版
class NumArray {
public:
    vector<int> s;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        s.resize(n + 1);
        for(int i = 0; i < n; i++){
            s[i + 1] = s[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return s[right + 1] - s[left];
    }
};