// ###################################################### 版本1 ###################################################### //
// 转化为 快慢指针寻找环的入口，nums[i] = j 则从i到j连一条边，由于每个点均有出边所以一定存在环
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int a = 0, b = 0;
        while(true){
            a = nums[a];
            b = nums[nums[b]];
            if(a == b){
                a = 0;
                while(a != b){
                    a = nums[a];
                    b = nums[b];
                }
                return a;
            }
        }
        return -1;
    }
};