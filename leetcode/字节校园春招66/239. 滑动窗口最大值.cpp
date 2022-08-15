// ###################################################### 版本3 ###################################################### //
// deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;
        for(int i = 0; i < nums.size(); i++){
            while(q.size() && q.front() < i - k + 1) q.pop_front();
            while(q.size() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
            if(i >= k - 1) ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版，单调队列，时间复杂度O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int q[n], front = 0, rear = -1;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            while(rear >= front && nums[q[rear]] <= nums[i]) rear--;
            q[++rear] = i;
            while(q[front] < i - k + 1) front++;
            if(i >= k - 1) ans.push_back(nums[q[front]]);
        }
        return ans;
    }
};

// ###################################################### 版本2 ###################################################### //
// 优先队列，时间复杂度O(nlogn)
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