// ###################################################### 版本1 ###################################################### //
// 贪心
class Solution {
public:
    static const int N = 1e5 + 10;
    int maxEvents(vector<vector<int>>& events) {
        vector<vector<int>> begin(N);
        for(int i = 0; i < events.size(); i++){
            begin[events[i][0]].push_back(i);
        }
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for(int t = 1; t < N; t++){
            for(auto i : begin[t]) q.push(events[i][1]);
            while(q.size() && q.top() < t) q.pop();
            if(q.size()){
                q.pop();
                ans++;
            }
        }
        return ans;
    }
};