// ###################################################### 版本2 ###################################################### //
// dp，时间复杂度O(n sqrt n)
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j * j <= i; j++){
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

// ###################################################### 版本4 ###################################################### //
// dp，完全背包
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n);
        dp[0] = 0;
        for(int i = 1; i <= n / i; i++){
            for(int j = i * i; j <= n; j++){
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        return dp[n];
    }
};

// ###################################################### 版本3 ###################################################### //
// 数学，时间复杂度O(sqrt n)
class Solution {
public:
    bool check(int x){
        int r = sqrt(x);
        return r * r == x;
    }
    int numSquares(int n) {
        if(check(n)) return 1;
        for(int i = 1; i <= n / i; i++){
            if(check(n - i * i)) return 2;
        }
        while(n % 4 == 0) n /= 4;
        if(n % 8 != 7) return 3;
        return 4;
    }
};

// ###################################################### 版本1 ###################################################### //
// 最短路spfa
class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        vector<int> dist(n + 1, n);
        q.push(0);
        dist[0] = 0;
        while(q.size()){
            auto t = q.front();
            q.pop();
            if(t == n) break;
            for(int i = 1; t + i * i <= n; i++){
                if(dist[t + i * i] > dist[t] + 1){
                    dist[t + i * i] = dist[t] + 1;
                    q.push(t + i * i);
                } 
            }
        }
        return dist[n];
    }
};

// ###################################################### 版本5 ###################################################### //
// dfs+剪枝
class Solution {
public:
    int ans;
    void dfs(int u, int n){
        if(u >= ans) return;   // 不剪枝会超时
        if(!n){
            ans = min(ans, u);
            return;
        }
        for(int i = sqrt(n); i >= 1; i--){   // 从小到大枚举也会超时
            dfs(u + 1, n - i * i);
        }
    }
    int numSquares(int n) {
        ans = n;
        dfs(0, n);
        return ans;
    }
};