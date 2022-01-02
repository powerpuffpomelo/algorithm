// ###################################################### 版本1 ###################################################### //
// 我的初版，单调队列
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int q[n], front = -1, rear = -1;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            while(rear > front && nums[q[rear]] <= nums[i]) rear--;
            q[++rear] = i;
            while(q[front + 1] < i - k + 1) front++;
            if(i >= k - 1) ans.push_back(nums[q[front + 1]]);
        }
        return ans;
    }
};

// ###################################################### 版本2 ###################################################### //
// 优先队列
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> q;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            while(q.size() && q.top().second < i - k + 1) q.pop();
            q.push({nums[i], i});
            if(i >= k - 1) ans.push_back(q.top().first);
        }
        return ans;
    }
};