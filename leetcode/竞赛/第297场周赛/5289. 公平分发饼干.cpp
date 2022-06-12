// ###################################################### 版本2 ###################################################### //
// 类似
class Solution {
public:
    vector<int> q;
    int k;
    int ans = 1e9;
    int sum[10] = {0};

    void dfs(int u){
        if(u == q.size()){
            int mx = 0;
            for(int i = 0; i < k; i++) mx = max(mx, sum[i]);
            ans = min(ans, mx);
            return;
        }
        for(int i = 0; i < k; i++){
            sum[i] += q[u];
            if(sum[i] < ans) dfs(u + 1);
            sum[i] -= q[u];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        q = cookies;
        this->k = k;
        dfs(0);
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int n;
    int ans = 1e9;
    void dfs(int u, vector<int>& cookies, int k, vector<int>& have){
        if(u == n){
            int mm = 0;
            for(auto x : have) mm = max(mm, x);
            ans = min(ans, mm);
            return;
        }
        for(int i = 0; i < k; i++){
            if(have[i] + cookies[u] >= ans) continue;
            have[i] += cookies[u];
            dfs(u + 1, cookies, k, have);
            have[i] -= cookies[u];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        vector<int> have(k, 0);
        dfs(0, cookies, k, have);
        return ans;
    }
};