class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        queue<int> q;
        vector<bool> inq(nums.size(), false);
        q.push(0);
        inq[0] = true;
        while(q.size()){
            auto t = q.front();
            q.pop();
            for(int i = 1; i <= nums[t]; i++){
                if(t + i == nums.size() - 1) return true;
                if(t + i < nums.size() && !inq[t + i]){
                    q.push(t + i);
                    inq[t + i] = true;
                }
            }
        }
        return false;
    }
};