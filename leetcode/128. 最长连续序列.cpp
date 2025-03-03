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

// ###################################################### 版本4 ###################################################### //
// 记录所有存在的元素，然后遍历数组，对于每个元素都看看有多少跟它能连上的数，同时用vis把已访问过的数划掉
class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            int n = nums.size();
            set<int> se;
            for(auto x : nums) se.insert(x);
            set<int> vis;
            int ans = 0;
            for(int i = 0; i < n; i++){
                if(vis.count(nums[i])) continue;
                vis.insert(nums[i]);
                int ret = 1, x = nums[i], y = nums[i];
                while(se.count(x - 1)){  // 看看左边能连上多少
                    vis.insert(x - 1);
                    x--;
                    ret++;
                }
                while(se.count(y + 1)){  // 看看右边能连上多少
                    vis.insert(y + 1);
                    y++;
                    ret++;
                }
                ans = max(ans, ret);
            }
            return ans;
        }
    };