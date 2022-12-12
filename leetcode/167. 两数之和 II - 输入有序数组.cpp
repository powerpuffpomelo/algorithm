// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        vector<int> ans;
        while(i < j){
            if(numbers[i] + numbers[j] < target) i++;
            else if(numbers[i] + numbers[j] > target) j--;
            else{
                ans = {i + 1, j + 1};
                break;
            }
        }
        return ans;
    }
};