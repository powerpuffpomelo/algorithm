// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
    map<int, int> cnt;
    typedef long long LL;
    typedef pair<LL, int> pii;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), cmp);
        for(int i = 0; i < n; i++) q.push({0, i});
        for(auto m : meetings){
            pii t;
            vector<pii> temp;
            auto choose = q.top();
            while(q.size() && q.top().first <= m[0]){
                t = q.top();
                q.pop();
                temp.push_back(t);
                if(t.second < choose.second) choose = t;
            }
            for(auto t : temp){
                if(t.second != choose.second) q.push(t);
            }
            if(choose.first > m[0]) q.pop();
            q.push({m[1] + max(0LL, choose.first - m[0]), choose.second});
            cnt[choose.second]++;
        }
        int maxcnt = 0, ans = n - 1;
        for(int i = 0; i < n; i++){
            if(cnt[i] > maxcnt){
                maxcnt = cnt[i];
                ans = i;
            }
        }
        return ans;
    }
    
};