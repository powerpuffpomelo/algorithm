// ###################################################### 版本1 ###################################################### //
// stl
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> lose_cnt;
        for(auto p : matches){
            lose_cnt[p[0]];   // 这么写一下就可以了，不用++--
            lose_cnt[p[1]]++;
        }
        vector<vector<int>> ans(2);
        for(auto [k, v] : lose_cnt){
            if(v == 0) ans[0].push_back(k);
            else if(v == 1) ans[1].push_back(k);
        }
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    static const int N = 1e5 + 10;
    int cnt[N], vis[N];
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        fill(cnt, cnt + N, 0);
        fill(vis, vis + N, 0);
        for(auto item : matches){
            cnt[item[1]]++;
            vis[item[0]] = vis[item[1]] = 1;
        }
        vector<vector<int>> ans(2);
        for(int i = 1; i < N; i++){
            if(vis[i] && cnt[i] == 0) ans[0].push_back(i);
            else if(vis[i] && cnt[i] == 1) ans[1].push_back(i);
        }
        return ans;
    }
};