// ###################################################### 版本2 ###################################################### //
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
// 数组实现单调队列
class Solution {
public:
    vector<int> maxInWindows(vector<int>& nums, int k) {
        int n = nums.size();
        int q[n], front = 0, rear = -1;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            while(rear >= front && nums[i] >= nums[q[rear]]) rear--;
            q[++rear] = i;
            while(q[front] < i - k + 1) front++;
            if(i >= k - 1) ans.push_back(nums[q[front]]);
        }
        return ans;
    }
};