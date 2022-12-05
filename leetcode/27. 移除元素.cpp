// ###################################################### 版本2 ###################################################### //
// 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val) nums[k++] = nums[i];
        }
        return k;
    }
};

// ###################################################### 版本1 ###################################################### //
// 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = 0;
        while(i < nums.size()){
            if(nums[i] == val) i++;
            else nums[j++] = nums[i++];
        }
        return j;
    }
};