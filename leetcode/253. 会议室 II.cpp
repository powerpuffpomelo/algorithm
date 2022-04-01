// ###################################################### 版本2 ###################################################### //
// 时间打散，记录多少个会议正在进行
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>> times;
        for(auto inter : intervals){
            times.push_back({inter[0], 1});  // 注意，时间相同时，开始要排在后面，所以开始是1结束是0
            times.push_back({inter[1], 0});
        }
        sort(times.begin(), times.end());
        int ans = 0, s = 0;
        for(auto t : times){
            if(t.second) s++, ans = max(ans, s);  // 遇到开始会议就s++
            else s--;
        }
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 优先队列
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        return a[0] <= b[0];
    }
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> q;
        sort(intervals.begin(), intervals.end(), cmp);
        for(auto inter : intervals){
            if(q.size() && inter[0] >= q.top()) q.pop();
            q.push(inter[1]);
        }
        return q.size();
    }
};