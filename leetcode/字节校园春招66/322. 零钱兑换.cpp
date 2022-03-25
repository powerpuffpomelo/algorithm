// ###################################################### 版本3 ###################################################### //
// dp
class Solution {
public:
    const int INF = 1e9;
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;
        for(int i = 0; i < coins.size(); i++){
            for(int j = coins[i]; j <= amount; j++){
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        if(dp[amount] == INF) return -1;
        return dp[amount];
    }
};

// ###################################################### 版本2 ###################################################### //
// dp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int c : coins){
                if(i - c >= 0 && dp[i - c] != -1){
                    dp[i] = dp[i] == -1 ? dp[i - c] + 1 : min(dp[i], dp[i - c] + 1);
                }
            }
        }
        return dp[amount];
    }
};

// ###################################################### 版本1 ###################################################### //
// bfs
class Solution {
public:
    typedef long long lld;
    static bool cmp(int a, int b){
        return a > b;
    }
    int bfs(vector<int>& coins, int amount){
        //cout << amount << endl;
        queue<lld> q;
        unordered_map<lld, int> ma;
        q.push(0);
        ma[0] = 0;
        while(q.size()){
            auto t = q.front();
            if(t == amount) return ma[t];
            q.pop();
            for(int c : coins){
                if(t + c <= amount && !ma.count(t + c)){
                    q.push(t + c);
                    ma[t + c] = ma[t] + 1;
                }
            }
        }
        return -1;
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), cmp);
        return bfs(coins, amount);
    }
};