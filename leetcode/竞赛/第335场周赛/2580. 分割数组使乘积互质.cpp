// ###################################################### 版本1 ###################################################### //
// 同一个质因子，记录其最早出现的位置、最晚出现的位置，这中间是不能分割的，所以我们得到了一系列区间，
// 把区间合并起来，我们要找到合并后的第一个区间的末尾端点
class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> left;  // left[p] = i; 质因子p最早出现的位置为i
        vector<int> right(n);  // right[i] = j; 在i位置出现的某质因子，最远在j位置也出现
        for(int i = 0; i < n; i++){
            int x = nums[i];
            for(int p = 2; p <= x / p; p++){
                if(x % p == 0){
                    if(!left.count(p)) left[p] = i;
                    right[left[p]] = i;
                    while(x % p == 0) x /= p;
                }
            }
            if(x != 1){
                if(!left.count(x)) left[x] = i;
                right[left[x]] = i;
            }
        }
        // 寻找第一个合并区间的末尾端点
        int maxr = 0;
        for(int i = 0; i < n; i++){
            if(i > maxr) return maxr;
            maxr = max(maxr, right[i]);
        }
        return -1;
    }
};