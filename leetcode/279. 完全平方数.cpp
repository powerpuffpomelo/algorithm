// ###################################################### 版本1 ###################################################### //
// bfs
class Solution {
public:
    int numSquares(int n) {
        vector<int> num;
        queue<int> q;
        unordered_map<int, int> cnt;
        for(int i = 1; i * i <= n; i++){
            num.push_back(i * i);
            if(i * i == n) return 1;
            q.push(i * i);
            cnt[i * i] = 1;
        }
        while(q.size()){
            auto t = q.front();
            q.pop();
            for(auto x : num){
                if(t + x == n) return cnt[t] + 1;
                if(!cnt.count(t + x)){
                    cnt[t + x] = cnt[t] + 1;
                    q.push(t + x);
                }
            }
        }
        return -1;
    }
};