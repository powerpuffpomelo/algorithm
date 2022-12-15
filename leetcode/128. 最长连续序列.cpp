// ###################################################### 版本3 ###################################################### //
// 哈希+记忆化搜索：先记录所有存在的元素，然后计算以每个存在元素为右端点的连续序列长度
class Solution {
public:
    unordered_map<int, int> cnt;
    int cal(int x){
        if(cnt[x] != 1 || !cnt[x - 1]) return cnt[x];
        return cnt[x] = cal(x - 1) + 1;
    }
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        for(auto x : nums) cnt[x] = 1;
        for(auto x : nums){
            cnt[x] = cal(x);
            ans = max(ans, cnt[x]);
        }
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 先插入所有存在的元素，然后遍历，只遍历开头所以不会重复
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        for(auto nn : nums) us.insert(nn);
        int ans = 0;
        for(auto nn : us){
            if(!us.count(nn - 1)){     // 或者 if(us.find(nn - 1) == us.end())
                int now_num = nn, now_len = 1;
                while(us.count(now_num + 1)){
                    now_num ++;
                    now_len ++;
                }
                ans = max(ans, now_len);
            }
        }
        return ans;
    }
};

// ###################################################### 版本2 ###################################################### //
// map记录以一个点为端点的最大长度
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> um;
        int lenl, lenr, len, ans = 0;
        for(auto nn : nums){
            if(!um[nn]){
                lenl = um[nn - 1], lenr = um[nn + 1];
                len = lenl + lenr + 1;
                um[nn] = len;
                um[nn - lenl] = len;
                um[nn + lenr] = len;
                ans = max(ans, len);
            }
        }
        return ans;
    }
};