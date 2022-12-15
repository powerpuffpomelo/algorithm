// ###################################################### 版本1 ###################################################### //
// 贪心
// 本题单调队列也可做，参考acwing1088
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i = 0, j; i < n; ){  // 枚举起点，如果从i开始不能走到k，那么从i和k中间的任意位置开始都不可能是答案
            int left = 0;
            for(j = 0; j < n; j++){
                int k = (i + j) % n;
                left += gas[k] - cost[k];
                if(left < 0) break;
            }
            if(j == n) return i;
            i = i + j + 1;
        }
        return -1;
    }
};