// ###################################################### 版本2 ###################################################### //
// dp，维护两个数组，左最大，右最大，这样每个点分别算
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmax(n), rmax(n);
        int mm = 0;
        for(int i = 0; i < n; i++){
            lmax[i] = mm;
            mm = max(mm, height[i]);
        }
        mm = 0;
        for(int i = n - 1; i >= 0; i--){
            rmax[i] = mm;
            mm = max(mm, height[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += max(0, min(lmax[i], rmax[i]) - height[i]);
        }
        return ans;
    }
};

// ###################################################### 版本3 ###################################################### //
// 单调栈
// 优雅，喜欢！它不是一个点一个点算，而是一层一层算
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> stk;
        int ans = 0;
        for(int i = 0; i < n; i++){
            while(stk.size() && height[i] > height[stk.top()]){
                int top = stk.top();
                stk.pop();
                if(stk.empty()) break;
                int left = stk.top();
                int ww = i - left - 1;
                int hh = min(height[left], height[i]) - height[top];
                ans += ww * hh;
            }
            stk.push(i);
        }
        return ans;
    }
};

// ###################################################### 版本4 ###################################################### //
// 双指针
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        int left = 0, right = n - 1;
        int left_max = height[left], right_max = height[right];
        while(left < right){
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);
            if(height[left] <= height[right]){  // height[left] 和 height[right] 中必有一个最大的，最大的不动；小的算雨水、移动指针，直到找到更大的为止
                ans += left_max - height[left];
                left++;
            }else{
                ans += right_max - height[right];
                right--;
            }
        }
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版
// 找到最大值，分成两段分别遍历
class Solution {
public:
    int trap(vector<int>& height) {
        int max_id = -1, max_height = 0;
        int n = height.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(height[i] > max_height){
                max_height = height[i];
                max_id = i;
            }
        }
        
        int temp_height = 0;
        for(int i = 0; i < max_id; i++){
            if(height[i] > temp_height){
                temp_height = height[i];
            }else{
                ans += (temp_height - height[i]);
            }
        }
        
        temp_height = 0;
        for(int i = n - 1; i > max_id; i--){
            if(height[i] > temp_height){
                temp_height = height[i];
            }else{
                ans += (temp_height - height[i]);
            }
        }
        return ans;
    }
};