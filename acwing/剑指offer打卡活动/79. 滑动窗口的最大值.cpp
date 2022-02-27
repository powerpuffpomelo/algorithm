// ###################################################### 版本1 ###################################################### //
// 我的初版，数组模拟队列
class Solution {
public:
    vector<int> maxInWindows(vector<int>& nums, int k) {
        int q[1010], hh = 0, tt = -1;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            while(hh <= tt && q[hh] <= i - k) hh++;
            while(hh <= tt && nums[i] >= nums[q[tt]]) tt--;
            q[++tt] = i;
            if(i >= k - 1) ans.push_back(nums[q[hh]]);
        }
        return ans;
    }
};

// ###################################################### 版本2 ###################################################### //
// deque
class Solution {
public:
    vector<int> maxInWindows(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;
        for(int i = 0; i < nums.size(); i++){
            while(q.size() && q.front() <= i - k) q.pop_front();
            while(q.size() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
            if(i >= k - 1) ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};