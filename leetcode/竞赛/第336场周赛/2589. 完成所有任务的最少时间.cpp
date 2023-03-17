// ###################################################### 版本2 ###################################################### //
// 将所有任务按照结束时间从小到大排序
// 按顺序遍历所有任务，对于当前任务，判断是否已经有了足够的运行时间，如果没够，则从后往前补齐运行时间
class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        int n = tasks.size();
        const int M = 2010;
        vector<bool> vis(M, false);
        int ans = 0;
        sort(tasks.begin(), tasks.end(),
            [](const vector<int>& a, const vector<int>& b){
                return a[1] < b[1];
            }
        );
        for(int i = 0; i < n; i++){
            vector<int> t = tasks[i];
            for(int j = t[0]; j <= t[1] && t[2] > 0; j++){
                if(vis[j]){
                    t[2]--;
                }
            }
            if(!t[2]) continue;
            for(int j = t[1]; t[2] > 0; j--){
                if(vis[j]) continue;
                vis[j] = true;
                ans++;
                t[2]--;
            }
        }
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[1] != b[1]) return a[1] < b[1];
        return a[0] < b[0];
    }
    int findMinimumTime(vector<vector<int>>& tasks) {
        set<int> se;
        int n = tasks.size();
        sort(tasks.begin(), tasks.end(), cmp);
        for(int i = 0; i < n; i++){
            int l = tasks[i][0], r = tasks[i][1], d = tasks[i][2];
            int s = 0;
            for(int j = l; j <= r; j++){
                if(se.count(j)) s++;
            }
            int rem = max(0, d - s);  // 还需要多少
            int j = r;
            while(rem){
                if(se.count(j)){
                    j--;
                    continue;
                }
                se.insert(j);
                rem--;
                j--;
            }
        }
        return se.size();
    }
};