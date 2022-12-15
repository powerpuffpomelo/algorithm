// ###################################################### 版本1 ###################################################### //
// 构造
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> ma;
        int maxc = 0, cnt = 0;   // maxc：出现次数最多的元素出现了几次；cnt：有几个元素出现次数最多
        for(auto c : tasks) ma[c]++;
        for(auto [k, v] : ma) maxc = max(maxc, v);
        for(auto [k, v] : ma){
            if(v == maxc) cnt++;
        }
        return max((int)tasks.size(), (maxc - 1) * (n + 1) + cnt);  // 构造：只考虑n和出现次数最多的元素；如果其余元素填不下空余的话，就说明没有空余，就是元素总数
    }
};